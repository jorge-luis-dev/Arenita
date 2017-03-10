#ifndef LOCALIDADFORM_H
#define LOCALIDADFORM_H

#include <QMainWindow>
#include "base/mensaje.h"
#include "base/conectar.h"

namespace Ui {
class LocalidadForm;
}

class LocalidadForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit LocalidadForm(QWidget *parent = 0);
    Mensaje mensaje;
    ~LocalidadForm();

private:
    Ui::LocalidadForm *ui;

signals:
    void messageSent(const Mensaje &mensaje);

public slots:
    void setMensaje(const Mensaje &mensaje);

private slots:
    void sendMessage();
    void on_pushAceptar_clicked();
};

#endif // LOCALIDADFORM_H
