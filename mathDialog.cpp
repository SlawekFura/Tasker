#include "mathDialog.h"
#include "ui_mathDialog.h"

mathDialog::mathDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mathDialog)
{
    ui->setupUi(this);
}

mathDialog::~mathDialog()
{
    delete ui;
}
