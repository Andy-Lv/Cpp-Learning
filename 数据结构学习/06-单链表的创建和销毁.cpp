//
// Created by andy on 2021/7/7.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef int ElemType;     // �Զ������������Ԫ��Ϊ����

typedef struct LNode
{
    ElemType data;       // ��Žڵ������Ԫ��
    struct LNode *next;  // ָ����һ���ڵ��ָ��
}LNode,*LinkList;

//��ʼ������LL,����ֵ:ʧ�ܷ���NULL,�ɹ�����ͷ�ڵ�ĵ�ַ
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

//����ָ������ĵ�ַ�ķ���
//��ʼ������,����ֵ:0-ʧ��:1-�ɹ�
int InitList2(LinkList *LL)
{
    if(*LL!=NULL)
    {
        cout<<"�������Ѿ���һ���ǿ�����"<<endl;
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

// ��������
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

// ����ָ��ķ�����������
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

// ����ָ���ַ�ķ���
// void DestroyList3(LinkList &LL);

// �������
void ClearList(LinkList LL)
{
    if (LL==NULL)
    {
        cout<<"����������"<<endl;
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

// ������LL��ii��λ�ò���Ԫ��ee
int  InsertList(LinkList LL, unsigned int ii, ElemType *ee)
{
    if ( (LL == NULL) || (ee == NULL) )
    {
        cout<<"����Ϊ�ջ��߲���Ԫ�ش���"<<endl;
        return 0;
    }

    if (ii<1)
    {
        cout<<"����λ�ò��Ϸ�"<<endl;
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
        cout<<"�������"<<endl;
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

// ��ӡ������Ԫ��
void PrintList(LinkList LL)
{
    if (LL == NULL) { printf("????LL???????\n"); return; } // ?��?????????????

    LNode *pp=LL->next;
    while (pp != NULL)
    {
        printf("%-3d", pp->data);
        pp=pp->next;
    }

    printf("\n");
}

// ������ͷ������Ԫ��ee
int  PushFront(LinkList LL, ElemType *ee)
{
    return InsertList(LL,1,ee);
}

// ������β������Ԫ��ee
int  PushBack(LinkList LL, ElemType *ee)
{
    if ( (LL == NULL) || (ee == NULL) )
    {
        cout<<"����Ϊ�ջ��߲���Ԫ�ش���"<<endl;
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

// ɾ������LL�еĵ�ii���ڵ�
int  DeleteNode(LinkList LL, unsigned int ii)
{
    if(LL==NULL)
    {
        cout<<"����������"<<endl;
    }

    if(ii<1)
    {
        cout<<"ѡ��Ľڵ㲻�Ϸ�"<<endl;
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
        cout<<"�ڵ��Ѿ���ĩβ"<<endl;
    }

    LNode *tmp=pp->next;
    pp->next=tmp->next;

    free(tmp);

    return 1;
}

// ɾ�������һ���ڵ�
int PopFront(LinkList LL)
{
    return DeleteNode(LL, 1);
}

// ɾ���������һ���ڵ�
int PopBack(LinkList LL)
{
    if (LL == NULL)
    {
        cout<<"����Ϊ�ջ��߲���Ԫ�ش���"<<endl;
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

// ������ĳ���
int  LengthList(LinkList LL)
{
    if (LL == NULL)
    {
        cout<<"����Ϊ�ջ��߲���Ԫ�ش���"<<endl;
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

// �ж������Ƿ�Ϊ��
int IsEmpty(LinkList LL)
{
    if (LL == NULL) return 0;

    if (LL->next == NULL) return 1;

    return 0;
}

//��ȡee�������е�ii���ڵ�
LNode *LocateNode(LinkList LL, unsigned int ii)
{
    if (LL == NULL)
    {
        cout<<"����Ϊ�ջ��߲���Ԫ�ش���"<<endl;
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
        cout<<"δ�ҵ�"<<endl;
    }

    return pp;
}

//����Ԫ��ee������LL�нڵ�ĵ�ַ
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

// ��ָ��pp֮�����Ԫ��ee
int InsertNextNode(LNode *pp, ElemType *ee)
{
    if (LL == NULL)
    {
        cout<<"����Ϊ�ջ��߲���Ԫ�ش���"<<endl;
        return 0;
    }

    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    if (tmp == NULL) return 0;

    memcpy(&tmp->data,ee,sizeof(ElemType));
    tmp->next=pp->next;
    pp->next=tmp;

    return 1;
}

// ��ָ���ڵ�pp֮ǰ����Ԫ��ee
int InsertPriorNode(LNode *pp, ElemType *ee)
{
    if (LL == NULL)
    {
        cout<<"����Ϊ�ջ��߲���Ԫ�ش���"<<endl;
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

// ɾ��ָ���ڵ�
int DeleteNode1(LNode *pp)
{
    if (LL == NULL)
    {
        cout<<"����Ϊ�ջ��߲���Ԫ�ش���"<<endl;
        return 0;
    }

    LNode *tmp=pp->next;  // tmp???pp??????
    memcpy(&pp->data,&tmp->data,sizeof(ElemType)); // ???????????????pp????��??
    pp->next=tmp->next;   // ??pp??next????????next??
    free(tmp);  // ???????

    return 1;
}

// ���ù鲢�ķ������������������La��Lb,�ϲ���Ϊһ�����������Lc
int MergeList(LinkList La,LinkList Lb,LinkList Lc)
{
    if ( (La == NULL) || (Lb == NULL) || (Lc == NULL) )
    {
        printf("ĳһ������Ϊ��\n");
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