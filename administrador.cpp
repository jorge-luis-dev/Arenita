#include "administrador.h"
#include "ui_administrador.h"
#include "administrador/administrar/empresa.h"

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
    Empresa* empresa=new Empresa();
    empresa->showMaximized();
}
