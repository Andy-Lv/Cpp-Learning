#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodname)
{
    //直接打印会出现引号，想要不出现引号需要先转换为QByteArray(toutf8)，再转换为char*
    qDebug()<<"请老师吃"<<foodname.toUtf8().data();
}
