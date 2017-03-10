#ifndef LOCALIDAD_H
#define LOCALIDAD_H

#include <QMainWindow>
#include "base/mensaje.h"
#include "localidadform.h"

namespace Ui {
class Localidad;
}

class Localidad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Localidad(QWidget *parent = 0);
    Mensaje mensaje;
    LocalidadForm *ld = new LocalidadForm();
    ~Localidad();

private:
    Ui::Localidad *ui;

signals:
    void messageSent(const Mensaje &mensaje);

public slots:
    void setMensaje(const Mensaje &mensaje);

private slots:
    void sendMessage();
    void on_pushNuevo_clicked();
    void on_pushModificar_clicked();
};

#endif // LOCALIDAD_H
