#include "iniciarsesion.h"
#include "ui_iniciarsesion.h"
#include "principal.h"
#include <QMessageBox>
#include "administrador/parametro/servidorconfigura.h"
#include <QCompleter>
#include <QDebug>

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

    settings.beginGroup("Servidores");
    const QStringList listaServidores = settings.childKeys();

    QStringList nombre;
    QStringList valor;

    foreach (const QString &servidor, listaServidores)
     {
            nombre << servidor;
            valor << settings.value(servidor).toString();
            qDebug() << "Servidor:" << servidor << "IP:" << settings.value(servidor).toString();
     }
     settings.endGroup();
     return listaServidores;
}

IniciarSesion::~IniciarSesion()
{
    delete ui;
}


