//
// Created by authetic on 2018/10/9.
/*
 * 最小生成树，Kruskal算法
 */
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Edge {
    int u,v;
    int cost;
}ed[maxn];

int father[maxn],m,n;

bool cmp(Edge a, Edge b) {
    return a.cost < b.cost;
}

int findFather(int n) {
    int a = n;
    while (n != father[n]) {
        n = father[n];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = n;
    }
    return n;
}

int Kruskal() {
    int ans=0,numEdge=0;
    for (int i=0; i<n; i++) {
        father[i] = i;
    }
    sort(ed, ed+m, cmp);
    for (int i=0; i<m; i++) {
        int a = findFather(ed[i].u);
        int b = findFather(ed[i].v);
        if (a != b) {
            father[a] = b;
            ans += ed[i].cost;
            numEdge++;
        }
        if (numEdge == n-1) break;
    }
    if (numEdge != n-1) return -1;
    return ans;
}