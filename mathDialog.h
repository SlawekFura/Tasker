#ifndef MATHDIALOG_H
#define MATHDIALOG_H

#include <QDialog>

namespace Ui {
class mathDialog;
}

class mathDialog : public QDialog
{
    Q_OBJECT

public:
    explicit mathDialog(QWidget *parent = 0);
    ~mathDialog();

private:
    Ui::mathDialog *ui;
};

#endif // MATHDIALOG_H
