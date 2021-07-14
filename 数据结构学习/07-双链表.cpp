//
// Created by andy on 2021/7/13.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;


typedef struct DNode{
    ElemType data;
    struct  DNode *prior,*next;
}DNode,*DLinklist;

bool InitDLinkList(DLinklist &L)
{
    L=(DNode *) malloc(sizeof (DNode));
    if(L==NULL)
        return false;
    L->prior=NULL;
    L->next=NULL;
    return true;
}

void testDLinkList()
{
    DLinklist L;
    InitDLinkList(L);
}

//在p节点之后插入s节点
bool InsertNextDNode(DNode *p,DNode *s)
{
    s->next=p->next;
    if (p->next!=NULL)
        p->next->prior=s;
    s->prior=p;
    p->next=s;
}

//删除p的后继节点q
bool DeleteNextDNode(DNode *p)
{
    if (p==NULL)
        return false;
    DNode *q=p->next;
    if (q==NULL)
        return false;

    p->next=q->next;
    q->prior=p;
    free(q);
    return true;
}

//删除整个节点
void DestoryList(DLinklist &L)
{
    while(L->next!=NULL)
        DeleteNextDNode(L);
    free(L);//释放头节点
    L=NULL;//头指针指向NULL
}