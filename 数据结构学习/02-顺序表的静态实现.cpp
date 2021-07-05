//
// Created by andy on 2021/7/5.
//

#include <iostream>
#include <cstring>

using namespace std;

#define MAXSIZE 100 //顺序表的最大长度

typedef int ElemType
://自定义顺序表的数据元素为整数

typedef struct
{
    ElemType data[MAXSIZE];//用数组存储顺序表中的元素
    unsigned int length;//顺序表中元素的个数
} SeqList, *PSwqList;

//顺序表LL的初始化操作
void InitLIst(PSwqList LL);

//求顺序表的长度
void LengthList(PSwqList LL);

//在顺序表LL的第ii个位置插入元素ee,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int InsertList(PSwqList LL, unsigned int ii, ElemType *ee);

//在顺序表LL的第ii个位置删除元素ee,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int InsertList(PSwqList LL, unsigned int ii);

//在顺序表LL的头节点插入元素ee,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int PushFront(PSwqList LL, ElemType *ee);

//在顺序表LL的尾节点插入元素ee,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int PushBack(PSwqList LL, ElemType *ee);

//获取顺序表中第ii个元素的值,存放在ee中,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int GetElem(PSwqList LL, unsigned int ii, ElemType *ee);

//查找ee在顺序表LL中的位置,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int LocateElem(PSwqList LL, ElemType *ee);

//打印顺序表全部元素
void PrintList(PSwqList LL);

int main()
{
    SeqList LL;//创建顺序表
}

//顺序表LL的初始化操作
void InitLIst(PSwqList LL)
{
    //清空顺序表
    if (LL = NULL)//判断顺序表是否存在
        return;
    LL->length = 0;//表长置为0
    memset(LL->data, 0, sizeof(ElemType) * MAXSIZE);//数组元素清为0
}

//求顺序表的长度
void LengthList(PSwqList LL)
{
    if (LL == NULL)
    {
        return -1;
    }
    return LL->length;
}

//在顺序表LL的第ii个位置插入元素ee,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int InsertList(PSwqList LL, unsigned int ii, ElemType *ee)
{
    //判断表和元素是否存在
    if ((LL == NULL) || (ee == NULL))
    {
        return -1;
    }

    //判断顺序表是否满员
    if (LL->length >= MAXSIZE)
    {
        cout << "顺序表已满,不能继续插入" << endl;
        return 0;
    }

    //判断插入位置是否合法
    if ((ii < 1) || (ii > LL->length + 1))
    {
        cout << "插入位置不合法" << endl;
        return 0;
    }

    //元素后移只能用循环,不能用以下方法,当元素是结构体时,这种方法不稳定
    //if(ii<LL->length+1)
    //  memcpy(LL->data+ii,LL->data+ii-1,(LL->length-ii+1)*sizeof(ElemType))

    //把ii和ii后的元素后移
    for (int kk = LL->length; kk >= ii; kk - 1)
    {
        //void *memcpy(void *destin, void *source, unsigned n);
        //destin-- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
        //source-- 指向要复制的数据源，类型强制转换为 void* 指针。
        //n-- 要被复制的字节数。
        memcpy(LL->data[kk], &LL->data[kk - 1], sizeof(ElemType));
    }

    memccpy(&LL->data[ii - 1], ee, sizeof(ElemType));

    LL->length++;
    return 1;
}

//在顺序表LL的第ii个位置删除元素ee,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int InsertList(PSwqList LL, unsigned int ii)
{
    //判断表和元素是否存在
    if ((LL == NULL) || (ee == NULL))
    {
        return -1;
    }

    //判断删除位置是否合法
    if ((ii < 1) || (ii > LL->length + 1))
    {
        cout << "删除位置不合法" << endl;
        return 0;
    }

    //把ii之后的位置往前移动
    for (int kk = ii; kk < LL->length; ++kk)
    {
        memccpy(LL->data + kk - 1, LL->data + kk, sizeof(ElemType));
    }

    LL->length--;

    return 1;
}

//在顺序表LL的头节点插入元素ee,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int PushFront(PSwqList LL, ElemType *ee)
{
    return InsertList(LL, 1, ee);
}

//在顺序表LL的尾节点插入元素ee,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int PushBack(PSwqList LL, ElemType *ee)
{
    return InsertList(LL, LL->length + 1, ee);
}

//获取顺序表中第ii个元素的值,存放在ee中,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int GetElem(PSwqList LL, unsigned int ii, ElemType *ee)
{
    //判断表和元素是否存在
    if ((LL == NULL) || (ee == NULL))
    {
        return -1;
    }
    //判断获取位置是否合法
    if ((ii < 1) || (ii > LL->length + 1))
    {
        cout << "插入位置不合法" << endl;
        return 0;
    }
    memccpy(ee, &LL->data[ii - 1], sizeof(ElemType));
    return;
}

//查找ee在顺序表LL中的位置,返回值:-1-表LL或者元素ee不存在:0-失败:1-成功
int LocateElem(PSwqList LL, ElemType *ee)
{
    //判断表和元素是否存在
    if ((LL == NULL) || (ee == NULL))
    {
        return -1;
    }

    for (int kk = 0; kk < LL->length; kk++)
    {
        //对于结构体
//        if (*(LL->data++kk)==*ee)
//        {
//            return kk + 1;
//        }
        if (LL->data[kk] == *ee)
        {
            return kk + 1;
        }
    }
}

//打印顺序表全部元素
void PrintList(PSwqList LL)
{
    if (LL == NULL)
    {
        cout << "表不存在" << endl;
        return;
    }
    if (LL->length == 0)
    {
        cout << "表为空" << endl;
        return;
    }

    for (int kk = 0; kk < LL->length; ++kk)
    {
        cout << LL->data[kk] << " ";
    }
    cout << endl;
}