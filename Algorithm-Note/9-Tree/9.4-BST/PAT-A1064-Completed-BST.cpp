//
// Created by authetic on 2018/9/16.
/*
 * 给定一串序列，要求建立完全二叉搜索树，并层次遍历输出
 * Note: 自己开始的做法蠢到了极点，想排序后按位得出前序遍历的序列，
 * 然后建立二叉树，完全忽略了完全二叉树的特性，左子节点的父节点*2，
 * 这样可以直接模拟完全二叉搜索树的中序遍历过程，将排序的序列依次填入
 * ，然后存放树的数组就是二叉搜索树的层次遍历序列！
 */
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int num[maxn],CBT[maxn];
int n,index=0;

void inOrder(int root) {
    if (root>n) return;
    inOrder(2*root);
    CBT[root] = num[index++];
    inOrder(2*root+1);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &num[i]);
    }
    sort(num, num+n);
    inOrder(1);
    for (int i=1; i<=n; i++) {
        printf("%d", CBT[i]);
        if (i<n) printf(" ");
    }
    return 0;
}