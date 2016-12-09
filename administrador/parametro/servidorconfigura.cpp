#include "servidorconfigura.h"
#include "ui_servidorconfigura.h"
#include <QDir>
#include <QMessageBox>
#include <QSettings>

const QString ServidorConfigura::homeConfig = QDir::homePath() + QDir::separator() + "ArenitaConfig";

ServidorConfigura::ServidorConfigura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServidorConfigura)
{
    ui->setupUi(this);

    if(!crearCarpetaArenitaConfig()){
        QMessageBox::critical(this,tr("Error"),"No se pudo crear la carpeta ArenitaConfig");
    }

    ui->txtHome->setText(ServidorConfigura::homeConfig);
}

ServidorConfigura::~ServidorConfigura()
{
    delete ui;
}

void ServidorConfigura::on_pushCrearArchivoConfig_clicked()
{
    crearArchivoArenita_ini();
}

bool ServidorConfigura::crearCarpetaArenitaConfig(){
    if(!QDir(ServidorConfigura::homeConfig).exists()){
        QDir dir = QDir::root();
        if(!dir.mkdir(ServidorConfigura::homeConfig)){
            return false;
        }
    }
    return true;
}

bool ServidorConfigura::crearArchivoArenita_ini(){
    QSettings settings(homeConfig + QDir::separator() +"Arenita.ini", QSettings::NativeFormat);

    settings.beginGroup("Servidores");
    settings.setValue("Servidor/Arenita", "127.0.0.1");
    settings.setValue("Servidor/Jorge","192.168.1.18");
    settings.endGroup();

    settings.beginGroup("Prioridad");
    settings.setValue("Servidor", "Arenita");
    settings.endGroup();

    return true;
}

