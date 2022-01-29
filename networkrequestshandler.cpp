#include "networkrequestshandler.h"


NetworkRequestsHandler::NetworkRequestsHandler(QObject *parent)
{
    netManager = new QNetworkAccessManager(parent);

    //manager->get(request);


}
NetworkRequestsHandler::~NetworkRequestsHandler()
{
    //free(netManager);
    //free(request);
}
void NetworkRequestsHandler::checkConnection(LoginWindow* window){
    QTcpSocket jSocket;
    QJsonObject obj;
    obj.insert("request",NEW_CLIENT_SIGNATURE);
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    jSocket.connectToHost("127.0.0.1",80);
    if (jSocket.waitForConnected(2000))
    {
    jSocket.write(data);
    }
    if (jSocket.waitForReadyRead(2000))
    {
        doc = QJsonDocument::fromJson(jSocket.readAll());
        obj = doc.object();
        if (obj["response"] == NEW_CLIENT_SIGNATURE_ACCEPTED)
        {
            window->notifyConnectionUp();
        }
        else
        {
            window->notifyConnectionDown();
        }

    }
    else
    {
        window->notifyConnectionDown();
    }
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
bool NetworkRequestsHandler::checkAccess(QString username, QString password , LoginWindow* window){
    QTcpSocket jSocket;
    QJsonObject obj;
    obj["request"] = LOGIN_CLIENT_SIGNATURE;
    obj["username"] = username;
    obj["password"] = password;
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    jSocket.connectToHost("127.0.0.1",80);
    if (jSocket.waitForConnected(2000))
    {
    jSocket.write(data);
    }
    if (jSocket.waitForReadyRead(2000))
    {
        doc = QJsonDocument::fromJson(jSocket.readAll());
        obj = doc.object();
        if (obj["response"] == LOGIN_CLIENT_SIGNATURE_SUCCESS)
        {
            accessToken = obj["access_token"];
            window->notifyConnectionUp();
        }
        else
        {
            window->notifyConnectionDown();
        }

    }
    else
    {
        window->notifyConnectionDown();
    }




//    QSqlQuery query;
//    query.prepare("SELECT * FROM users WHERE username=? AND password=? AND code=?;");
//    query.addBindValue(username);
//    query.addBindValue(password);

//    query.exec();
//    if (query.size()<=0){return false;}

return true;
}
bool NetworkRequestsHandler::writeNewUser(QString username, QString password, QString lastname,
                                          QString patronymic, QString name, QString nodegroup,
                                          QString roles, QString phonenumber, QString email,
                                          QString userdescription, QString passwordexpiration, QString loginattemptsaviable){
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

