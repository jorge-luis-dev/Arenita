#include "qdbhelper.h"

QdbHelper::QdbHelper(const char *driver)
{
     db = new QSqlDatabase( QSqlDatabase::addDatabase(driver) );
}

QdbHelper::~QdbHelper()
{
    qDebug() << "Destructor!";
    delete db;
}

QSqlDatabase* QdbHelper::connect( const QString& server,
                                  const QString& port,
                                     const QString& databaseName,
                                     const QString& userName,
                                     const QString& password )
{
    db->setConnectOptions();
    db->setHostName(server);
    db->setPort(port.toInt());
    db->setDatabaseName(databaseName);
    db->setUserName(userName);
    db->setPassword(password);

    if(db->open()) {
        qDebug() << "Conexión aceptada";
        return db;
    }
    else {
        qDebug() << "Conexión rechazada";
        return NULL;
    }
}

int QdbHelper::selectRowCountResult(QSqlQuery* query)
{
    bool queryRes = query->exec();
    if (query->lastError().type() != QSqlError::NoError || !queryRes)
    {
        qDebug() << query->lastError().text();
        return -1;
    }

    int recordCount = 0;
    while (query->next())
    {
        qDebug() << "Field 1 : " << query->value(0).toString()
                 << "Field 2 : " << query->value(1).toString();
        ++recordCount;
    }

    return recordCount;
}

bool QdbHelper::executeInsert(QSqlQuery* query)
{
    db->transaction();
    bool queryRes = query->exec();
    if (query->lastError().type() != QSqlError::NoError || !queryRes)
    {
        qDebug() << query->lastError().text();
        db->rollback();
        return false;
    }
    db->commit();
    return true;
}

bool QdbHelper::executeUpdate(QSqlQuery* query)
{
    db->transaction();
    bool queryRes = query->exec();
    if (query->lastError().type() != QSqlError::NoError || !queryRes)
    {
        qDebug() << query->lastError().text();
        db->rollback();
        return false;
    }
    db->commit();
    return true;
}

bool QdbHelper::executeDelete(QSqlQuery* query)
{
    db->transaction();
    bool queryRes = query->exec();
    if (query->lastError().type() != QSqlError::NoError || !queryRes)
    {
        qDebug() << query->lastError().text();
        db->rollback();
        return false;
    }
    db->commit();
    return true;
}

void QdbHelper::disConnect()
{
    qDebug() << "Disconnected From Database!";
    db->close();
}
