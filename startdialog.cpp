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
    if(!m_sectionsDialog)
        m_sectionsDialog = std::shared_ptr<SectionsDialog>(new SectionsDialog(this));
    hide();
    m_sectionsDialog->show();
}
