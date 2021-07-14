//
// Created by andy on 2021/7/14.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;

#define MaxSize 10//静态链表的最大长度

struct Node//静态链表结构类型的定义
{
    ElemType data;//储存数据元素
    int next;//下一个元素的数组下标
} SLinkList[MaxSize];

void testSLinkList()
{
    struct Node a[MaxSize];//数组a为静态链表
}