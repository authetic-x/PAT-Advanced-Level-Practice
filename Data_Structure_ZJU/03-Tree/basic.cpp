//
// Created by authetic on 2019/4/13.
//

/*
 * 树的概念：
 * 1. n个结点n-1条边
 * 2. 结点的度(Degree)：结点子树的个数
 * 3. 树的度：所有结点中最大的度数
 * 4. 结点的层次(Level)：根结点层次为1，其它结点依次加1
 * 5. 树的深度(Depth)：树中所有结点的最大层次
 * 6. n0表示叶结点的个数，n2度为2的结点个数
 *    则n0 = n2 + 1
 *    (从边的角度考虑，
 *     n0+n1+n2-1 = n0*0 + n1*1 + n2*2
 *
 * 完全二叉树顺序存储
 * 1. 结点i的父结点 = i/2
 * 2. 结点i的左子结点 = 2*i
 * 3. 结点i的右子结点 = 2*i+1
 */

#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

typedef int ElementType;

struct TNode {
    ElementType data;
    TNode* left;
    TNode* right;
};

typedef TNode* BinTree;

void PreOrderTraversal(BinTree BT) {
    if (BT) {
        printf("%d ", BT->data);
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }
}

void InOrderTraversal(BinTree BT) {
    if (BT) {
        InOrderTraversal(BT->left);
        printf("%d", BT->data);
        InOrderTraversal(BT->right);
    }
}

void PostOrderTraversal(BinTree BT) {
    if (BT) {
        PostOrderTraversal(BT->left);
        PostOrderTraversal(BT->right);
        printf("%d", BT->data);
    }
}

// 非递归中序遍历
// 前序和后序遍历？
void InOrderTraversal2(BinTree BT) {
    stack<BinTree> st;
    BinTree T = BT;
    while (T || !st.empty()) {
        while (T) {
            st.push(T);
            T = T->left;
        }
        if (!st.empty()) {
            BinTree top = st.top();
            printf("%d", top->data);
            T = top->right;
            st.pop();
        }
    }
}

void PostOrderTraversal2(BinTree BT) {
    stack<BinTree> st;
    BinTree T = BT;
    while (T || !st.empty()) {
        while (T) {
            st.push(T->left);
        }

    }
}

void LevelOrderTraversal(BinTree BT) {
    queue<BinTree> q;
    q.push(BT);
    while (!q.empty()) {
        BinTree T = q.front();
        q.pop();
        printf("%d", T->data);
        if (T->left) q.push(T->left);
        if (T->right) q.push(T->right);
    }
}