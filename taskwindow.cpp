#include "taskwindow.h"
#include "ui_taskwindow.h"

#include <string>
#include <QMessageBox>
#include <iomanip>

#define EPSILON 0.005


extern User user;
class MathematicsWindow;

TaskWindow::TaskWindow(QString filename, MathematicsWindow * mathematicsWindow, QWidget *parent):
    QDialog(parent),
    ui(new Ui::TaskWindow)
{
    taskData = new TaskData(((string)"../Tasker/mathematics/" + filename.toStdString()).c_str());
    m_mathematicsWindow = mathematicsWindow;
    ui->setupUi(this);
    ui->taskLabel->setWordWrap(true);
    fillTaskWindow(filename);
}

TaskWindow::~TaskWindow()
{
    delete ui;
    delete taskData;
}

void TaskWindow::fillTaskWindow(QString &filename)
{
    ui->titleLabel->setText(filename);
    ui->titleLabel->setAlignment(Qt::AlignCenter);
    ui->taskLabel->setText(QString::fromStdString(taskData->getTaskField()));
    ui->answerFormLabel->setText(QString::fromStdString(taskData->getAnswerString()));
}

void TaskWindow::goodAnswerHandling(QString userAnswerString)
{
    user.setTaskStatus(ui->titleLabel->text(), true);
    m_mathematicsWindow->setTaskButtonColor(ui->titleLabel->text(), true);
    QMessageBox msgBox;
    msgBox.setText("GOOD!");
    msgBox.setInformativeText(userAnswerString);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();    
}

void TaskWindow::wrongAnswerHandling(QString userAnswerString)
{
    user.setTaskStatus(ui->titleLabel->text(), false);
    m_mathematicsWindow->setTaskButtonColor(ui->titleLabel->text(), false);
    QMessageBox msgBox;
    msgBox.setText("Wrong Answer!");
    msgBox.setInformativeText(userAnswerString);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();    
}

void TaskWindow::on_taskOkButton_clicked()
{
    QString userAnswerString = ui->lineEdit->text();
    bool conversion_flag = true;
    double userAnswer = ui->lineEdit->text().toDouble(&conversion_flag);
    if(!conversion_flag)
    {
        QMessageBox msgBox;
        msgBox.setText("Wrong format!");
        msgBox.setInformativeText(userAnswerString);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    if(fabs(userAnswer - taskData->getAnswer()) < EPSILON)
    {
        goodAnswerHandling(userAnswerString);
    }
    else
    {
        wrongAnswerHandling(userAnswerString);
    }
}

void TaskWindow::on_taskBackButton_clicked()
{
    hide();
    m_mathematicsWindow->show();
}
