#include "iniciarsesion.h"
#include "ui_iniciarsesion.h"
#include "principal.h"
#include <QMessageBox>
#include "administrador/parametro/servidorconfigura.h"
#include <QCompleter>
#include <QDebug>
#include "qdbhelper.h"

IniciarSesion::IniciarSesion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IniciarSesion)
{
    ui->setupUi(this);


    QCompleter *completer = new QCompleter(getServidores(), this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->txtServidor->setCompleter(completer);

    ui->txtServidor->setText(getServidorPredeterminado());


    connect(ui->pushCancelar,SIGNAL(pressed()),this,SLOT(OnQuit()));
    connect(ui->pushAceptar,SIGNAL(pressed()),this,SLOT(OnLogin()));
}

void IniciarSesion::reject(){
    OnQuit();
}

void IniciarSesion::OnQuit(){
    this->close();
    parentWidget()->close();
}
void IniciarSesion::OnLogin(){
    QString usuario=ui->txtUsuario->text();
    QString clave=ui->txtClave->text();

    if(usuario.isEmpty() || clave.isEmpty()){

        QMessageBox::information(this,tr("Advertencia"),"Usuario o clave, no validos");
    }
    else{
        Conectar();
        this->destroy();
    }

}
//Obtiene el servidor predeterminado de el archivo de configuración
QString IniciarSesion::getServidorPredeterminado(){
    QSettings settings(ServidorConfigura::homeConfig+ QDir::separator() +"Arenita.ini", QSettings::NativeFormat);
    settings.beginGroup("Prioridad");
    QString servidor=settings.value("Servidor").toString();
    settings.endGroup();
    qDebug() << "Servidor predeterminado:" << servidor;
    return servidor;
}
//Obtiene la lista de servidores del archivo de configuración
QStringList IniciarSesion::getServidores(){
    QSettings settings(ServidorConfigura::homeConfig+ QDir::separator() +"Arenita.ini", QSettings::NativeFormat);

    QStringList grupos = settings.childGroups();

    grupos.removeOne("Prioridad");

    foreach (const QString &group, grupos) {
        QString groupString = QString("%1").arg(group);
        settings.beginGroup(group);
        qDebug() << "Grupo:" << groupString;
        foreach (const QString &key, settings.childKeys()) {
            QString nombre;
            QString valor;
            nombre.append(QString("%1").arg(key));
            valor.append(QString("%1").arg(settings.value(key).toString()));
            qDebug() << "  Nombre:" << nombre << " Valor:" << valor;
        }
        qDebug() << "\n";
        settings.endGroup();
    }

    return grupos;
}

IniciarSesion::DatosConexion IniciarSesion::getDatosConexion()
{
    DatosConexion datosConexion;
    QSettings settings(ServidorConfigura::homeConfig+ QDir::separator() +"Arenita.ini", QSettings::NativeFormat);

    settings.beginGroup(ui->txtServidor->text());

    const QStringList servidor = settings.childKeys();
    /*
     * Recupera los datos de conexión en la estructura
    */
    foreach (const QString &nombre, servidor)
    {
        if(nombre=="ip"){
            datosConexion.ip=settings.value(nombre).toString();
        }
        else if (nombre=="puerto") {
            datosConexion.puerto=settings.value(nombre).toString();
        }
        else if (nombre=="baseDatos") {
            datosConexion.baseDatos=settings.value(nombre).toString();
        }
    }
    settings.endGroup();
    /*
     * Añade el usuario y la clave en la estructura
    */
    datosConexion.usuario=ui->txtUsuario->text();
    datosConexion.clave=ui->txtClave->text();

    qDebug() << "Datos de Conexión";
    qDebug() << "ip:" << datosConexion.ip;
    qDebug() << "puerto:" << datosConexion.puerto;
    qDebug() << "base de datos:" << datosConexion.baseDatos;
    //qDebug() << "usuario:" << datosConexion.usuario;
    //qDebug() << "clave:" << datosConexion.clave;

    return datosConexion;
}

IniciarSesion::~IniciarSesion()
{
    delete ui;
}


bool IniciarSesion::Conectar()
{

    const char* driverName = "QPSQL";
    QdbHelper* qdbHelper = new QdbHelper(driverName);


    DatosConexion dc=getDatosConexion();

    QSqlDatabase* db = qdbHelper->connect(dc.ip, dc.puerto, dc.baseDatos, dc.usuario, dc.clave);

    bool exists = false;

    QSqlQuery checkQuery(*db);
    checkQuery.prepare("select tipo,estado from seg_usuarios where usuario=(:u)");
    checkQuery.bindValue(":u", dc.usuario);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
            qDebug() << "Tipo" << checkQuery.value("tipo").toString();
            qDebug() << "Estado" << checkQuery.value("estado").toString();
        }
    }
    qDebug() << "Existe" << exists;
    return exists;
}

void IniciarSesion::on_pushConexiones_clicked()
{
    ServidorConfigura* configura=new ServidorConfigura();
    configura->showMaximized();
}
