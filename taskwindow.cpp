#include "taskwindow.h"
#include "ui_taskwindow.h"
#include "string"

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
    TaskData taskData(((string)"D:/Programowanie/QtWorkspace/Tasker/physics/" + filename.toStdString()).c_str());
    ui->titleLabel->setText(filename);
    ui->taskLabel->setText(QString::fromStdString(taskData.getTaskField()));
    ui->answerFormLabel->setText(QString::fromStdString(taskData.getAnswerString()));
}
