#include "qtaskbutton.h"

QTaskButton::QTaskButton(QString string, QObject *object, QWidget *parent):QPushButton(string, parent)
{
    connect(this, SIGNAL(clicked()), object, SLOT(onPushbuttonClicked()));
}
