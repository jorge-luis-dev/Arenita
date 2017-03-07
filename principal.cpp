#include "principal.h"
#include "ui_principal.h"
#include <QDebug>

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    ui->toolBar->addWidget(ui->lblNombreUsuario);
    ui->toolBar->addWidget(ui->lblUsuario);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::setMensaje(const Mensaje &mensaje)
{
    this->mensaje = mensaje;
    qDebug() << "Mensaje:" << this->mensaje.getUsuario() << this->mensaje.getClave()
             << this->mensaje.getTipo() << this->mensaje.getServidor();
    ui->lblUsuario->setText(" "+mensaje.getUsuario()+"  |  "+mensaje.getTipo()
                            +"  |  "+mensaje.getServidor());
}

void Principal::on_actionAcerca_de_triggered()
{
    Acerca *acerca=new Acerca();
    acerca->show();
}

void Principal::on_actionAdministrador_triggered()
{
    Administrador* administrador=new Administrador();
    administrador->showMaximized();
}

void Principal::setUsuario(QString usuario)
{
    ui->lblUsuario->setText(usuario);
}

