#include <ctime>
#include "sectionsdialog.h"
#include "ui_sectionsdialog.h"


SectionsDialog::SectionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SectionsDialog)
{
    ui->setupUi(this);
}

SectionsDialog::~SectionsDialog()
{
    delete ui;
}

void SectionsDialog::on_ButtonMathematics_clicked()
{
    if(!m_mathematicsWindow)
        m_mathematicsWindow = std::shared_ptr<MathematicsWindow>(new MathematicsWindow(this));
    hide();
    m_mathematicsWindow->show();
}
