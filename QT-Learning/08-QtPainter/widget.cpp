#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击移动按钮移动图片
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        //如果需要手动调用绘图事件，用update更新
        update();
    })
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{



//    //实例化画家对象
//    QPainter painter(this);

//    //设置笔的颜色
//    QPen pen(QColor(255,0,0));
//    painter.setPen(pen);

//    painter.drawLine(QPoint(0,0),QPoint(100,100));

//    //设置画刷
//    QBrush brush(Qt::cyan);
//    painter.setBrush(brush);

//    //画圆
//    painter.drawEllipse(QPoint(100,100),50,50);
//    painter.drawEllipse(QPoint(100,100),100,50);

//    //画矩形
//    painter.drawRect(QRect(100,100,100,50));

//    //画文字
//    painter.drawText(QRect(10,200,100,50),"I am your father");

    ////////////////////////高级设置/////////////////////////////

//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100,50),50,50);

//    //设置抗锯齿 效率低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

//    painter.drawRect(QRect(20,20,50,50));

//    painter.translate(100,0);//改变画家开始绘画的起始位置
//    painter.save();//保存画家状态

//    painter.drawRect(QRect(20,20,50,50));



    ////////////////////////利用画家画资源图片/////////////////////////////

    QPainter painter(this);
    posX+=20;

    //如果超出屏幕，从0开始
    if(posX>this->width())
    {
        posX=0;
    }
    painter.drawPixmap(20,100,QPixmap("***"));

}
