#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/image/sing-in.png");
    int w = ui -> image -> width();
    int h = ui -> image -> height();

    ui -> image -> setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_authButton_clicked()
{
    QString login = ui -> login -> text();
    QString password = ui -> password -> text();

    if(login == "Misha" && password == "123") {
        QMessageBox::information(this, "Уведомление", "Авторизация прошла успешно");
    } else {
        QMessageBox::warning(this, "Уведомление", "Данные введены неверно");
    }
}
