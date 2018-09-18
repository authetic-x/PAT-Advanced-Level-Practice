//
// Created by authetic on 2018/9/13.
/*
 * 一行行的给出结点的左右子结点，要求反转二叉树，并且层次遍历和中序遍历的输出该二叉树
 * Note: 因为按点给出二叉树，用静态二叉树会比较方便，只需找出根结点即可，用一个bool数组
 * 标记，然后遍历找出根结点，反转看起来很难，其实只是一个后序遍历的过程，然后层次遍历和中序遍历
 * 几乎一样，只是将地址改为int，最后记住一点，不要去试图看清递归的每一个过程，理解递归的作用，
 * 将大问题缩小，感受递归式和递归边界！
 */
//

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 20;

struct Node {
    int lchild,rchild;
}node[maxn];

int n,num=0;
bool notRoot[maxn] = {false};

void print(int root) {
    num++;
    if (num<n) printf("%d ", root);
    else printf("%d\n", root);
}

void postOrder(int root) {
    if (root==-1) return;
    postOrder(node[root].lchild);
    postOrder(node[root].rchild);
    int temp = node[root].lchild;
    node[root].lchild = node[root].rchild;
    node[root].rchild = temp;
}

void inOrder(int root) {
    if (root==-1) return;
    inOrder(node[root].lchild);
    print(root);
    inOrder(node[root].rchild);
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        print(front);
        if (node[front].lchild!=-1) q.push(node[front].lchild);
        if (node[front].rchild!=-1) q.push(node[front].rchild);
    }
}

int strToNum(char c) {
    if (c=='-') return -1;
    else {
        notRoot[c-'0'] = true;
        return c-'0';
    }
}

int findRoot() {
    for (int i=0; i<n; i++) {
        if (!notRoot[i]) return i;
    }
}

int main() {
    char lchild,rchild;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%*c%c %c", &lchild, &rchild);
        node[i].lchild = strToNum(lchild);
        node[i].rchild = strToNum(rchild);
    }
    int root = findRoot();
    postOrder(root);
    BFS(root);
    num=0;
    inOrder(root);
    return 0;
}