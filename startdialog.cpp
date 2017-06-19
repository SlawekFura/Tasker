#include "startdialog.h"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    m_sectionsDialog = NULL;
    ui->setupUi(this);
}

StartDialog::~StartDialog()
{
    if(m_sectionsDialog != NULL)
        delete m_sectionsDialog;
    delete ui;
}

void StartDialog::on_ButtonStart_clicked()
{
    if(!m_sectionsDialog)
        m_sectionsDialog = new SectionsDialog(this);
    hide();
    m_sectionsDialog->show();
}
