#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //PixMap绘图设备
//    QPixmap pix(300,300);

//    pix.fill(Qt::white);//设置背景色为白色

//    //声明画家
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::red));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    //保存
//    pix.save("pix.png");

//    //QImage
//    QImage image(300,300,QImage::Format_ARGB32);
//    image.fill(Qt::white);
//    QPainter painter(&image);
//    painter.setPen(QPen(Qt::red));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    image.save("image.png");

    //QPicture 绘图设备 可以记录和重新绘图指令
    QPicture pic;
    QPicture painter;
    painter.begin(&pic);

    painter.end();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //利用image对像素进行修改
    QImage img;
    img.load("***");

    //修改像素点
    for(int i=50;i<100;i++)
    {
        for (int j=50;j<100 ;j++ ) {
            QRgb value=qRgb(255,0,0);
            img.setPixel(i,j,value);
        }
    }

    painter.drawImage(0,0,img);
}

Widget::~Widget()
{
    delete ui;
}

