#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include "sectionsdialog.h"
#include <memory>

class SectionsDialog;

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT
public:
    explicit StartDialog(QWidget *parent = 0);
    ~StartDialog();

private slots:
    void on_ButtonStart_clicked();

private:
    Ui::StartDialog *ui;
    QMainWindow *m_mainWindow;
    SectionsDialog* m_sectionsDialog;
};

#endif // STARTDIALOG_H
