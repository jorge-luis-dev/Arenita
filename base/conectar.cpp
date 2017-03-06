#include "conectar.h"

Conectar::Conectar(const QString &servidor)
{
    dc = getDatosConexion(servidor);
    db = new QSqlDatabase( QSqlDatabase::addDatabase("QPSQL") );
    qDebug() << "Driver:" << db->driverName();
}

QSqlDatabase *Conectar::conecta(const QString &usuario, const QString &clave)
{
    db->setConnectOptions();
    db->setHostName(dc.ip);
    db->setPort(dc.puerto.toInt());
    db->setDatabaseName(dc.base);
    db->setUserName(usuario);
    db->setPassword(clave);

    if(db->open()) {
        qDebug() << "Conexión aceptada";
        return db;
    }
    else {
        qDebug() << "Conexión rechazada" << db->lastError();
        return NULL;
    }
}

Conectar::DatosConexion Conectar::getDatosConexion(QString servidor)
{
    DatosConexion dc;
    QSettings settings(ServidorConfigura::homeConfig+ QDir::separator() +"Arenita.ini", QSettings::NativeFormat);

    settings.beginGroup(servidor);

    const QStringList datosServidor = settings.childKeys();
    /*
     * Recupera los datos de conexión en la estructura
    */
    foreach (const QString &nombre, datosServidor)
    {
        if(nombre=="ip"){
            dc.ip=settings.value(nombre).toString();
        }
        else if (nombre=="puerto") {
            dc.puerto=settings.value(nombre).toString();
        }
        else if (nombre=="baseDatos") {
            dc.base=settings.value(nombre).toString();
        }
    }
    settings.endGroup();

    qDebug() << "Datos de Conexión";
    qDebug() << "ip:" << dc.ip;
    qDebug() << "puerto:" << dc.puerto;
    qDebug() << "base de datos:" << dc.base;

    return dc;
}
