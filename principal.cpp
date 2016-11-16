#include "principal.h"
#include "ui_principal.h"
#include "acerca.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
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
