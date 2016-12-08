#include "administrador.h"
#include "ui_administrador.h"
#include "administrador/administrar/empresa.h"
#include "administrador/parametro/servidorconfigura.h"

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

void Administrador::on_actionServidor_triggered()
{
    ServidorConfigura* configura=new ServidorConfigura();
    configura->showMaximized();
}
