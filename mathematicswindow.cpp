#include "mathematicswindow.h"
#include "ui_mathematicswindow.h"

MathematicsWindow::MathematicsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MathematicsWindow)
{
    resize(400,300);
    m_mathematicsWindowLayout = new QVBoxLayout(this);
    taskButtonsCreator();
    ui->setupUi(this);
    ui->scrollArea->widget()->setLayout(m_mathematicsWindowLayout);
    ui->scrollArea->widget()->setMinimumSize(90,m_buttonVector.size()*110);
}

MathematicsWindow::~MathematicsWindow()
{
    delete ui;
}

void MathematicsWindow::taskButtonsCreator()
{
    QDir filePath("../Tasker/physics");
    filePath.setFilter(QDir::Filters(QDir::AllEntries | QDir::NoDotAndDotDot));
    QFileInfoList listTasksNames = filePath.entryInfoList();

    for (int i=0; i<listTasksNames.size(); i++)
    {
        QTaskButton *button = new QTaskButton(listTasksNames[i].fileName(), this, this);
        button->setMinimumSize(200,100);
        button->setMaximumSize(200,100);
        m_buttonVector.push_back(button);
        m_mathematicsWindowLayout->addWidget(m_buttonVector.at(i));
    }

}

void MathematicsWindow::onPushbuttonClicked()
{
    //std::cout<<"onPushButton";
    QTaskButton* button = static_cast<QTaskButton*>(QObject::sender());
    //std::cout<<button->text().toStdString();

    m_taskWindow = new TaskWindow(button->text());
    hide();
    m_taskWindow->show();
}

