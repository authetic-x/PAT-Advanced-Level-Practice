//
// Created by authetic on 2019/4/15.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct TNode {
    ElementType data;
    TNode* left;
    TNode* right;
};

typedef TNode* BinTree;

BinTree Find(ElementType X, BinTree BST) {
    if (BST == nullptr) return nullptr;
    if (BST->data == X) return BST;
    else if (BST->data > X) {
        return Find(X, BST->left);
    } else {
        return Find(X, BST->right);
    }
}

// 非递归实现
BinTree Find2(ElementType X, BinTree BST) {
    while (BST) {
        if (BST->data > X) {
            BST = BST->left;
        } else if (BST->data < X) {
            BST = BST->right;
        } else {
            return BST;
        }
    }
    return nullptr;
}

// 找到最小值
// 一直往左边找，找到一个没有左结点的结点为止
BinTree FindMin(BinTree BST) {
    if (!BST) return nullptr;
    if (!BST->left) return BST;
    else return FindMin(BST->left);
}

// 一直往右边找，找到一个没有右结点的结点为止
BinTree FindMax(BinTree BST) {
    if (BST) {
        while (BST->right) BST = BST->right;
    }
    return BST;
}

// BST的插入，关键是找到一个合适的空位置
BinTree Insert(ElementType X, BinTree BST) {
    if (!BST) {
        BST = (BinTree)malloc(sizeof(TNode));
        BST->data = X;
        BST->left = BST->right = nullptr;
    } else {
        if (X < BST->data) {
            BST = Insert(X, BST->left);
        } else if (X > BST->data) {
            BST = Insert(X, BST->right);
        }
    }
    return BST;
}

/*
 * BST的删除，注意返回结点的写法
 * 1. 如果该结点既有左子树又有右子树，
 *    则找到左子树的最大结点或者右子
 *    树的最小结点去替换该结点
 * 2. 如果该结点没有子树或只有一边有
 *    子树，直接删除或替换即可
 */
BinTree Delete(ElementType X, BinTree BST) {
    if (!BST) printf("No such node!");
    else if (BST->data > X) {
        BST->left = Delete(X, BST->left);
    } else if (BST->data < X) {
        BST->right = Delete(X, BST->right);
    } else {
        BinTree tmp;
        if (BST->left && BST->right) {
            tmp = FindMin(BST->right);
            BST->data = tmp->data;
            BST->right = Delete(tmp->data, BST->right);
        } else {
            tmp = BST;
            if (BST->left) {
                BST = BST->left;
            } else if (BST->right) {
                BST = BST->right;
            }
            free(tmp);
        }
    }
    return BST;
}

// 判断两个序列构建的BST是否相同，做麻烦了！
// 只用构建一棵树，然后依次查找第二个序列，
// 看有没有碰到过没检查的数
bool isSameBST(BinTree BST1, BinTree BST2) {
    if (BST1->data != BST2->data) return false;
    if ((!BST1 && BST2) || (BST1 && !BST2)) {
        return false;
    }
    return isSameBST(BST1->left, BST2->left) &&
            isSameBST(BST1->right, BST2->right);
}