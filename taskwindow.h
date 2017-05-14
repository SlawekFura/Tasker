#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include <QDialog>

namespace Ui {
class TaskWindow;
}

class TaskWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TaskWindow(QString filename, QWidget *parent = 0);
    ~TaskWindow();

private:
    Ui::TaskWindow *ui;
    void fillTaskWindow(QString &filename);
};

#endif // TASKWINDOW_H
