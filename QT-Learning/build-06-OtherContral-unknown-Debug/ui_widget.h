/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QWidget *page_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *page_5;
    QToolBox *toolBox;
    QWidget *page;
    QPushButton *pushButton_8;
    QWidget *page_2;
    QToolButton *toolButton;
    QWidget *page_3;
    QRadioButton *radioButton;
    QPushButton *btn_scrollArea;
    QPushButton *btn_toolBox;
    QPushButton *btn_tabWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(50, 60, 361, 451));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        scrollArea = new QScrollArea(page_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 30, 141, 401));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 125, 507));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        verticalLayout->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        verticalLayout->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        verticalLayout->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        verticalLayout->addWidget(pushButton_14);

        pushButton_15 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        verticalLayout->addWidget(pushButton_15);

        pushButton_16 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        verticalLayout->addWidget(pushButton_16);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        stackedWidget->addWidget(page_4);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        tabWidget = new QTabWidget(page_6);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(50, 60, 181, 341));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        stackedWidget->addWidget(page_6);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        toolBox = new QToolBox(page_5);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(30, 30, 181, 371));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 181, 269));
        pushButton_8 = new QPushButton(page);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(40, 30, 87, 27));
        toolBox->addItem(page, QString::fromUtf8("\345\256\266\344\272\272"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 181, 269));
        toolButton = new QToolButton(page_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(70, 50, 26, 26));
        toolBox->addItem(page_2, QString::fromUtf8("\346\234\213\345\217\213"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        radioButton = new QRadioButton(page_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(40, 70, 109, 25));
        toolBox->addItem(page_3, QString::fromUtf8("\351\273\221\345\220\215\345\215\225"));
        stackedWidget->addWidget(page_5);
        btn_scrollArea = new QPushButton(Widget);
        btn_scrollArea->setObjectName(QString::fromUtf8("btn_scrollArea"));
        btn_scrollArea->setGeometry(QRect(530, 110, 87, 27));
        btn_toolBox = new QPushButton(Widget);
        btn_toolBox->setObjectName(QString::fromUtf8("btn_toolBox"));
        btn_toolBox->setGeometry(QRect(530, 210, 87, 27));
        btn_tabWidget = new QPushButton(Widget);
        btn_tabWidget->setObjectName(QString::fromUtf8("btn_tabWidget"));
        btn_tabWidget->setGeometry(QRect(530, 310, 87, 27));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);
        tabWidget->setCurrentIndex(2);
        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_14->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_15->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_16->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "\347\231\276\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "\350\260\267\346\255\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Widget", "\345\255\227\350\212\202", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("Widget", "\345\256\266\344\272\272", nullptr));
        toolButton->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("Widget", "\346\234\213\345\217\213", nullptr));
        radioButton->setText(QCoreApplication::translate("Widget", "RadioButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("Widget", "\351\273\221\345\220\215\345\215\225", nullptr));
        btn_scrollArea->setText(QCoreApplication::translate("Widget", "scrollArea", nullptr));
        btn_toolBox->setText(QCoreApplication::translate("Widget", "toolBox", nullptr));
        btn_tabWidget->setText(QCoreApplication::translate("Widget", "tabWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
