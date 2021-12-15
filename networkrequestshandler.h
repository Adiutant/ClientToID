#ifndef NETWORKREQUESTSHANDLER_H
#define NETWORKREQUESTSHANDLER_H
#include <QSqlDatabase>
#include <QtSql>
#include "QMessageBox"
#include <string>
#include <QtWidgets>
#include <iostream>
using namespace std;



class NetworkRequestsHandler
{
public:
    NetworkRequestsHandler();
    ~NetworkRequestsHandler();
    bool checkConnection();
    bool checkAccess(QString username, QString password );
    bool writeNewUser(QString username, QString password,QString lastname , QString otchestvo, QString name, QString nodegroup, QString roles, QString phonenumber, QString email, QString userdescription, QString passwordexpiration, QString loginattemptsaviable);
};

#endif // NETWORKREQUESTSHANDLER_H
