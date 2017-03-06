#ifndef INICIARSESION_H
#define INICIARSESION_H

#include <QDialog>
#include "principal.h"
#include "base/conectar.h"

namespace Ui {
class IniciarSesion;
}

class IniciarSesion : public QDialog
{
    Q_OBJECT

public:    
    explicit IniciarSesion(QWidget *parent = 0);

    Principal *w=new Principal();

    ~IniciarSesion();

private slots:    
    void reject();
    void OnQuit();
    void OnLogin();
    QString getServidorPredeterminado();
    QStringList getServidores();
    bool conectarServidor();
    void on_pushConexiones_clicked();

private:
    Ui::IniciarSesion *ui;
};

#endif // INICIARSESION_H
