#include "startdialog.h"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_ButtonStart_clicked()
{
    m_sectionsDialog = std::shared_ptr<SectionsDialog>(new SectionsDialog);
    hide();
    m_sectionsDialog->show();
}
