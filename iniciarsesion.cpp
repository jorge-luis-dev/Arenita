#include "iniciarsesion.h"
#include "ui_iniciarsesion.h"

IniciarSesion::IniciarSesion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IniciarSesion)
{
    ui->setupUi(this);
}

IniciarSesion::~IniciarSesion()
{
    delete ui;
}
