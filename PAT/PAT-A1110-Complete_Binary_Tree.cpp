//
// Created by authetic on 2018/12/28.
/*
 * 记住完全二叉树的性质，left = index*2, right = index*2 + 1;
 */
//

#include <iostream>
using namespace std;

struct Node {
    int id;
    int left, right;
}node[30];

int n, maxn = -1, last_node = -1;
bool isCompleteTree = true;

void isComplete(int i, int index) {
    if (index > maxn) {
        maxn = index;
        if (maxn == n) {
            last_node = i;
        }
    }
    if (node[i].left != -1) isComplete(node[i].left, index*2);
    if (node[i].right != -1) isComplete(node[i].right, index*2 + 1);
}

int main() {
    int root;
    cin >> n;
    int isRoot[30] = {0};
    for (int i = 0; i < n; i ++ ) {
        string a, b;
        cin >> a >> b;
        if (a == "-") {
            node[i].left = -1;
        } else {
            node[i].left = stoi(a);
            isRoot[node[i].left] = 1;
        }
        if (b == "-") {
            node[i].right = -1;
        } else {
            node[i].right = stoi(b);
            isRoot[node[i].right] = 1;
        }
    }
    for (int i = 0; i < n; i ++ ) {
        if (isRoot[i] == 0) root = i;
    }
    isComplete(root, 1);
    if (maxn == n) {
        cout << "YES" << " " << last_node;
    } else {
        cout << "NO" << " " << root;
    }
    return 0;
}