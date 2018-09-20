//
// Created by authetic on 2018/9/19.
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int father[maxn];
int isRoot[maxn];
int hobby[maxn];

bool cmp(int a, int b) {
    return a>b;
}

void init(int n) {
    for (int i=1; i<=n; i++) {
        father[i] = i;
        isRoot[i] = 0;
        hobby[i] = 0;
    }
}

int findFather(int a) {
    while (a != father[a]) {
        a = father[a];
    }
    return a;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa!=fb) {
        father[fa] = fb;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);
    for (int i=1; i<=n; i++) {
        int k,h;
        scanf("%d:", &k);
        for (int j=0; j<k; j++) {
            scanf("%d", &h);
            if (hobby[h]==0) hobby[h] = i;
            Union(i, findFather(hobby[h]));
        }
    }
    for (int i=1; i<=n; i++) {
        int f = findFather(i);
        isRoot[f]++;
    }
    int ans=0;
    for (int i=1; i<=n; i++) {
        if (isRoot[i]!=0) ans++;
    }
    sort(isRoot+1, isRoot+n+1, cmp);
    printf("%d\n", ans);
    for (int i=1; i<=ans; i++) {
        printf("%d", isRoot[i]);
        if (i<ans) printf(" ");
    }
    return 0;
}