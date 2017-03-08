#include "principal.h"
#include "ui_principal.h"
#include <QDebug>

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    ui->toolBar->addWidget(ui->lblNombreUsuario);
    ui->toolBar->addWidget(ui->lblUsuario);
    connect(this,SIGNAL(messageSent(Mensaje)),administrador,SLOT(setMensaje(Mensaje)));
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

void Principal::on_actionAdministrador_triggered()
{
    sendMessage();
    administrador->showMaximized();
}

void Principal::setUsuario(QString usuario)
{
    ui->lblUsuario->setText(usuario);
}

void Principal::establecerMenus()
{
    qDebug() << "Tipo usuario:" << mensaje.getTipo();
    if(mensaje.getTipo()=="Administrador"){
        ui->actionAdministrador->setVisible(true);
        ui->actionContabilidad->setVisible(true);
    }
    else{
        ui->actionContabilidad->setVisible(false);
        ui->actionAdministrador->setVisible(false);
    }
    /*
     * Añadir un menú por código
    QAction *jorge=new QAction("Jorge");
    ui->menuModulos->addAction(jorge);
    */
}
void Principal::sendMessage()
{
    emit messageSent(this->mensaje);
}
void Principal::setMensaje(const Mensaje &mensaje)
{
    this->mensaje = mensaje;
    qDebug() << "Mensaje:" << this->mensaje.getUsuario() /*<< this->mensaje.getClave()*/
             << this->mensaje.getTipo() << this->mensaje.getServidor();
    ui->lblUsuario->setText(" "+mensaje.getUsuario()+"  |  "+mensaje.getTipo()
                            +"  |  "+mensaje.getServidor());
    establecerMenus();
}
