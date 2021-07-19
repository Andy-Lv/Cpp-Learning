#include "smallwidget.h"
#include "ui_smallwidget.h"

smallWidget::smallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallWidget)
{
    ui->setupUi(this);

    //QSponBox移动 QSLIDER跟着移动

    void(QSpinBox::*spSignal)(int)=&QSpinBox::valueChanged;
    connect(ui->spinBox,spSignal,ui->horizontalSlider,&QSlider::setValue);

    //反过来
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

smallWidget::~smallWidget()
{
    delete ui;
}


void smallWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}

int smallWidget::getNum()
{
    return ui->spinBox->value();
}
