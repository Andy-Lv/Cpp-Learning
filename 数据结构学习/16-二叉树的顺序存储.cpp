//
// Created by andy on 2021/7/15.
//

typedef int ElemType;
#define MaxSize 100

struct TreeNode
{
    ElemType value;//节点中的数据元素
    bool isEmpty;//节点是否为空
};

typedef struct BitNode
{
    ElemType data;//数据域
    struct BitNode *lchild, *rchild;//左右孩子指针
    struct BitNode *parent;//父节点指针
} BitNode, *BiTree;

typedef struct LinkNode
{
    static LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

//先序遍历
void PreOrder(BitNode T)
{
    if (T != NULL)
    {
        visit(T);
        PreOrder(T.lchild);
        PreOrder(T.rchild);
    }
}

//求树的深度
int treeDepth(BiTree T)
{
    if (T == NULL)
        return 0;
    else
    {
        int l = treeDepth(T.lchild);
        int r = treeDepth(T.rchild);
        return l > r ? l + 1 : r + 1;
    }
}

//层序遍历
void levelOrder(BiTree T)
{
    LinkQueue Q;
    BiTree p;
    EnQueue(Q, T);
    while (!isEmpty(Q))//将跟节点入队
    {
        DeQueue(Q, p);//队头节点出队
        visit(p);//访问出队节点
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);//左孩子入队

        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);//右孩子入队
    }
}