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
#include "sectionsdialog.h"
#include <memory>

class TaskWindow;
class SectionsDialog;

namespace Ui {
class MathematicsWindow;
}

class MathematicsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MathematicsWindow(SectionsDialog * sectionsDialog, QWidget *parent = 0);
    ~MathematicsWindow();
    std::vector<QPushButton*> m_buttonVector;

public slots:
  void onPushbuttonClicked();
  void setTaskButtonColor(QString taskName, bool state);

private slots:
  void on_BackButton_clicked();

private:
    Ui::MathematicsWindow *ui;
    SectionsDialog *m_sectionsDialog;
    TaskWindow *m_taskWindow;
    QVBoxLayout *m_mathematicsWindowLayout;
    void taskButtonsCreator();
};

#endif // MATHEMATICSWINDOW_H
