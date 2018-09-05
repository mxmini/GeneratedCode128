#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include "customlabel.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void getInputNum();

private:
     QLineEdit *m_inputNum;
      CustomLabel *m_showGenerate;
};

#endif // WIDGET_H
