#include "servidorconfigura.h"
#include "ui_servidorconfigura.h"
#include <QMessageBox>


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
    crearArchivoArenita_ini(ui->txtNombreServidor->text(),ui->txtDireccionIP->text(),ui->txtPuerto->text());
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

bool ServidorConfigura::crearArchivoArenita_ini(QString nombreServidor, QString ipServidor, QString puerto){
    QSettings settings(homeConfig + QDir::separator() +"Arenita.ini", QSettings::NativeFormat);

    settings.beginGroup(nombreServidor);
    settings.setValue("ip", ipServidor);
    settings.setValue("puerto", puerto);
    settings.endGroup();

    settings.beginGroup("Prioridad");
    settings.setValue("Servidor", "Arenita");
    settings.endGroup();

    return true;
}

