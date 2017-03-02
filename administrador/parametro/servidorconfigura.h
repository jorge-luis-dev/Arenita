#ifndef SERVIDORCONFIGURA_H
#define SERVIDORCONFIGURA_H

#include <QMainWindow>
#include <QSettings>
#include <QDir>

namespace Ui {
class ServidorConfigura;
}

class ServidorConfigura : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServidorConfigura(QWidget *parent = 0);
    static const QString homeConfig;
    ~ServidorConfigura();

private slots:
    void on_pushCrearArchivoConfig_clicked();
    bool crearCarpetaArenitaConfig();
    bool crearArchivoArenita_ini(QString nombreServidor, QString ipServidor, QString puerto, QString baseDatos);

private:
    Ui::ServidorConfigura *ui;
};

#endif // SERVIDORCONFIGURA_H
