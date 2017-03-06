#include "principal.h"
#include "ui_principal.h"
#include "acerca.h"
#include "administrador.h"


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

void Principal::setClave(QString clave)
{
    ui->txtClave->setText(clave);
}

void Principal::setTipo(QString tipo)
{
    ui->lblTipo->setText(tipo);
}

void Principal::setServidor(QString servidor)
{
    ui->lblServidor->setText(servidor);
}

