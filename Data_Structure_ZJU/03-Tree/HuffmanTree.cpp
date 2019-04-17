//
// Created by hp on 2019/4/17.
//

/*
 * Huffman Tree:
 * 在一个有序序列中，每次选择最小的两个元素构建二叉树，
 * 结点的权值为两个子结点的权值之和，并将新结点的权值
 * 加入到原序列中！
 * 1. 若叶结点数为n，则总结点数为2*n-1
 * 2. 哈夫曼树不存在度为1的结点
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int weight;
    TreeNode* left;
    TreeNode* right;
};

typedef TreeNode* ElementType;

typedef TreeNode* HuffmanTree;

struct HeapStruct {
    ElementType *Elements;
    int Size;
    int Capacity;
};

typedef struct HeapStruct *MinHeap;

ElementType DeleteMin(MinHeap H);

void Insert(MinHeap H, ElementType item);

// 利用最小堆创建哈夫曼树
HuffmanTree Huffman(MinHeap H) {
    HuffmanTree T;
    for (int i = 1; i < H->Size; i ++ ) {
        T = (TreeNode*)malloc(sizeof(TreeNode));
        T->left = DeleteMin(H);
        T->right = DeleteMin(H);
        T->weight = T->left->weight + T->right->weight;
        Insert(H, T);
    }
    T = DeleteMin(H);
    return T;
}