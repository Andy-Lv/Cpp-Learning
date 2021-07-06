//
// Created by andy on 2021/7/7.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef int ElemType;     // 自定义链表的数据元素为整数

typedef struct LNode
{
    ElemType data;       // 存放节点的数据元素
    struct LNode *next;  // 指向下一个节点的指针
}LNode,*LinkList;

//初始化链表LL,返回值:失败返回NULL,成功返回头节点的地址
LNode *InitList()
{
    LNode *head=(LNode *) malloc(sizeof (LNode));

    if(head==NULL)
    {
        return NULL;
    }
    head->next=NULL;

    return head;
}

//传入指针变量的地址的方法
//初始化链表,返回值:0-失败:1-成功
int InitList2(LinkList *LL)
{
    if(*LL!=NULL)
    {
        cout<<"该链表已经是一个非空链表"<<endl;
        return 0;
    }

    LNode *head=(LNode *) malloc(sizeof (LNode));

    if(head==NULL)
    {
        return 0;
    }

    head->next=NULL;

    *LL=head;

    return 1;
}

// C++????????????Linux????????g++????
// ????????????????0-????1-?????
// int InitList3(LinkList &LL);

// 销毁链表
void DestroyList1(LinkList LL)
{
    LNode *tmp;

    while (LL!=NULL)
    {
        tmp=LL->next;
        free(LL);
        LL=tmp;
    }

    return;
}

// 传入指针的方法销毁链表
void DestroyList2(LinkList *LL)
{
    LNode *tmp1,*tmp2;
    tmp1=*LL;

    while (tmp1!=NULL)
    {
        tmp2=tmp1->next;
        free(temp1);
        tmp1=tmp2;
    }

    *LL=NULL;

    return;
}

// 传入指针地址的方法
// void DestroyList3(LinkList &LL);

// 清空链表
void ClearList(LinkList LL)
{
    if (LL==NULL)
    {
        cout<<"该链表不存在"<<endl;
        return;
    }

    LNode *tmp1;
    LNode *tmp2=LL->next;

    while (tmp2!=NULL)
    {
        tmp1=tmp2->next;
        free(tmp2);
        tmp2=tmp1;
    }

    LL->next=NULL;

    return;
}

// 在链表LL的ii个位置插入元素ee
int  InsertList(LinkList LL, unsigned int ii, ElemType *ee)
{
    if ( (LL == NULL) || (ee == NULL) )
    {
        cout<<"链表为空或者插入元素错误"<<endl;
        return 0;
    }

    if (ii<1)
    {
        cout<<"插入位置不合法"<<endl;
        return 0;
    }

    LNode *pp=LL;
    int kk=0;

    while((pp!=NULL)&&(kk<ii-1))
    {
        pp=pp->next;
        kk++;
    }

    if(pp==NULL)
    {
        cout<<"链表结束"<<endl;
    }

    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    if (tmp == NULL)
    {
        return 0;
    }

    memcpy(&tmp->data,ee,sizeof(ElemType));

    tmp->next=pp->next;
    pp->next=tmp;

    return 1;
}

// 打印链表中元素
void PrintList(LinkList LL)
{
    if (LL == NULL) { printf("????LL???????\n"); return; } // ?§?????????????

    LNode *pp=LL->next;
    while (pp != NULL)
    {
        printf("%-3d", pp->data);
        pp=pp->next;
    }

    printf("\n");
}

// 在链表头部插入元素ee
int  PushFront(LinkList LL, ElemType *ee)
{
    return InsertList(LL,1,ee);
}

// 在链表尾部插入元素ee
int  PushBack(LinkList LL, ElemType *ee)
{
    if ( (LL == NULL) || (ee == NULL) )
    {
        cout<<"链表为空或者插入元素错误"<<endl;
        return 0;
    }

    LNode *pp=LL;

    while (pp->next!=NULL)
    {
        pp=pp->next;
    }

    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    if (tmp == NULL) return 0;

    memcpy(&tmp->data,ee,sizeof(ElemType));

    tmp->next=NULL;
    pp->next=tmp;

    return 1;
}

// 删除链表LL中的第ii个节点
int  DeleteNode(LinkList LL, unsigned int ii)
{
    if(LL==NULL)
    {
        cout<<"该链表不存在"<<endl;
    }

    if(ii<1)
    {
        cout<<"选择的节点不合法"<<endl;
    }

    LNode *pp=LL;
    int kk=0;

    while( (pp != NULL) && (kk < ii-1) )
    {
        pp=pp->next;
        k++;
    }

    if ( pp->next==NULL )
    {
        cout<<"节点已经到末尾"<<endl;
    }

    LNode *tmp=pp->next;
    pp->next=tmp->next;

    free(tmp);

    return 1;
}

