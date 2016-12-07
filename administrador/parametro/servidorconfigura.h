#ifndef SERVIDORCONFIGURA_H
#define SERVIDORCONFIGURA_H

#include <QMainWindow>

namespace Ui {
class ServidorConfigura;
}

class ServidorConfigura : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServidorConfigura(QWidget *parent = 0);
    ~ServidorConfigura();

private:
    Ui::ServidorConfigura *ui;
};

#endif // SERVIDORCONFIGURA_H
