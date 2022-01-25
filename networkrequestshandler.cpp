#include "networkrequestshandler.h"


NetworkRequestsHandler::NetworkRequestsHandler(QObject *parent)
{
    netManager = new QNetworkAccessManager(parent);

    //manager->get(request);


}
NetworkRequestsHandler::~NetworkRequestsHandler()
{
    free(netManager);
    free(request);
}
bool NetworkRequestsHandler::checkConnection(){
    request->setUrl(QUrl("localhost:8080/check_conn"));
    connect(netManager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

                QString answer = reply->readAll();

                qDebug() << answer;
            }
        );
    netManager->get(*request);
//    QSqlDatabase dbObj = QSqlDatabase::addDatabase("QPSQL");
//    dbObj.setDatabaseName("test_task_db");
//    dbObj.setUserName("postgres");
//   // dbObj.setPassword("123");

//    if (!dbObj.open()){
//        QMessageBox::warning(0,"Db Error",dbObj.lastError().text());
//        return false;


//    }
//    QSqlQuery query;
//    query.exec("CREATE TABLE users (username TEXT, password TEXT, code TEXT);");


//    return true;
}
bool NetworkRequestsHandler::checkAccess(QString username, QString password ){
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username=? AND password=? AND code=?;");
    query.addBindValue(username);
    query.addBindValue(password);

    query.exec();
    if (query.size()<=0){return false;}

return true;
}
bool NetworkRequestsHandler::writeNewUser(QString username, QString password,QString lastname , QString otchestvo, QString name, QString nodegroup, QString roles, QString phonenumber, QString email, QString userdescription, QString passwordexpiration, QString loginattemptsaviable){
    QSqlQuery query;

    query.prepare("SELECT * FROM users WHERE username=?;");
    query.addBindValue(username);


    query.exec();
    cout<<query.size();
           if(query.size()>0){
               QMessageBox::warning(0,"Warning","Это имя пользователя уже используется");
               return false;

         }


    query.prepare("INSERT INTO users (username,password,code) VALUES (?,?,?);");
    query.addBindValue(username);
    query.addBindValue(password);
    query.exec();
    QMessageBox::information(0,"Внимание","Запомните или запишите 4-х значный код доступа!");



return true;
}

