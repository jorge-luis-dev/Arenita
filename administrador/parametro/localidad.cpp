#include "localidad.h"
#include "ui_localidad.h"

Localidad::Localidad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Localidad)
{
    ui->setupUi(this);
    ui->statusbar->addWidget(ui->lblMensaje);
    connect(this,SIGNAL(messageSent(Mensaje)),ld,SLOT(setMensaje(Mensaje)));
}

Localidad::~Localidad()
{
    delete ui;
}
void Localidad::sendMessage()
{
    emit messageSent(this->mensaje);
}
void Localidad::setMensaje(const Mensaje &mensaje)
{
    this->mensaje = mensaje;
    ui->lblMensaje->setText("Usuario: "+mensaje.getUsuario()+"  |  "+mensaje.getTipo()
                            +"  |  "+mensaje.getServidor());
}

void Localidad::on_pushNuevo_clicked()
{    
    sendMessage();
    ld->showMaximized();
}

void Localidad::on_pushModificar_clicked()
{
    ui->lblMensaje->setText("Modificar");
}
