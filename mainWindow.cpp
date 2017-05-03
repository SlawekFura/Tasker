#include "mainWindow.h"
#include "ui_mainwindow.h"


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

void MainWindow::on_ButtonStart_clicked()
{
    m_sectionsDialog = new SectionsDialog;
    hide();
    m_sectionsDialog->show();
}

void MainWindow::on_ButtonProgress_clicked()
{

}
