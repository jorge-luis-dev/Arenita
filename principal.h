#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "acerca.h"
#include "administrador.h"
#include "base/mensaje.h"

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    Mensaje mensaje;
    ~Principal();

public slots:
    void setMensaje(const Mensaje &mensaje);
    void on_actionAcerca_de_triggered();
    void on_actionAdministrador_triggered();
    void setUsuario(QString usuario);

private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