// 删除链表第一个节点
int PopFront(LinkList LL)
{
    return DeleteNode(LL, 1);
}

// 删除链表最后一个节点
int PopBack(LinkList LL)
{
    if (LL == NULL)
    {
        cout<<"链表为空或者插入元素错误"<<endl;
        return 0;
    }

    LNode *pp=LL;

    while (pp->next->next!=NULL)
    {
        pp=pp->next;
    }

    free(pp->next);
    pp->next=NULL;

    return 1;
}

// 求链表的长度
int  LengthList(LinkList LL)
{
    if (LL == NULL)
    {
        cout<<"链表为空或者插入元素错误"<<endl;
        return 0;
    }

    LNode *pp=LL->next;

    int length=0;
    while(pp!=NULL)
    {
        pp=pp->next;
        length++;
    }

    return length;
}

// 判断链表是否为空
int IsEmpty(LinkList LL)
{
    if (LL == NULL) return 0;

    if (LL->next == NULL) return 1;

    return 0;
}

//获取ee在链表中第ii个节点
LNode *LocateNode(LinkList LL, unsigned int ii)
{
    if (LL == NULL)
    {
        cout<<"链表为空或者插入元素错误"<<endl;
        return 0;
    }

    LNode *pp=LL;
    int kk=0;

    while ((pp != NULL) && (kk < ii))
    {
        pp=pp->next;
        kk++;
    }

    if ( pp==NULL )
    {
        cout<<"未找到"<<endl;
    }

    return pp;
}

//查找元素ee在链表LL中节点的地址
LNode *LocateElem(LinkList LL, ElemType *ee)
{
    LNode *pp=LL->next;

    while (pp != NULL)
    {

        if (pp->data == *ee) return pp;

        pp = pp->next;
    }

    return NULL;
}

// 在指定pp之后插入元素ee
int InsertNextNode(LNode *pp, ElemType *ee)
{
    if (LL == NULL)
    {
        cout<<"链表为空或者插入元素错误"<<endl;
        return 0;
    }

    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    if (tmp == NULL) return 0;

    memcpy(&tmp->data,ee,sizeof(ElemType));
    tmp->next=pp->next;
    pp->next=tmp;

    return 1;
}

// 在指定节点pp之前插入元素ee
int InsertPriorNode(LNode *pp, ElemType *ee)
{
    if (LL == NULL)
    {
        cout<<"链表为空或者插入元素错误"<<endl;
        return 0;
    }

    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    if (tmp == NULL) return 0;

    memcpy(&tmp->data,&pp->data,sizeof(ElemType));
    tmp->next=pp->next;

    memcpy(&pp->data,ee,sizeof(ElemType));
    pp->next=tmp;

    return 1;
}

// 删除指定节点
int DeleteNode1(LNode *pp)
{
    if (LL == NULL)
    {
        cout<<"链表为空或者插入元素错误"<<endl;
        return 0;
    }

    LNode *tmp=pp->next;  // tmp???pp??????
    memcpy(&pp->data,&tmp->data,sizeof(ElemType)); // ???????????????pp????§??
    pp->next=tmp->next;   // ??pp??next????????next??
    free(tmp);  // ???????

    return 1;
}

// 采用归并的方法将两个升序的链表La和Lb,合并成为一个升序的链表Lc
int MergeList(LinkList La,LinkList Lb,LinkList Lc)
{
    if ( (La == NULL) || (Lb == NULL) || (Lc == NULL) )
    {
        printf("某一个链表为空\n");
        return 0;
    }

    La=La->next;
    Lb=Lb->next;

    LNode *pp;

    while ( (La != NULL) && (Lb != NULL) )
    {
        if (La->data <= Lb->data)
        {
            pp=La; La=La->next;
        }
        else
        {
            pp=Lb; Lb=Lb->next;
        }


        Lc->next=(LNode *)malloc(sizeof(LNode));  // ???????????
        Lc=Lc->next;
        memcpy(&Lc->data,&pp->data,sizeof(ElemType));
        Lc->next=NULL;
}

void ReverseList(LNode *pp)
{
    LNode *ss;      // ??????
    LNode *ssnext;  // ?????????????

    ss=pp->next;    // ??pp???????????????

    pp->next=NULL;  // pp->next?????

    while (ss != NULL)
    {
        ssnext=ss->next;  // ????ss???????????

        // ??????????????pp??????ss???
        ss->next=pp->next;
        pp->next=ss;

        ss=ssnext;  // ss???????
    }
}