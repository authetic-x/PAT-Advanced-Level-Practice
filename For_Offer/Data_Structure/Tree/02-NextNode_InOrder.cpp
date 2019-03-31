//
// Created by authetic on 2019/3/31.
//

/*
 * (!)给出二叉树的一个结点，求该结点在中序遍历下的下一个结点
 * keys: 画图分析，有右结点和无右结点，有右结点相对简单，
 * 即右子树的最深左结点；无右结点相对麻烦，向上遍历，想到
 * 找到该结点是其父结点左子结点的情况即可！
 */

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *left, *right, *parent;
};

Node* next_node(Node* node) {
    if (node == nullptr) return nullptr;
    Node* next = nullptr;
    if (node->right != nullptr) {
        Node* right = node->right;
        while (right != nullptr) {
            right = right->left;
        }
        next = right;
    } else if (node->parent != nullptr) {
        Node* nParent = node->parent;
        Node* nCurrent = node;
        while (nParent->parent != nullptr && nParent->right == nCurrent) {
            nCurrent = nParent;
            nParent = nParent->parent;
        }
        next = nParent;
    }
    return next;
}