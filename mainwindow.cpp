#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestiondesproduits.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/ASUS/Desktop/2021-2022/Projects/C++Qt/Projects/Gestion Des Produits/MW.jpg");
    ui->IMG->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    GestionDesProduits GDP;
    GDP.setModal(true);
    GDP.exec();
}

void MainWindow::on_pushButton_04_clicked()
{
    exit(1);
}
