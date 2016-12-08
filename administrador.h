#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <QMainWindow>

namespace Ui {
class Administrador;
}

class Administrador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Administrador(QWidget *parent = 0);
    ~Administrador();

private slots:
    void on_actionEmpresa_triggered();

    void on_actionServidor_triggered();

private:
    Ui::Administrador *ui;
};

#endif // ADMINISTRADOR_H
