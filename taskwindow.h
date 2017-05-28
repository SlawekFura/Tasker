#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include <QDialog>
#include "ParsingIncludes/parsing.hpp"

namespace Ui {
class TaskWindow;
}

class TaskWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TaskWindow(QString filename, QWidget *parent = 0);
    ~TaskWindow();

private slots:
    void on_taskOkButton_clicked();

private:
    Ui::TaskWindow *ui;
    TaskData *taskData;
    void fillTaskWindow(QString &filename);
};

#endif // TASKWINDOW_H
