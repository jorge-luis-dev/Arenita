#ifndef MENSAJE_H
#define MENSAJE_H
#include <QString>

class Mensaje
{
public:
    Mensaje();
    Mensaje(const Mensaje &other);
    ~Mensaje();

    Mensaje(const QString &getBody, const QString &getHeaders);

    QString getBody() const;
    QString getHeaders() const;

private:
    QString m_body;
    QString m_headers;
};
#endif // MENSAJE_H
