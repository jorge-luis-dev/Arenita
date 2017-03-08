#include "iniciarsesion.h"
#include "ui_iniciarsesion.h"
#include <QMessageBox>
#include "administrador/parametro/servidorconfigura.h"
#include <QCompleter>
#include <QDebug>

IniciarSesion::IniciarSesion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IniciarSesion)
{
    ui->setupUi(this);

    ui->pushConexiones->hide();

    QCompleter *completer = new QCompleter(getServidores(), this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->txtServidor->setCompleter(completer);

    ui->txtServidor->setText(getServidorPredeterminado());


    /*
     * Señales para eventos de botones
     */
    connect(ui->pushCancelar,SIGNAL(pressed()),this,SLOT(OnQuit()));
    connect(ui->pushAceptar,SIGNAL(pressed()),this,SLOT(OnLogin()));    
    /*
     * Señales para paso de valores entre ventanas
     */
    connect(ui->txtUsuario,SIGNAL(textChanged(QString)),w,SLOT(setUsuario(QString)));
    connect(this,SIGNAL(messageSent(Mensaje)),w,SLOT(setMensaje(Mensaje)));
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
        if (conectarServidor()){
            sendMessage();
            w->showMaximized();
            this->hide();
            this->close();
            this->destroy();
        }
        else{
            QMessageBox::critical(this,tr("Error"),"No se pudo establecer la conexión");
        }
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

IniciarSesion::~IniciarSesion()
{
    delete ui;
}


bool IniciarSesion::conectarServidor()
{
    QString servidor = ui->txtServidor->text();
    Conectar *co = new Conectar(servidor);

    QSqlDatabase* db = co->conecta(ui->txtUsuario->text(),ui->txtClave->text());

    QString tipo;
    QString estado;
    bool existe = false;
    if(db){
        QSqlQuery checkQuery(*db);
        checkQuery.prepare("select tipo,estado from seg_usuarios where usuario=(:u)");
        checkQuery.bindValue(":u", ui->txtUsuario->text());

        if (checkQuery.exec())
        {
            if (checkQuery.next())
            {
                existe = true;
                tipo = checkQuery.value("tipo").toString();
                qDebug() << "Tipo" << tipo;
                estado = checkQuery.value("estado").toString();
                qDebug() << "Estado" << estado;
                if(estado=="Inactivo"){
                    QMessageBox::warning(this,tr("Advertencia"),"El usuario está inactivo");
                    existe = false;
                }
            }
            else{
                QMessageBox::warning(this,tr("Advertencia"),"El usuario no está registrado en la base de datos");
            }
        }
        qDebug() << "Existe" << existe;

    }
    if(existe){
        this->mensaje = Mensaje(ui->txtUsuario->text(),ui->txtClave->text(),tipo,
                                ui->txtServidor->text());
    }
    db->close();
    co->desconecta();
    return existe;
}

void IniciarSesion::on_pushConexiones_clicked()
{
    ServidorConfigura* configura=new ServidorConfigura();
    configura->showMaximized();
}
/*
 * Función que envía los parámetros
 */
void IniciarSesion::sendMessage()
{    
    emit messageSent(this->mensaje);
}
