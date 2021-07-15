//
// Created by andy on 2021/7/15.
//
#define MAXLEN 255

typedef struct
{
    char ch[MAXLEN];//每个分量储存一个字符
    int length;//串的实际长度

} SString;

void get_next(SString T, int next[],int nextval[])
{
    int i = 1, j = 0;
    next[1] = 0;
    nextval[1]=0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        } else
        {
            j=next[j];
        }
    }
    for (int j = 2; j < =T.length; ++j)
    {
        if  (T.ch[next[j]]==T.ch[j])
            nextval[j]=nextval[next[j]];
        else
            nextval[j]=next[j];
    }
}

int Index_KMP(SString S, SString T, int next[])
{
    int i = 1, j = 1;
    int next[T.length + 1];
    int nextval[T.length + 1];
    get_next(T,next,nextval);

    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;//继续比较后面字符
        } else
        {
            j = next[j];//模式串向后移动
        }
    }
    if (j > T.length)
    {
        return i - T.length;//匹配成功
    } else
    {
        return false;
    }
}