#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);

    //菜单栏,最多只能有一个
    QMenuBar * bar=menuBar();
    setMenuBar(bar);

    //创建菜单
    QMenu * fileMenu= bar->addMenu("Flie");
    QMenu * editMenu= bar->addMenu("Edit");

    //创建菜单项
    QAction * newAction= fileMenu->addAction("新建");
    //添加分割符
    fileMenu->addSeparator();
    QAction * openAction=fileMenu->addAction("打开");

    //工具栏 可以有多个
    QToolBar * toolBar=new QToolBar(this);
    addToolBar(toolBar);

    //后期设置，只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);

    //设置浮动
    toolBar->setFloatable(false);

    //设置移动 总开关
    toolBar->setMovable(false);

    //工具栏可以设置内容
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    //状态栏 最多只有一个
    QStatusBar *stbar= statusBar();
    //设置到窗口中
    setStatusBar(stbar);
    //放标签控件
    QLabel * label=new QLabel("提示信息",this);
    stbar->addWidget(label);

    QLabel * label2=new QLabel("右侧提示信息",this);
    stbar->addPermanentWidget(label2);

    //铆接部件（浮动窗口）
    QDockWidget * dockWidget =new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);

    //设置后续停靠区域 只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);


    //设置中心部件 只能一个
    QTextEdit * edit =new QTextEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{
}

