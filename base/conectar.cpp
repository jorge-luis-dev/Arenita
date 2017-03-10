#include "conectar.h"


Conectar::Conectar(const QString &servidor)
{
    dc = getDatosConexion(servidor);
    QStringList list = QSqlDatabase::connectionNames();

    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = new  QSqlDatabase(QSqlDatabase::database("qt_sql_default_connection"));
    else
        db = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"));
    /*
    qDebug() << "Número de bases:" << list.count();
    if(list.count()>0){
        for(int i = 0; i < list.count(); ++i) {
            QSqlDatabasePrivate::removeDatabase(list[i]);
            qDebug() << "Nombres de conexión:" << list[i];
        }
    }
    */
    qDebug() << "Driver:" << db->driverName();
}

Conectar::~Conectar()
{
    db->close();
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

void Conectar::desconecta()
{
        //QSqlDatabase::removeDatabase(db->connectionName());
        db->close();
}
