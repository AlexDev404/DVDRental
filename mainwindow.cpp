#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "database.h"
database db("DVDRental"); // Get connected
//Ui::MainWindow ui_;
//QWidget cWidget;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // ui_ = *ui;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sign_in_clicked()
{
    QString username = ui->password->text();
    QString password = ui->username->text();
}
