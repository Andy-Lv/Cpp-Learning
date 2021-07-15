//
// Created by andy on 2021/7/15.
//

typedef int ElemType;
#define MaxSize 100

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNOde *lchild, *rchild;
    int ltag, rtag;//左右线索标志
} ThreadNode, *ThreadTree;

ThreadNode *pre = NULL;//指向当前访问节点前驱

void visit(ThreadNode *q)
{
    if (q->lchild == NULL)//左子树为空，建立前驱线索
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q;//建立前驱节点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}

void PreThread(ThreadTree T)
{
    if (T != NULL)
    {

        visit(T);//访问跟节点
        if(T->rtag==0)//lchild不是前驱线索
            PreThread(T->lchild);//中序遍历左子树

        PreThread(T->rchild);//中序遍历右子树
    }
}

//中序线索化二叉树
void CreatPreThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)//非空二叉树才能线索化
    {
        PreThread(T);//先序线索化二叉树
        if (pre->rchild == NULL)
            pre->rtag = 1;//处理遍历的最后一个节点
    }
}