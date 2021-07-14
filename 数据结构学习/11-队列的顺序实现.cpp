//
// Created by andy on 2021/7/14.
//

//队列是只允许在一段进行插入，在另一端删除的线性表
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 10

typedef int ElemType;

typedef  struct
{
    ElemType data[MaxSize];//用静态数组存放队列元素
    int front,rear;//队头指针和队尾指针
}SqQueue;

//初始化队列
void InitQueue(SqQueue &Q)
{
    //初始时，队头队尾指针指向0
    Q.rear=Q.front=0;
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
    if (Q.rear==Q.front)
        return true;
    else
        return false;
}

//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
    if (Q.rear==MaxSize-1)
        return false;
    Q.data[Q.rear]=x;//将x插入队尾
    Q.rear=Q.rear+1;//队尾指针后移
    return true;
}

//循环队列
//判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
    if(Q.rear==Q.front)//队空条件
        return true;
    else
        return false;
}

//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear+1)%MaxSize==Q.front)
        return false;//队满则报错
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q,ElemType x)
{
    if (Q.rear==Q.front)
        return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;//队头指针后移
    return true;
}

//获得队头元素的值，用x返回
bool GetHead(SqQueue Q,ElemType &x)
{
    if (Q.rear==Q.front)
        return false;//队空则报错
    x=Q.data[Q.front];
    return true;
}