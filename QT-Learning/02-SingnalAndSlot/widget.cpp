#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>



//下课后，老师会触发一个信号，饿了，学生相应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师的对象
    this->zt=new Teacher(this);
    //创建一个学生对象
    this->st=new Student(this);

    void (Teacher::*teacherSingal)()=&Teacher::hungry;
    void (Student::*studentSingal)()=&Student::treat;

    connect(zt,teacherSingal,st,studentSingal);

    //connect(zt,&Teacher::hungry,st,&Student::treat);

    //调用下课函数
    classIsOver();

    //点击一个下课按钮触发下课
    QPushButton *btn=new QPushButton("下课",this);
    this->resize(600,400);

//    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);
    connect(btn,&QPushButton::clicked,this,
            [=](){
        emit zt->hungry();
    });

    //链接带参数的信号和槽
//    void (Teacher::*teacherSingal)(QString)=&Teacher::hungry;
//    void (Student::*studentSingal)(QString)=&Student::treat;

//    connect(zt,teacherSingal,st,studentSingal);

//    classIsOver();

    //信号是可以链接信号
    //信号可以链接多个槽函数
    //多个信号可以链接同一个槽函数
    //信号和槽函数的参数类型必须一一对应
    //信号参数的个数必须多余槽函数参数的个数
}

void Widget::classIsOver()
{
    //下课函数，调用后，触发老师饿的信号
    emit zt->hungry();
//    emit zt->hungry("shit");
}

Widget::~Widget()
{
    delete ui;
}

