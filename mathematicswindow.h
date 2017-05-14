#ifndef MATHEMATICSWINDOW_H
#define MATHEMATICSWINDOW_H

#include <QDialog>
#include <QDir>
#include <iostream>
#include <vector>
#include <QPushButton>
#include <QVBoxLayout>
#include "qtaskbutton.h"
#include "taskwindow.h"


namespace Ui {
class MathematicsWindow;
}

class MathematicsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MathematicsWindow(QWidget *parent = 0);
    ~MathematicsWindow();
    std::vector<QPushButton*> m_buttonVector;

public slots:
  void onPushbuttonClicked();

private:
    Ui::MathematicsWindow *ui;
    TaskWindow *m_taskWindow;
    QVBoxLayout *m_mathematicsWindowLayout;
    void taskButtonsCreator();
};

#endif // MATHEMATICSWINDOW_H
