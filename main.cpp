#include "principal.h"
#include "iniciarsesion.h"
#include <QApplication>
#include "administrador/parametro/servidorconfigura.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Principal* w=new Principal();
    IniciarSesion* i=new IniciarSesion(w);
    w->showMaximized();
    i->show();

    /*
    ServidorConfigura s;
    s.show();
    */
    return a.exec();
}
