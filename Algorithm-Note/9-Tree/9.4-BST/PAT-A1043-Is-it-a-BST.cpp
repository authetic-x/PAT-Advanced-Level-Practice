//
// Created by authetic on 2018/9/16.
/*
 * 给定一段序列，判断是否是BST或者反转的BST的先序遍历序列
 * Note: 一开始做不知道怎么建树，这个题可以直接根据给定的序列
 * 建立BST(即假设该序列是二叉搜索树的先序遍历序列)，然后分别得
 * 出它的先序遍历和后序遍历序列(镜像的做法相同), 将得出的先序遍历
 * 序列与原序列对比即可！
 */
//

#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1010;

vector<int> origin,pre,preM,post,postM;

struct Node {
    int data;
    Node *lchild;
    Node *rchild;
};

void insert(Node* &root, int data) {
    if (root==NULL) {
        root = new Node;
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        return;
    }
    if (data<root->data) insert(root->lchild, data);
    else insert(root->rchild, data);
}
void preOrder(Node* root) {
    if (root==NULL) return;
    pre.push_back(root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}
void preMOrder(Node* root) {
    if (root==NULL) return;
    preM.push_back(root->data);
    preMOrder(root->rchild);
    preMOrder(root->lchild);
}
void postOrer(Node* root) {
    if (root==NULL) return;
    postOrer(root->lchild);
    postOrer(root->rchild);
    post.push_back(root->data);
}
void postMOrder(Node* root) {
    if (root==NULL) return;
    postMOrder(root->rchild);
    postMOrder(root->lchild);
    postM.push_back(root->data);
}

int main() {
    int n;
    scanf("%d", &n);
    Node *root = NULL;
    int temp;
    for (int i=0; i<n; i++) {
        scanf("%d", &temp);
        insert(root, temp);
        origin.push_back(temp);
    }
    preOrder(root);
    preMOrder(root);
    postOrer(root);
    postMOrder(root);
    if (origin==pre) {
        printf("YES\n");
        for (int i=0; i<post.size(); i++) {
            printf("%d", post[i]);
            if (i<post.size()-1) printf(" ");
        }
    } else if (origin==preM) {
        printf("YES\n");
        for (int i=0; i<postM.size(); i++) {
            printf("%d", postM[i]);
            if (i<postM.size()-1) printf(" ");
        }
    } else {
        printf("NO\n");
    }
    return 0;
}