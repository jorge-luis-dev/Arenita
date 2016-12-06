#include "admempresa.h"
#include "ui_admempresa.h"

AdmEmpresa::AdmEmpresa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdmEmpresa)
{
    ui->setupUi(this);
}

AdmEmpresa::~AdmEmpresa()
{
    delete ui;
}
