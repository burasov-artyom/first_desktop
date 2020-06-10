#include "mainwindow.h"
//#include "secondwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug> /*Console*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui -> click_label -> setText("Кнопка нажата");
}

void MainWindow::on_pushButton_2_clicked()
{
//      QMessageBox::about(this, "Заголовок", "Описание");
//      QMessageBox::critical(this, "Заголовок", "Описание");
//      QMessageBox::information(this, "Заголовок", "Описание");
//      QMessageBox::warning(this, "Заголовок", "Описание");
      QMessageBox::StandardButton reply = QMessageBox::question(
                  this,
                  "Заголовок",
                  "Да или нет?",
                  QMessageBox::Yes | QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          ui -> click_label -> setText("Ответ: да");
          qDebug() << "Всё верно";
      } else {
          ui -> click_label -> setText("Ответ: нет");
          QApplication::quit();
      }
}

void MainWindow::on_pushButton_3_clicked()
{
//    desabled first window
//    SecondWindow window;
//    window.setModal(true);
//    window.exec();

    hide();
//    active all window
    window = new SecondWindow(this);
    window -> show();
}

void MainWindow::on_pushButton_4_clicked()
{
    if (ui -> radioButton -> isChecked()) {
        ui -> statusBar -> showMessage("Выбран 1");
    } if (ui -> radioButton_2 -> isChecked()) {
        ui -> statusBar -> showMessage("Выбран 2");
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (ui -> checkBox -> isChecked()) {
        ui -> statusBar -> showMessage("Отмечено");
    } else {
        ui -> statusBar -> showMessage("Не отмечено");
    }
}

void MainWindow::on_action_4_triggered()
{
    QApplication::quit();
}

void MainWindow::on_action_triggered()
{

}
