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

}
