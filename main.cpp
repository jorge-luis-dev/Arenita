#include "principal.h"
#include "iniciarsesion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal* w=new Principal();
    IniciarSesion* i=new IniciarSesion(w);
    w->showMaximized();
    i->show();
    return a.exec();
}
