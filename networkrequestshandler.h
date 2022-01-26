#ifndef NETWORKREQUESTSHANDLER_H
#define NETWORKREQUESTSHANDLER_H
#include <QSqlDatabase>
#include <QtSql>
#include "QMessageBox"
#include <string>
#include <QtWidgets>
#include <QObject>
#include <iostream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QSqlDatabase>
#include <QSql>
#include <QString>
#include <QtNetwork/QNetworkReply>
using namespace std;



class NetworkRequestsHandler :public QObject {

private :
    QNetworkAccessManager *netManager;

    const QString HEALTHY_CODE = "HEALTHY_ACT";
    const QString NEW_CLIENT_SIGNATURE = "NEW_CLIENT_ATTACHED";

Q_OBJECT

public:
    explicit NetworkRequestsHandler(QObject *parent=0);
     ~NetworkRequestsHandler();
    bool checkConnection();
    bool checkAccess(QString username, QString password );
    bool writeNewUser(QString username, QString password,QString lastname ,
                      QString patronymic, QString name, QString nodegroup, QString roles, QString phonenumber,
                      QString email, QString userdescription, QString passwordexpiration, QString loginattemptsaviable);
};

#endif // NETWORKREQUESTSHANDLER_H
