#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "database.h"
//Ui::MainWindow ui_;
//QWidget cWidget;
database db; // Empty-but assigned later!

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // ui_ = *ui;
    database ref_db("DVDRental"); // Get connected
    db = ref_db;
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
