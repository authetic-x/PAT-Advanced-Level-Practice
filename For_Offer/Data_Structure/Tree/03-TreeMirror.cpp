//
// Created by authetic on 2019/4/3.
//

/*
 * 二叉树的镜像
 * 前序遍历，依次交换左右子结点即可
 */

#include <iostream>
using namespace std;

struct Tree {
    int value;
    Tree* left;
    Tree* right;
};

void MirrorTree(Tree* node) {
    if (node == nullptr) return;
    if (node->left == nullptr && node->right == nullptr) return;

    Tree* tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    MirrorTree(node->left);
    MirrorTree(node->right);
}