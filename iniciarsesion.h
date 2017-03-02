#ifndef INICIARSESION_H
#define INICIARSESION_H

#include <QDialog>

namespace Ui {
class IniciarSesion;
}

class IniciarSesion : public QDialog
{
    Q_OBJECT

public:
    explicit IniciarSesion(QWidget *parent = 0);
    ~IniciarSesion();

private slots:
    void reject();
    void OnQuit();
    void OnLogin();
    QString getServidorPredeterminado();
    QStringList getServidores();
    bool Login(QString u, QString p);


    void on_pushConexiones_clicked();

private:
    Ui::IniciarSesion *ui;
};

#endif // INICIARSESION_H
