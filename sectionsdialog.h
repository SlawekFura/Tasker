#ifndef SECTIONSDIALOG_H
#define SECTIONSDIALOG_H

#include <QDialog>
#include "mathematicswindow.h"
#include "startdialog.h"
#include <memory>

class MathematicsWindow;
class StartDialog;

namespace Ui {
class SectionsDialog;
}

class SectionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SectionsDialog(StartDialog * startDialog, QWidget *parent = 0);
    ~SectionsDialog();

private slots:
    void on_ButtonMathematics_clicked();

    void on_BackButton_clicked();

private:
    Ui::SectionsDialog *ui;
    std::shared_ptr<MathematicsWindow> m_mathematicsWindow;
    std::shared_ptr<StartDialog> m_startDialog;
};

#endif // SECTIONSDIALOG_H
