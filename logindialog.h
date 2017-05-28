#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <memory>
#include "user.h"
#include "startdialog.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginDialog *ui;
    std::shared_ptr<StartDialog> m_startDialog;
};

#endif // LOGINDIALOG_H
