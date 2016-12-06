#include "empresa.h"
#include "ui_empresa.h"

Empresa::Empresa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Empresa)
{
    ui->setupUi(this);
}

Empresa::~Empresa()
{
    delete ui;
}
