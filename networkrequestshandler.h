#ifndef DBHELPER_H
#define DBHELPER_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSql>
#include <string>
#include <iostream>

class DbHelper
{
public:
    DbHelper();
    ~DbHelper();
    bool checkConnection();
    bool writeNewUser(QString username, QString password );
    bool checkAccess(QString username, QString password,QString lastname , QString otchestvo, QString name, QString nodegroup, QString roles, QString phonenumber, QString email, QString userdescription, QString passwordexpiration, QString loginattemptsaviable);
};

#endif // DBHELPER_H
