#ifndef SECTIONSDIALOG_H
#define SECTIONSDIALOG_H

#include <QDialog>
#include "mathematicswindow.h"
#include <memory>

class MathematicsWindow;

namespace Ui {
class SectionsDialog;
}

class SectionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SectionsDialog(QWidget *parent = 0);
    ~SectionsDialog();

private slots:
    void on_ButtonMathematics_clicked();

private:
    Ui::SectionsDialog *ui;
    std::shared_ptr<MathematicsWindow> m_mathematicsWindow;
};

#endif // SECTIONSDIALOG_H
