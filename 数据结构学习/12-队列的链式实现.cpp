//
// Created by andy on 2021/7/14.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
};

typedef struct
{
    LinkNode *front,*rear;
}LinkQueue;

//初始化队列
void InitQueue(LinkQueue &Q)
{
    //初始时，front,rear都指向头节点
    Q.front=Q.rear=(LinkNode*) malloc(sizeof (LInkNode));
    Q.front->next=NULL;
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
    if (Q.front==Q.rear)
        return true;
    else
        return false;
}

//入队
void EnQueue(LinkQueue &Q,ElemType x)
{
    LinkNode *s=(LinkNode*) malloc(sizeof (LinkNode));
    s->data=x;
    s->next= NULL;
    Q.rear->next=s;
    Q.rear=s;
}

//队头元素出队
bool DeQueue(LinkQueue &Q,ElemType &x)
{
    if (Q.front==Q.rear)
        return false;//空队
    LinkNode *p=Q.front->next;
    x=p->data;//用变量x返回队头元素
    Q.front->next=p->next;//修改头节点next指针
    if(Q.rear==p)//最后一个节点出队
        Q.rear=Q.front;//修改rear指针
    free(p);//修改结点空间
    return true;
}