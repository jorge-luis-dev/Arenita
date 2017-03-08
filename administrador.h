#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <QMainWindow>
#include "base/mensaje.h"
#include "administrador/administrar/empresa.h"
#include "administrador/parametro/servidorconfigura.h"
#include "administrador/parametro/localidad.h"

namespace Ui {
class Administrador;
}

class Administrador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Administrador(QWidget *parent = 0);
    Mensaje mensaje;
    Empresa *empresa = new Empresa();
    Localidad *localidad = new Localidad();
    ~Administrador();

signals:
    void messageSent(const Mensaje &mensaje);

public slots:
    void setMensaje(const Mensaje &mensaje);

private slots:
    void sendMessage();
    void on_actionEmpresa_triggered();
    void on_actionServidor_triggered();


    void on_actionLocalidad_triggered();

private:
    Ui::Administrador *ui;
};

#endif // ADMINISTRADOR_H
