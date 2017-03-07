#include "mensaje.h"

Mensaje::Mensaje()
{
}

Mensaje::Mensaje(const Mensaje &other)
{
    usuario = other.usuario;
    clave = other.clave;
    tipo = other.tipo;
    servidor = other.servidor;
}

Mensaje::~Mensaje()
{
}

Mensaje::Mensaje(const QString usuario, const QString &clave, const QString &tipo, const QString &servidor)
{
    this->usuario = usuario;
    this->clave = clave;
    this->tipo = tipo;
    this->servidor = servidor;
}
QString Mensaje::getUsuario() const
{
    return usuario;
}
QString Mensaje::getClave() const
{
    return clave;
}

QString Mensaje::getTipo() const
{
    return tipo;
}

QString Mensaje::getServidor() const
{
    return servidor;
}


