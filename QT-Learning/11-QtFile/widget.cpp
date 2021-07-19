#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击选取文件按钮弹出文件对话框
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","\\home\andy");

        //将路径放入linedit中
        ui->lineEdit->setText(path);

        //读取内容放入到textedit中 默认支持utf-8

        //设置编码格式
        QTextCodec * CODEC=QTextCodec::codecForName("GBK");

        QFile file(path);
        //设置打开方式
        file.open(QIODevice::ReadOnly);//只读

        //按行读取
//        QByteArray array;
//        while(!file.atEnd())
//        {
//            array+=file.readLine();
//        }

        QByteArray array=file.readAll();
        //将读取到的放入textedit中
        //ui->textEdit->setText(array);

        ui->textEdit->setText(CODEC->toUnicode(array));

        file.close();

        //进行写文件
//        file.open(QIODevice::Append);//运用追加的方式写
//        file.write("aaaaaaa");
//        file,close();

        //qfileinfo文件信息
        QFileInfo info(path);
        qDebug()<<"大小"<<info.size()<<"后缀名"<<info.suffix();
        qDebug()<<"创建日期"<<info.created().toString("yyyy/MM/dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}

