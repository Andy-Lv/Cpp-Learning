//
// Created by andy on 2021/7/14.
//

//栈(stack)是只允许在一端进行插入或删除操作的线性表

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 10

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];//静态数组中存放栈中的元素
    int top;//栈顶指针
} SqStack;

//初始化栈
void InitStack(SqStack &S)
{
    S.top = -1;//初始化栈顶指针
}

//判断栈空
bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}

//新元素入栈
bool Push(SqStack &S, ElemType x)
{
    if (S.top == MaxSize - 1)
        return false;//栈，满，报错

    S.top = S.top + 1;//指针先加1
    S.data[S.top] = x;//新元素入栈
    return true;
}

//出栈操作
bool Pop(SqStack &S,ElemType &x)
{
    if (S.top==-1)
        return false;//栈空，报错
    x=S.data[S.top];
    S.top=S.top-1;
    return true;
}

//读栈顶操作
bool GetTop(SqStack &S,ElemType &x)
{
    if (S.top==-1)
        return false;//栈空，报错
        x=S.data[S.top];
    return true;
}