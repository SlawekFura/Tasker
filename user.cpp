#include "user.h"
#include <iostream>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <string>

const QString path("../Tasker/userdata/userdata");

User::User()
{
    QFileInfo filePath(path);
    if(filePath.exists())
    {
        loadUserData();
        m_userNameSet = true;
        return;
    }
    m_userNameSet = false;
}

void User::setUserName(QString p_name, QString p_surname)
{
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

void User::getTaskStatusFromTextLine(QString & line, std::map<QString, bool> &taskMap)
{
    int pos = line.toStdString().find(' ');
    std::string lineTemp = line.toStdString();
    std::string taskNameTemp = lineTemp.substr(0, pos);
    QString taskName(QString::fromStdString(taskNameTemp));
    bool taskStatus = (bool)std::stoi(lineTemp.substr(pos));
    taskMap[taskName] = taskStatus;
}

void User::loadUserData()
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    for(int i=0; !in.atEnd(); i++)
    {
        QString line = in.readLine();
        if (i==0) m_name = line;
        else if(i==1) m_surname = line;
        else if(!line.isEmpty())
        {
            getTaskStatusFromTextLine(line, m_tasksStatus);
        }
    }
    file.close();
}

void User::setTaskStatus(QString taskName, bool taskStatus)
{
    m_tasksStatus[taskName] = taskStatus;
}

User::~User()
{
    if(!isUserNameSet())
        return;
    std::map<QString, bool> l_taskMap;
    QFile file(path);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QTextStream in(&file);
    for(int i=0; !in.atEnd(); i++)
    {
        QString line = in.readLine();
        if(i>=2)
        {
            getTaskStatusFromTextLine(line, l_taskMap);
        }
    }

    for(auto elem : m_tasksStatus)
    {
        if(l_taskMap.find(elem.first) == l_taskMap.end())
            in<<endl<<elem.first<<" "<<m_tasksStatus[elem.first];
    }
    file.close();
}

bool User::isElemInMap(QString taskName)
{
    return m_tasksStatus.find(taskName) != m_tasksStatus.end();
}


