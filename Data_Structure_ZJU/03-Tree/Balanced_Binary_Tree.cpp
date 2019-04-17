//
// Created by authetic on 2019/4/15.
//

/*
 * 平衡二叉树(AVL)：树高相差不超过1
 * 高度为h的平衡二叉树所需的最小结点数：
 *  N(h) = N(h-1) + N(h-2) + 1, N(0)=1, N(1) = 2
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct TNode {
    ElementType data;
    TNode* left;
    TNode* right;
};

typedef TNode* BinTree;

