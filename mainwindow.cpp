#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include <windows.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_startWindow = NULL;
    m_loginDialog = NULL;
}

MainWindow::~MainWindow()
{
    if(m_startWindow != NULL)
        delete m_startWindow;
    if(m_loginDialog != NULL)
        delete m_loginDialog;
    delete ui;
}

void MainWindow::on_OKButton_clicked()
{
    QString folderPath = "../Tasker/userdata";
    if(!QDir(folderPath).exists())
        QDir().mkdir(folderPath);

    QString path = "../Tasker/userdata/userdata";
    QFileInfo filePath(path);
    if(filePath.exists())
    {
        m_startWindow = new StartDialog(this);
        m_startWindow->show();
    }
    else
    {
        m_loginDialog = new LoginDialog(this);
        m_loginDialog->show();
    }
    hide();
}
