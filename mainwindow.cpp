#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include <windows.h>


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

void MainWindow::on_OKButton_clicked()
{
    QString path = "../Tasker/userdata/userdata";
    QFileInfo filePath(path);
    if(filePath.exists())
    {
        m_startWindow = std::shared_ptr<StartDialog>(new StartDialog(this));
        m_startWindow->show();
    }
    else
    {
        m_loginDialog = std::shared_ptr<LoginDialog>(new LoginDialog(this));
        m_loginDialog->show();
    }
    hide();
}
