#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include <QDialog>
#include <memory>
#include "ParsingIncludes/parsing.hpp"
#include "user.h"
#include "mathematicswindow.h"

class MathematicsWindow;

namespace Ui {
class TaskWindow;
}

class TaskWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TaskWindow(QString filename, MathematicsWindow *mathematicsWindow, QWidget *parent = 0);
    ~TaskWindow();

    void goodAnswerHandling(QString userAnswerString);
    
    void wrongAnswerHandling(QString userAnswerString);
    
private slots:
    void on_taskOkButton_clicked();

    void on_taskBackButton_clicked();

private:
    Ui::TaskWindow *ui;
    TaskData *taskData;
    std::shared_ptr<MathematicsWindow> m_mathematicsWindow;
    void fillTaskWindow(QString &filename);
};

#endif // TASKWINDOW_H
