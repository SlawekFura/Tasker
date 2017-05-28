#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShowEvent>
#include <memory>
#include "startDialog.h"
#include "logindialog.h"
#include "user.h"


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
    void on_OKButton_clicked();
private:
    Ui::MainWindow *ui;
    std::shared_ptr<StartDialog> m_startWindow;
    std::shared_ptr<LoginDialog> m_loginDialog;

};

#endif // MAINWINDOW_H
