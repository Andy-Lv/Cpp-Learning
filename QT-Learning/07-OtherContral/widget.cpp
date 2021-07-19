#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //默认scrollArea
    ui->stackedWidget->setCurrentIndex(0);

    //scrollArea
    connect(ui->btn_scrollArea,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //toolBox
    connect(ui->btn_toolBox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //tabWidget
    connect(ui->btn_tabWidget,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
}

Widget::~Widget()
{
    delete ui;
}

