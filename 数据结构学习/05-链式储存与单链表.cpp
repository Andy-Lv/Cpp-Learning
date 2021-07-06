//
// Created by andy on 2021/7/6.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;//自定义链表数据元素为整数

typedef struct LNode
{
    ElemType data;//存放节点数据元素
    struct LNode *next;//只想下一个节点的指针
}LNode,*LinkList;

LinkList LL;//强调声明一个链表
LNode *node;//强调声明一个节点

