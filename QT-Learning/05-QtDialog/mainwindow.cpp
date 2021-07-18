#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮，弹出对话框
    //模态对话框
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框分为模态对话框（不可以对其他窗口进行操作）和非模态对话框（可以对其他窗口进行操作）
        //模态创建
//        QDialog dlg(this);
//        dlg.resize(100,100);
//        dlg.exec();

        //非模态对话框
        //防止一闪而过需要放在堆区
//        QDialog *dlg2=new QDialog (this);
//        dlg2->resize(100,100);
//        dlg2->show();
//        //关闭的时候释放掉
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);

        //消息对话框
        QMessageBox::critical(this,"critical","错误");//错误对话框

        QMessageBox::information(this,"info","信息");//信息对话框

        //参数：父亲、标题、提示内容、按键类型，默认关联回车按键
        QMessageBox::question(this,"ques","提问",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Save);//提问对话框

        QMessageBox::warning(this,"warning","警告");
    });



}

MainWindow::~MainWindow()
{
    delete ui;
}

