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
        Login("jorge","a");
        //this->destroy();
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

    foreach (const QString &group, grupos) {
        QString groupString = QString("%1").arg(group);
        settings.beginGroup(group);
        qDebug() << "Grupo:" << groupString;
        foreach (const QString &key, settings.childKeys()) {
            QString nombre;
            QString valor;
            nombre.append(QString("%1").arg(key));
            valor.append(QString("%1").arg(settings.value(key).toString()));
            qDebug() << "Nombre:" << nombre;
            qDebug() << "Valor:" << valor;
        }

        settings.endGroup();
    }

     return grupos;
}

IniciarSesion::~IniciarSesion()
{
    delete ui;
}


bool IniciarSesion::Login(QString u, QString p)
{

    const char* driverName = "QPSQL";
    QdbHelper* qdbHelper = new QdbHelper(driverName);
    QSqlDatabase* db = qdbHelper->connect("localhost", "5432","postgres", "postgres", "horiz0ns");

    bool exists = false;

    QSqlQuery checkQuery(*db);
    checkQuery.prepare("select tipo,estado from seg_usuarios where usuario=(:un)");
    checkQuery.bindValue(":un", u);

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
