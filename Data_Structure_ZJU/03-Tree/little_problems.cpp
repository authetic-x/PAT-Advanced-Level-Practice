//
// Created by authetic on 2019/4/13.
//

/*
 * 待解决：
 * 1. 堆栈遍历
 * 2. 给出前序和中序，构建树
 * 3. 两棵树是否同构
 */

#include <stdio.h>

typedef int ElementType;

struct TNode {
    ElementType data;
    TNode* left;
    TNode* right;
};

typedef TNode* BinTree;

// 后序遍历返回树的高度
int PostOrderGetHeight(BinTree BT) {
    int hl, hr, maxH;
    if (BT) {
        hl = PostOrderGetHeight(BT->left);
        hr = PostOrderGetHeight(BT->right);
        maxH = (hl > hr) ? hl : hr;
        return maxH+1;
    } else return 0;
}

int pre[10], in[10];

// 给出前序和中序遍历数组，构造出原二叉树
BinTree Create(int preL, int preR, int inL, int inR) {
    if (preL > preR) return nullptr;

    int root = pre[preL], k;
    for (k = inL; k <= inR; k ++ ) {
        if (in[k] == root) break;
    }
    BinTree lChild = Create(preL+1, preL+k-inL, inL, k-1);
    BinTree rChild = Create(preL+k-inL+1, preR, k+1, inR);
    BinTree head = new TNode;
    head->data = root;
    head->left = lChild;
    head->right = rChild;
    return head;
}