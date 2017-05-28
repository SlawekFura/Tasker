#include "user.h"
#include <iostream>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <string>

User::User()
{
    QString path = "../Tasker/userdata/userdata";
    QFileInfo filePath(path);
    if(filePath.exists())
    {
     loadUserData(path);
     m_userNameSet = true;
     return;
    }
    m_userNameSet = false;
}

void User::setUserName(QString p_name, QString p_surname)
{
    QString path = "../Tasker/userdata/userdata";
    QFileInfo filePath(path);
    if(!filePath.exists())
    {
        QFile userdata(path);
        userdata.open(QIODevice::ReadWrite);
        {
            QTextStream stream(&userdata);
            stream << p_name << endl << p_surname << endl;
        }
    }
    m_userNameSet = true;
}

void User::loadUserData(QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    for(int i=0; !in.atEnd(); i++)
    {
        QString line = in.readLine();
        if(i==0) m_name = line;
        else if(i==1) m_surname = line;
        else
        {
            int pos = line.toStdString().find(' ');
            std::string lineTemp = line.toStdString();
            std::string taskNameTemp = lineTemp.substr(0, pos);
            QString taskName(QString::fromStdString(taskNameTemp));
            bool taskStatus = (bool)std::stoi(lineTemp.substr(pos));
            m_tasksStatus[taskName] = taskStatus;
        }
    }
    file.close();
}
