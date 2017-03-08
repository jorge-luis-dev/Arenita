#ifndef LOCALIDADDIALOGO_H
#define LOCALIDADDIALOGO_H

#include <QDialog>
#include "base/mensaje.h"
#include "base/conectar.h"

namespace Ui {
class LocalidadDialogo;
}

class LocalidadDialogo : public QDialog
{
    Q_OBJECT

public:
    explicit LocalidadDialogo(QWidget *parent = 0);
    Mensaje mensaje;
    ~LocalidadDialogo();

private:
    Ui::LocalidadDialogo *ui;

signals:
    void messageSent(const Mensaje &mensaje);

public slots:
    void setMensaje(const Mensaje &mensaje);

private slots:
    void sendMessage();
    void on_pushAceptar_clicked();
};

#endif // LOCALIDADDIALOGO_H
