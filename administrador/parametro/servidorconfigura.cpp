#include "servidorconfigura.h"
#include "ui_servidorconfigura.h"

ServidorConfigura::ServidorConfigura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServidorConfigura)
{
    ui->setupUi(this);
}

ServidorConfigura::~ServidorConfigura()
{
    delete ui;
}
