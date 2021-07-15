//
// Created by andy on 2021/7/15.
//

#define MAXLEN 255

//串的顺序存储

//静态数组实现
typedef struct
{
    char ch[MAXLEN];//每个分量储存一个字符
    int length;//串的实际长度

} SString;

//动态数组实现
typedef struct
{
    char *ch;//每个分量储存一个字符
    int length;//串的实际长度

} HString;

//串的链式存储

typedef struct StringNode
{
    char ch*;//每个节点存储一个字符
    struct StringNode *next;
} StringNode, *String;

//求子串
bool SubString(SString &Sub, SString S, int pos, int len)
{
    //子串范围越界
    if (pos + len - 1 > S.length)
        return false;
    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.length = len;
}

//比较操作。若S>T，则返回值>0,若S=T，则返回值=0,若S<T，则返回值<0
int StrCompare(SString S, SString T)
{
    for (int i = 1; i < S.length && i < T.length; ++i)
    {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    //扫描过所有字符都相同，则长度长的串更大
    return S.length - T.length;
}

//定位操作，若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置，否则函数值为0
int Index(SString S,SString T)
{
    int i=1,n=S.length,m=T.length;
    SString sub;
    while(i<=n-m+1)
    {
        SubString(sub,S,i,m);
        if  (StrCompare(sub,T)!=0)
            ++i;
        else
            return i;
    }
}