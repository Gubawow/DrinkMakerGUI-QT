#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"

#include <iostream>

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QFont>
#include <QColor>
#include <QColorDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPixmap>
#include <QDir>

loginwindow::loginwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);
}

loginwindow::~loginwindow()
{
    delete ui;
}

void loginwindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QFile login(":/resources/Login/login.txt");

    if(!login.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", login.errorString());
    }

    QTextStream in(&login);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split("\t");

        if(username == fields.at(0) && password == fields.at(1)){
            this->correct=0;
            close();
            break;
        }
        else if(username ==fields.at(0) && password != fields.at(1)){
            this->correct=1;
            break;
        }
        else{
            this->correct=2;
            continue;
        }
    }
    login.close();

    switch(correct){

    case 0:
        MainWindow::logged_in=true;
        QMessageBox::information(this, "Success", "You have logged in successfully");
        break;

    case 1:
        QMessageBox::warning(this, "Error", "Password is incorrect");
        break;

    case 2:
        QMessageBox::warning(this, "Error", "Username or/and password are incorrect");
        break;

    default:
        break;
    }

}

void loginwindow::on_pushButton_2_clicked()
{
    close();
}
