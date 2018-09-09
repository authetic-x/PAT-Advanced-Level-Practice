//
// Created by authetic on 2018/9/6.
/*
 * 反转链表
 * Note: 静态链表反转，先处理掉无效结点，处理边界时有点麻烦，
 * 写了不下四遍，自己写的将逻辑处理的太复杂，测试不能全部通过！
 */
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Node {
    int addr, data, next;
    int order;
    Node() {
        order = maxn;
    }
}temp[maxn],node[maxn];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    int head,n,k;
    int addr,data,next;

    scanf("%d %d %d", &head, &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d", &addr, &data, &next);
        node[addr].addr = addr;
        node[addr].data = data;
        node[addr].next = next;
    }

    n=0;
    int p=head;
    while (p!=-1) {
        node[p].order = n++;
        p = node[p].next;
    }
    sort(node, node+maxn, cmp);

    for (int i=0; i<n/k; i++) {
        for (int j=(i+1)*k-1; j>i*k; j--) {
            printf("%05d %d %05d\n", node[j].addr, node[j].data, node[j-1].addr);
        }
        printf("%05d %d ", node[i*k].addr, node[i*k].data);
        if (i<n/k-1) {
            printf("%05d\n", node[(i+2)*k-1].addr);
        } else {
            if (n%k==0) {
                printf("-1\n");
            } else {
                int pos = (i+1)*k;
                printf("%05d\n", node[pos].addr);
                for (int j=pos; j<n; j++) {
                    if (j<n-1) {
                        printf("%05d %d %05d\n", node[j].addr, node[j].data, node[j].next);
                    } else {
                        printf("%05d %d -1\n", node[j].addr, node[j].data);
                    }
                }
            }
        }
    }
    return 0;
}