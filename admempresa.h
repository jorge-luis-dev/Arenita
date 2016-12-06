#ifndef ADMEMPRESA_H
#define ADMEMPRESA_H

#include <QMainWindow>

namespace Ui {
class AdmEmpresa;
}

class AdmEmpresa : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdmEmpresa(QWidget *parent = 0);
    ~AdmEmpresa();

private:
    Ui::AdmEmpresa *ui;
};

#endif // ADMEMPRESA_H
