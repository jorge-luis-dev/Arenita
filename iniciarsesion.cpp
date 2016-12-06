#include "iniciarsesion.h"
#include "ui_iniciarsesion.h"
#include "principal.h"
#include <QMessageBox>

IniciarSesion::IniciarSesion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IniciarSesion)
{
    ui->setupUi(this);
    connect(ui->pushCancelar,SIGNAL(pressed()),this,SLOT(OnQuit()));
    connect(ui->pushAceptar,SIGNAL(pressed()),this,SLOT(OnLogin()));
}

void IniciarSesion::reject(){
    OnQuit();
}

void IniciarSesion::OnQuit(){
    this->close();
    parentWidget()->close();
}
void IniciarSesion::OnLogin(){
    QString usuario=ui->txtUsuario->text();
    QString clave=ui->txtClave->text();

    if(usuario.isEmpty() || clave.isEmpty()){

        QMessageBox::information(this,tr("Advertencia"),"Usuario o clave, no validos");
    }
    else{
        this->destroy();
    }

}

IniciarSesion::~IniciarSesion()
{
    delete ui;
}


