#include "mensaje.h"

Mensaje::Mensaje()
{
}

Mensaje::Mensaje(const Mensaje &other)
{
    m_body = other.m_body;
    m_headers = other.m_headers;
}

Mensaje::~Mensaje()
{
}

Mensaje::Mensaje(const QString &body, const QString &headers)
{
    m_body = body;
    m_headers = headers;
}

QString Mensaje::getBody() const
{
    return m_body;
}

QString Mensaje::getHeaders() const
{
    return m_headers;
}
