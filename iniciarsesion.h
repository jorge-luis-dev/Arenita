#ifndef INICIARSESION_H
#define INICIARSESION_H

#include <QDialog>
#include "principal.h"
#include "base/conectar.h"
#include "base/mensaje.h"

namespace Ui {
class IniciarSesion;
}

class IniciarSesion : public QDialog
{
    Q_OBJECT

public:    
    explicit IniciarSesion(QWidget *parent = 0);
    Mensaje mensaje;
    Principal *w=new Principal();

    ~IniciarSesion();

private:
    Ui::IniciarSesion *ui;

signals:
    void messageSent(const Mensaje &mensaje);

private slots:
    void sendMessage();
    void reject();
    void OnQuit();
    void OnLogin();
    QString getServidorPredeterminado();
    QStringList getServidores();
    bool conectarServidor();
    void on_pushConexiones_clicked();
};

#endif // INICIARSESION_H
