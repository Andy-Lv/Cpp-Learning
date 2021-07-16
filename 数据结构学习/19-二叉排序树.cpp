//
// Created by andy on 2021/7/16.
//

//左子树上所有节点的关键字均小于根节点的关键字
//右子树上所有节点的关键字均大于跟节点的关键字
//左子树和右子树又是一颗二叉排序树

typedef int ElemType;

typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTNode *BST_Search(BSTree T, int key)
{
    while (T != NULL && key != T->key)//若树空或等于根节点值，则结束循环
    {
        if (key < T.key)//小于，在左子树上查找
            T = T->lchild;
        else//大于，在右子树上查找
            T = T->rchild;
    }
    return T;
}

int BST_Insert(BSTree &T, int k)
{
    if (T == NULL)
    {
        T = (BSTree) malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    } else if (K == T->key)
    {
        return 0;
    } else if (k < T->key)
    {
        return BST_Insert(T->lchild, k);
    } else
    {
        return BST_Insert(T->rchild, k);
    }
}