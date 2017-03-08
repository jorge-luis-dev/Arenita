#ifndef EMPRESA_H
#define EMPRESA_H

#include <QMainWindow>
#include "base/mensaje.h"

namespace Ui {
class Empresa;
}

class Empresa : public QMainWindow
{
    Q_OBJECT

public:
    explicit Empresa(QWidget *parent = 0);
    Mensaje mensaje;
    ~Empresa();

private:
    Ui::Empresa *ui;

signals:
    void messageSent(const Mensaje &mensaje);

public slots:
    void setMensaje(const Mensaje &mensaje);

private slots:
    void sendMessage();

};

#endif // EMPRESA_H
