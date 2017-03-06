#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);    
    ~Principal();

public slots:
    void on_actionAcerca_de_triggered();
    void on_actionAdministrador_triggered();
    void setUsuario(QString usuario);
    void setClave(QString clave);
    void setTipo(QString tipo);
    void setServidor(QString servidor);

private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
