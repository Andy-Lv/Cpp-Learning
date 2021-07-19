#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //获取当前的值
    connect(ui->btn_getvalue,&QPushButton::clicked,[=](){
        qDebug()<<ui->widget->getNum();
    });

    connect(ui->btn_sethalf,&QPushButton::clicked,[=](){
        ui->widget->setNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}

