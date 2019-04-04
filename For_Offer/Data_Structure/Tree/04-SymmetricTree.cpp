//
// Created by authetic on 2019/4/3.
//

/*
 * 判断二叉树是否是对称二叉树
 * 模拟前序遍历的不同方式
 */

#include <iostream>
using namespace std;

struct Tree {
    int value;
    Tree* left;
    Tree* right;
};

bool isSymmetrical(Tree* root1, Tree* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;
    if (root1->value != root2->value) return false;

    return isSymmetrical(root1->left, root2->right) &&
            isSymmetrical(root1->right, root2->left);
}

bool Symmetrical(Tree* head) {
    return isSymmetrical(head->left, head->right);
}