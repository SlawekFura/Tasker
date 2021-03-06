#include "mathematicswindow.h"
#include "ui_mathematicswindow.h"
#include "user.h"
#include <algorithm>


extern User user;

MathematicsWindow::MathematicsWindow(SectionsDialog *sectionsDialog, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MathematicsWindow)
{
    m_taskWindow = NULL;
    m_sectionsDialog = sectionsDialog;
    resize(400,300);
    m_mathematicsWindowLayout = new QVBoxLayout(this);
    taskButtonsCreator();
    ui->setupUi(this);
    ui->scrollArea->widget()->setLayout(m_mathematicsWindowLayout);
    ui->scrollArea->widget()->setMinimumSize(90,m_buttonVector.size()*110);
}

MathematicsWindow::~MathematicsWindow()
{
    if(m_taskWindow != NULL)
        delete m_taskWindow;
    delete ui;
}

void MathematicsWindow::taskButtonsCreator()
{
    QDir filePath("../Tasker/mathematics");
    filePath.setFilter(QDir::Filters(QDir::AllEntries | QDir::NoDotAndDotDot));
    QFileInfoList listTasksNames = filePath.entryInfoList();

    for (int i=0; i<listTasksNames.size(); i++)
    {
        QTaskButton *button = new QTaskButton(listTasksNames[i].fileName(), this, this);
        if(user.isElemInMap(listTasksNames[i].fileName()))
        {
            if(user.getTaskStatus(listTasksNames[i].fileName()))
                button->setStyleSheet("background-color: green");
            else
                button->setStyleSheet("background-color: red");
        }

        button->setMinimumSize(200,100);
        button->setMaximumSize(200,100);
        m_buttonVector.push_back(button);
        m_mathematicsWindowLayout->addWidget(m_buttonVector.at(i));
    }

}

void MathematicsWindow::onPushbuttonClicked()
{
    QTaskButton* button = static_cast<QTaskButton*>(QObject::sender());

    m_taskWindow = new TaskWindow(button->text(), this);
    hide();
    m_taskWindow->show();
}

void MathematicsWindow::setTaskButtonColor(QString taskName, bool state)
{
    auto iter = m_buttonVector.begin();
    for(;iter != m_buttonVector.end(); iter++)
    {
        if((*iter)->text() == taskName)
            break;
    }
    if (iter == m_buttonVector.end())
        return;
    if((*iter)->styleSheet() == "background-color: green")
    {
        return;
    }
    else
    {
        if(state)
            (*iter)->setStyleSheet("background-color: green");
        else
            (*iter)->setStyleSheet("background-color: red");
    }
}



void MathematicsWindow::on_BackButton_clicked()
{
    hide();
    m_sectionsDialog->show();
}
