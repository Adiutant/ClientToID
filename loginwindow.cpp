#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
void LoginWindow::notifyConnectionUp()
{
    QMessageBox::information(this,"Успешно","Соединение установлено!");

}
void LoginWindow::notifyConnectionDown()
{
    QMessageBox::warning(this,"Ошибка","Сервер недоступен!");
}
void LoginWindow::on_loginButton_clicked()
{

}

void LoginWindow::on_registerButton_clicked()
{

}
