#include "administrador.h"
#include "ui_administrador.h"


Administrador::Administrador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Administrador)
{
    ui->setupUi(this);
    ui->statusbar->addWidget(ui->lblMensaje);
    connect(this,SIGNAL(messageSent(Mensaje)),empresa,SLOT(setMensaje(Mensaje)));
    connect(this,SIGNAL(messageSent(Mensaje)),localidad,SLOT(setMensaje(Mensaje)));
}

Administrador::~Administrador()
{
    delete ui;
}
void Administrador::on_actionEmpresa_triggered()
{    
    sendMessage();
    empresa->showMaximized();
}
void Administrador::on_actionServidor_triggered()
{
    ServidorConfigura* configura=new ServidorConfigura();
    configura->showMaximized();
}
void Administrador::on_actionLocalidad_triggered()
{
    sendMessage();
    localidad->showMaximized();
}
void Administrador::setMensaje(const Mensaje &mensaje)
{
    this->mensaje = mensaje;
    ui->lblMensaje->setText("Usuario: "+mensaje.getUsuario()+"  |  "+mensaje.getTipo()
                            +"  |  "+mensaje.getServidor());
}
void Administrador::sendMessage()
{
    emit messageSent(this->mensaje);
}

