#include <ctime>
#include "sectionsdialog.h"
#include "ui_sectionsdialog.h"


SectionsDialog::SectionsDialog(StartDialog * startDialog, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SectionsDialog)
{
    m_mathematicsWindow = NULL;
    m_startDialog = startDialog;
    ui->setupUi(this);
}

SectionsDialog::~SectionsDialog()
{
    if(m_mathematicsWindow != NULL)
        delete m_mathematicsWindow;
    delete ui;
}

void SectionsDialog::on_ButtonMathematics_clicked()
{
    if(!m_mathematicsWindow)
        m_mathematicsWindow = new MathematicsWindow(this);
    hide();
    m_mathematicsWindow->show();
}

void SectionsDialog::on_BackButton_clicked()
{
    hide();
    m_startDialog->show();
}
