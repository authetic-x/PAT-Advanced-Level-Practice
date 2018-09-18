//
// Created by authetic on 2018/9/13.
/*
 * 二叉树后序遍历加中序遍历重新构造树
 * Note: 一开始将postOrder看成了preOrder，以为是前序遍历，写法上与前序遍历几乎
 * 一样，确定根结点和左右子树个数，一次进行递归，然后进行层序遍历输出即可！
 */
//

#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 35;

struct Node {
    int data;
    Node *lchild;
    Node *rchild;
};

int preOrder[maxn];
int inOrder[maxn];

Node* create(int prel, int prer, int inl, int inr) {
    if (prel>prer) return NULL;
    Node *root = new Node;
    root->data = preOrder[prer];
    int k;
    for (k=inl; k<=inr; k++) {
        if (inOrder[k]==preOrder[prer]) break;
    }
    int numLeft = k-inl;
    root->lchild = create(prel,prel+numLeft-1,inl,k-1);
    root->rchild = create(prel+numLeft,prer-1,k+1,inr);
    return root;
}

void layTraversal(Node* root, int num) {
    queue<Node*> q;
    if (root!=NULL) q.push(root);
    int n=1;
    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        if (n!=num) printf("%d ", front->data);
        else printf("%d\n", front->data);
        n++;
        if (front->lchild!=NULL) q.push(front->lchild);
        if (front->rchild!=NULL) q.push(front->rchild);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &preOrder[i]);
    }
    for (int i=1; i<=n; i++) {
        scanf("%d", &inOrder[i]);
    }
    Node* root = create(1,n,1,n);
    layTraversal(root, n);
    return 0;
}