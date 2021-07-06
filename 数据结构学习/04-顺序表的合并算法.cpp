//
// Created by andy on 2021/7/6.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITSIZE 10        // 顺序表的初始长度。
#define EXTSIZE   5        // 每次扩展元素的个数。
#define MAXSIZE 100 //顺序表的最大长度

typedef int ElemType;      // 自定义顺序表的数据元素为整数。

typedef struct
{
    ElemType *data;           // 存储顺序表中元素的首地址。
    unsigned int maxsize;     // 顺序表元素的最大长度。
    unsigned int length;      // 顺序表中元素的个数。
} SeqList, *PSeqList;

//采用归并算法,将两个升序的顺序表La和Lb,合并成一个升序的顺序表Lc
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc)
{
    if (La == NULL || Lb == NULL || Lc == NULL)
    {
        cout << "La,Lb,Lc至少有一个不存在" << endl;
        return 0;
    }

    if (MAXSIZE < La->length + Lb->length)
    {
        cout << "Lc的长度不够" << endl;
        return -1;
    }

    int istarta = 0;//表La的第一个元素位置
    int istartb = 0;//表Lb的第一个元素位置
    int istartc = 0;//表Lc的第一个元素位置

    //把La和Lb合并到Lc中
    while (istarta < La->length && istartb < Lb->length)
    {
        Lc->data[istartc++] = La->data[istarta] < Lb->data[istartb] ? La->data[istarta++] : Lb->data[istartb++];
    }

    //将La其他元素追加到Lc中
    while(istarta<La->length)
    {
        Lc->data[istartc++]=La->data[istarta++];
    }

    //将Lb其他元素追加到Lc中
    while(istartb<Lb->length)
    {
        Lc->data[istartc++]=Lb->data[istartb++];
    }

    Lc->length=La->length+Lb->length;

    return 1;
}