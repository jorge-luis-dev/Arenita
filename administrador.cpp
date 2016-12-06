#include "administrador.h"
#include "ui_administrador.h"

Administrador::Administrador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Administrador)
{
    ui->setupUi(this);
}

Administrador::~Administrador()
{
    delete ui;
}
