//
// Created by authetic on 2018/9/6.
/*
 * 静态链表排序
 * Note: 写了很多遍的题目，还是会写错，少数的直接给很大的数组排序，
 * 排序加类似hash的题目
 */
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Node {
    int addr,data,next;
    bool flag;
    Node () {
        flag = false;
    }
}node[maxn];

bool cmp(Node a, Node b) {
    if (!a.flag || !b.flag) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main() {
    int n,head,count=0;
    scanf("%d %d", &n, &head);
    int addr,data,next;
    for (int i=0; i<n; i++) {
        scanf("%d %d %d", &addr, &data, &next);
        node[addr].addr = addr;
        node[addr].data = data;
        node[addr].next = next;
    }
    while (head!=-1) {
        count++;
        node[head].flag = true;
        head = node[head].next;
    }
    sort(node, node+maxn, cmp);
    if (count==0) {
        printf("0 -1\n");
    } else {
        printf("%d %05d\n", count, node[0].addr);
        for (int i=0; i<count; i++) {
            if (i!=count-1) {
                printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i+1].addr);
            } else {
                printf("%05d %d -1\n", node[i].addr, node[i].data);
            }
        }
    }
    return 0;
}