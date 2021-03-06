#ifndef USER_H
#define USER_H

#include <vector>
#include <map>
#include <string>
#include <QMainWindow>

using std::string;

class User
{
private:
    QString m_name;
    QString m_surname;
    std::map<QString, bool> m_tasksStatus;
    bool m_userNameSet;
    void loadUserData();
    void getTaskStatusFromTextLine(QString &line, std::map<QString, bool> &taskMap);
public:
    User();
    ~User();
    QString getUserName()    {return m_name;}
    QString getUserSurname() {return m_surname;}
    bool isUserNameSet()     {return m_userNameSet;}
    void setUserName(QString p_name, QString p_surname);
    bool getTaskStatus(QString);
    bool isElemInMap(QString taskName);
    void setTaskStatus(QString taskName, bool taskStatus);


};

#endif // USER_H
