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
#include <QHttpPart>
#include <loginwindow.h>
using namespace std;



class NetworkRequestsHandler :public QObject {

private :
    QNetworkAccessManager *netManager;

    const QString HEALTHY_CODE = "HEALTHY_ACT";
    const QString NEW_CLIENT_SIGNATURE = "NEW_CLIENT_ATTACHED";
    const QString NEW_CLIENT_SIGNATURE_ACCEPTED = "NEW_CLIENT_ATTACHED_YES";

Q_OBJECT

public:
    explicit NetworkRequestsHandler(QObject *parent=0);
     ~NetworkRequestsHandler();
    void checkConnection(LoginWindow* window);
    bool checkAccess(QString username, QString password );
    bool writeNewUser(QString username, QString password,QString lastname ,
                      QString patronymic, QString name, QString nodegroup, QString roles, QString phonenumber,
                      QString email, QString userdescription, QString passwordexpiration, QString loginattemptsaviable);
};

#endif // NETWORKREQUESTSHANDLER_H
