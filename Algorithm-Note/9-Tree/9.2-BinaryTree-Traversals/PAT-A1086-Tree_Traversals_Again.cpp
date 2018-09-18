//
// Created by authetic on 2018/9/13.
/*
 * 给出中序遍历的模拟入栈过程，要求输出后序遍历数列
 * Note: 一开始看起来很麻烦，其实是间接的给出了前序遍历和中序遍历的数列，
 * 即入栈和出栈的过程，然后重构二叉树，后序输出即可！
 */
//

#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int maxn = 35;

int preOrder[maxn],inOrder[maxn];
int n;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

Node* create(int prel, int prer, int inl, int inr) {
    if (prel>prer) return NULL;
    Node* root = new Node;
    root->data = preOrder[prel];
    int k;
    for (k=inl; k<=inr; k++) {
        if (inOrder[k]==preOrder[prel]) break;
    }
    int numLeft = k-inl;
    root->lchild = create(prel+1, prel+numLeft, inl, k-1);
    root->rchild = create(prel+numLeft+1, prer, k+1, inr);
    return root;
}

int num=0;
void postTraversal(Node* root) {
    if (root!=NULL) {
        postTraversal(root->lchild);
        postTraversal(root->rchild);
        num++;
        printf("%d", root->data);
        if (num<n) printf(" ");
    }
}

int main() {
    scanf("%d", &n);
    stack<int> st;
    char str[6];
    int pre=1,in=1;
    for (int i=1; i<=2*n; i++) {
        scanf("%s", str);
        if (strcmp(str,"Push")==0){
            scanf("%d", &preOrder[pre++]);
            st.push(preOrder[pre-1]);
        } else {
            inOrder[in++] = st.top();
            st.pop();
        }
    }
    Node* root = create(1,n,1,n);
    postTraversal(root);
    return 0;
}