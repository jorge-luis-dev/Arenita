#include "administrador.h"
#include "ui_administrador.h"
#include "admempresa.h"

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

void Administrador::on_actionEmpresa_triggered()
{
    AdmEmpresa* empresa=new AdmEmpresa();
    empresa->showMaximized();
}
