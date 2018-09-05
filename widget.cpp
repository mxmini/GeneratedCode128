#include "widget.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QHBoxLayout *hLayout = new QHBoxLayout;
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    QLabel *inputHint = new QLabel(this);
    inputHint->setText(QStringLiteral("请输入您需要生成的数据："));
    m_inputNum = new QLineEdit(this);
    QPushButton *generate = new QPushButton(this);
    generate->setText(QStringLiteral("产生"));

   hLayout->addWidget(inputHint);
   hLayout->addWidget(m_inputNum);
   hLayout->addWidget(generate);

   hLayout->setStretchFactor(generate, 0);

   m_showGenerate = new CustomLabel(this);
   m_showGenerate->setText(QString::fromLocal8Bit("hello world!"));

   vLayout->addLayout(hLayout);
   vLayout->addWidget(m_showGenerate);

   vLayout->setStretchFactor(hLayout, 0);
   vLayout->setStretchFactor(m_showGenerate, 1);

   QObject::connect(generate, SIGNAL(clicked(bool)), this, SLOT(getInputNum()));


}

Widget::~Widget()
{

}

void Widget::getInputNum()
{
    m_showGenerate->setSeriesNumber(m_inputNum->text().toStdString().data());
}
