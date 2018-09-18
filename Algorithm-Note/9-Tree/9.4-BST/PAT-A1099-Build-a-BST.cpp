//
// Created by authetic on 2018/9/16.
/*
 * 给出二叉搜索树的结构，给定一段序列，要求不破坏树的结构填入序列，然后层次遍历输出
 * Note: 依旧是利用中序遍历依次填入排好序的序列，这里用静态二叉树，然后层次遍历一下就行，
 * 目前为止，由于二叉搜索树的特性，可以用两种方法直接建树，一种是前序遍历，空位插入，
 * 另一种是中序遍历，前提要有树的结构或者是完全二叉树，填入排好序的序列！
 */
//

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110;

struct Node {
    int data,lchild,rchild;
}node[maxn];

int n,num[maxn],index=0;

void inOrder(int root) {
    if (root==-1) return;
    inOrder(node[root].lchild);
    node[root].data = num[index++];
    inOrder(node[root].rchild);
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    int num=0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        printf("%d", node[front]);
        num++;
        if (num<n) printf(" ");
        if (node[front].lchild!=-1) q.push(node[front].lchild);
        if (node[front].rchild!=-1) q.push(node[front].rchild);
    }
}

int main() {
    scanf("%d", &n);
    int l,r;
    for (int i=0; i<n; i++) {
        scanf("%d %d", &l, &r);
        node[i].lchild = l;
        node[i].rchild = r;
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &num[i]);
    }
    sort(num,num+n);
    inOrder(0);
    BFS(0);
    return 0;
}