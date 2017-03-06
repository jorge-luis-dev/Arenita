#ifndef CONECTAR_H
#define CONECTAR_H
#include <QtSql>
#include "administrador/parametro/servidorconfigura.h"

class Conectar
{
private:
    QSqlDatabase* db;
    struct DatosConexion {
        QString ip, puerto, base, usuario, clave, tipo;
    };
    DatosConexion dc;
public:
    Conectar(const QString &servidor);
    ~Conectar();
    QSqlDatabase *conecta(const QString& usuario,const QString& clave);
    void desconecta();
    DatosConexion getDatosConexion(QString servidor);
};

#endif // CONECTAR_H
