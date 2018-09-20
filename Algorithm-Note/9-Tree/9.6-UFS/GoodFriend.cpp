//
// Created by authetic on 2018/9/19.
/*
 * 并查集的基本模型
 */
//

#include <cstdio>

const int maxn = 110;

int father[maxn];
bool isRoot[maxn];

int findFather(int x) {
    while (x!=father[x]) {
        x = father[x];
    }
    return x;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa!=fb) {
        father[fa] = fb;
    }
}

void init(int n) {
    for (int i=0; i<n; i++) {
        father[i] = i;
        isRoot[i] = false;
    }
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    init(n);
    int a,b;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        Union(a,b);
    }
    for (int i=0; i<n; i++) {
        isRoot[findFather(i)] = true;
    }
    int ans=0;
    for (int i=0; i<n; i++) {
        if (isRoot[i]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}