#include "taskwindow.h"
#include "ui_taskwindow.h"

TaskWindow::TaskWindow(QString filename, QWidget *parent):
    QDialog(parent),
    ui(new Ui::TaskWindow)
{
    ui->setupUi(this);
    ui->taskLabel->setWordWrap(true);
    fillTaskWindow(filename);
}

TaskWindow::~TaskWindow()
{
    delete ui;
}

void TaskWindow::fillTaskWindow(QString &filename)
{

    ui->taskLabel;
}
