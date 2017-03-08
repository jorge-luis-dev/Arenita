#include "empresa.h"
#include "ui_empresa.h"


Empresa::Empresa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Empresa)
{
    ui->setupUi(this);
    ui->statusbar->addWidget(ui->lblMensaje);
}

Empresa::~Empresa()
{
    delete ui;
}
void Empresa::sendMessage()
{
    emit messageSent(this->mensaje);
}
void Empresa::setMensaje(const Mensaje &mensaje)
{
    this->mensaje = mensaje;
    ui->lblMensaje->setText("Usuario: "+mensaje.getUsuario()+"  |  "+mensaje.getTipo()
                            +"  |  "+mensaje.getServidor());
}
