#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sectionsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ButtonStart_clicked();
    void on_ButtonProgress_clicked();

private:
    Ui::MainWindow *ui;
    SectionsDialog *m_sectionsDialog;
};

#endif // MAINWINDOW_H
