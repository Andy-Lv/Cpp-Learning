#include "mywidget.h"
#include<QPushButton>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton *btn=new QPushButton;
//    btn->show();//show以顶层的方式弹出界面

    //让btn对象依赖在mywidget窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("第一个按钮");

    //创建第二个个按钮
    QPushButton *btn2=new QPushButton("第二个按钮",this);

    btn2->move(100,100);

    //重置窗口大小
    resize(600,800);

    //设置固定的窗口大小,不能改变窗口大小
    setFixedSize(100,800);

    //设置窗口标题
    setWindowTitle("第一个窗口");

    //点击第一个按钮将窗口关闭
    //参数：信号发送者，发送的信号(函数地址)，信号接受者，处理的槽函数(函数地址)
    connect(btn,&QPushButton::clicked,this,&myWidget::close);

}

myWidget::~myWidget()
{

}

