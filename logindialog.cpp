#include "logindialog.h"
#include "ui_logindialog.h"


extern User user;
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
    if(!user.isUserNameSet() && !ui->NameLineEdit->text().isEmpty() && !ui->SurnameLineEdit->text().isEmpty())
    {
    user.setUserName(ui->NameLineEdit->text(), ui->SurnameLineEdit->text());
    m_startDialog = new StartDialog;
    m_startDialog->show();
    this->hide();
    }
}
