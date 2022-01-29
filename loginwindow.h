#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include <QtNetwork/QNetworkReply>

namespace Ui {
  class LoginWindow;
};

class LoginWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void notifyConnectionUp();
    void notifyConnectionDown();
public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_loginButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
