#ifndef EMPRESA_H
#define EMPRESA_H

#include <QMainWindow>

namespace Ui {
class Empresa;
}

class Empresa : public QMainWindow
{
    Q_OBJECT

public:
    explicit Empresa(QWidget *parent = 0);
    ~Empresa();

private:
    Ui::Empresa *ui;
};

#endif // EMPRESA_H
