//
// Created by authetic on 2019/3/31.
//

/*
 * 给出前序遍历和中序遍历，重新构建树
 * keys: 思路是先找出根节点，然后根据中序遍历得出
 * 左子树长度和右子树长度，这样就可以递归构建树，关键
 * 是注意递归判断条件以及相关判断错误示例的语句！
 */

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* Construct_core(int* st_preOrder, int* ed_preOrder,
                     int* st_inOrder, int* ed_inOrder) {
    Node* root = new Node();
    int rootValue = st_preOrder[0];
    root->value = rootValue;
    root->left = nullptr, root->right = nullptr;

    int* root_inOrder = st_inOrder;
    while (root_inOrder <= st_inOrder) {
        if (*root_inOrder == rootValue) break;
        root_inOrder ++;
    }
    if (root_inOrder == ed_inOrder && *root_inOrder != rootValue) {
        // Exception
        return nullptr;
    }
    int length = root_inOrder - st_inOrder;
    int* leftPreOrderEd = st_preOrder + length;
    if (length > 0) {
        root->left = Construct_core(st_preOrder+1, leftPreOrderEd,
                                    st_inOrder, root_inOrder-1);
    }
    if (length < ed_preOrder - st_preOrder) {
        root->left = Construct_core(leftPreOrderEd+1, ed_preOrder,
                                    root_inOrder+1, ed_inOrder);
    }
    return root;
}

Node* construct(int *preOrder, int* inOrder, int len) {
    if (len <= 0 || preOrder == nullptr ||
        inOrder == nullptr) return nullptr;
    Node* tree = Construct_core(preOrder, preOrder+len-1,
                                inOrder, inOrder+len-1);
    return tree;
}