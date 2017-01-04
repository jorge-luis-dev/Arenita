#ifndef QDBHELPER_H
#define QDBHELPER_H

#include <QtSql>
#include <QSqlQuery>


class QdbHelper
{
public:
    QdbHelper(const char* driver);
    ~QdbHelper();
        QSqlDatabase* connect( const QString& server,
                               const QString& databaseName,
                               const QString& userName,
                               const QString& password );
        void disConnect();

        int selectRowCountResult(QSqlQuery* query);
        bool executeInsert(QSqlQuery* query);
        bool executeUpdate(QSqlQuery* query);
        bool executeDelete(QSqlQuery* query);

    private:
        QSqlDatabase* db;
};

#endif // QDBHELPER_H
