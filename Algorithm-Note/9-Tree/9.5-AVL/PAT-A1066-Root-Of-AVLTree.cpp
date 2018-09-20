//
// Created by authetic on 2018/9/19.
/*
 * 建立平衡二叉树
 * Note: 第一次做还是有点难，完全不会，也没有传说中的那么难，就是在建立搜索树的基础
 * 上加了“平衡”两个字，需要判断平衡因子，然后根据树的结构做左旋或者右旋，中间更新树的
 * 高度，在递归里写这么多东西还是有点复杂！
 */
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 25;

struct Node {
    int v, height;
    Node *lchild;
    Node *rchild;
} *root;

Node *newNoe(int v) {
    Node *node = new Node;
    node->v = v;
    node->height = 1;
    node->lchild = node->rchild = NULL;
    return node;
}

int getHeight(Node *root) {
    if (root == NULL) return 0;
    else return root->height;
}

void updateHeight(Node *root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(Node *root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(Node* &root) {
    Node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(Node* &root) {
    Node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void Insert(Node* &root, int v) {
    if (root == NULL) {
        root = newNoe(v);
        return;
    }
    if (v < root->v) {
        Insert(root->lchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild)==1) {
                R(root);
            } else {
                L(root->lchild);
                R(root);
            }
        }
    } else {
        Insert(root->rchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild)==-1) {
                L(root);
            } else {
                R(root->rchild);
                L(root);
            }
        }
    }
}

int main() {
    int n,v;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &v);
        Insert(root, v);
    }
    printf("%d\n", root->v);
    return 0;
}