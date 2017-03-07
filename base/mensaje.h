#ifndef MENSAJE_H
#define MENSAJE_H
#include <QString>

class Mensaje
{
public:
    Mensaje();
    Mensaje(const Mensaje &other);
    ~Mensaje();

    Mensaje(const QString usuario,const QString &clave, const QString &tipo, const QString &servidor);

    QString getUsuario() const;
    QString getClave() const;
    QString getTipo() const;
    QString getServidor() const;

private:
    QString usuario;
    QString clave;
    QString tipo;
    QString servidor;
};
#endif // MENSAJE_H
