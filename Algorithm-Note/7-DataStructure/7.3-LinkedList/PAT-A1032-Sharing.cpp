//
// Created by authetic on 2018/9/6.
/*
 * 静态链表
 */
//

#include <cstdio>

const int maxn = 100010;

struct Node {
    char data;
    int next;
    bool flag;
    Node() {
        flag = false;
    }
}node[maxn];

int main() {
    int s1,s2,n;
    scanf("%d %d %d", &s1, &s2, &n);
    char data;
    int addr, next;
    for (int i=0; i<n; i++) {
        scanf("%d %c %d", &addr, &data, &next);
        node[addr].data = data;
        node[addr].next = next;
    }
    int p;
    for (p=s1; p!=-1; p=node[p].next) {
        node[p].flag = true;
    }
    for (p=s2; p!=-1; p=node[p].next) {
        if (node[p].flag) break;
    }
    if (p!=-1) printf("%05d\n", p);
    else printf("-1\n");
    return 0;
}