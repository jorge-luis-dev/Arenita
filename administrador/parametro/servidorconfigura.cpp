#include "servidorconfigura.h"
#include "ui_servidorconfigura.h"
#include <QDir>
#include <QMessageBox>

ServidorConfigura::ServidorConfigura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServidorConfigura)
{
    ui->setupUi(this);
    if(!QDir(QDir::homePath()+QDir::separator()+"ArenitaConfig").exists()){
        QDir dir = QDir::root();
        if(!dir.mkdir(QDir::homePath()+QDir::separator()+"ArenitaConfig")){
            QMessageBox::information(this,tr("Advertencia"),"No se pudo crear la carpeta ArenitaConfig");
        }
    }

    ui->txtHome->setText(QDir::homePath() + QDir::separator()+"ArenitaConfig");
}

ServidorConfigura::~ServidorConfigura()
{
    delete ui;
}
