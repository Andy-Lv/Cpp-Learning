//
// Created by andy on 2021/7/14.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;

//单链表
typedef struct LNode{
    ElemType data;//每个节点存放一个数据元素
    struct  LNode *next;//指针指向下一个节点
}LNode,*Linklist;

//双链表
typedef struct DNode{
    ElemType data;
    struct  DNode *prior,*next;
}DNode,*DLinklist;

//初始化一个循环单链表
bool InitList(Linklist &L)
{
    L=(LNode *) malloc(sizeof (LNode));//分配一个头节点
    if(L==NULL)
        return false;//内存不足，分配失败
    L->next=L;
    return true;
}

//判断循环单链表是否为空
bool Empty(Linklist L)
{
    if (L->next==L)
        return true;
    else
        return false;
}

//判断节点P是否为循环单链表的表尾节点
bool isTail(Linklist L,LNode *p)
{
    if (p->next==L)
        return true;
    else
        return false;
}

//初始化空的循环双链表
bool InitDLinkList(DLinklist &L)
{
    L=(DNode *) malloc(sizeof (DNode));
    if (L==NULL)
        return false;
    L->prior=L;
    L->next=L;
    return true;
}

//判断循环双链表是否为空
bool Empty(DLinklist L)
{
    if (L->next==L)
        return true;
    else
        return false;
}

//在p节点之后插入s节点
bool InsertNextDNode(DNode *p,DNode *s)
{
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
}