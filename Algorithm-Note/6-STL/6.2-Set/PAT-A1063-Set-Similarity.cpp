//
// Created by authetic on 2018/8/28.
/*
 * 关于set的简单运用
 */
//

#include <cstdio>
#include <set>
using namespace std;

const int maxn = 51;
set<int> st[maxn];

void compare(set<int> a, set<int> b) {
    int totalNum=b.size(), sameNum=0;
    for (set<int>::iterator it=a.begin(); it!=a.end(); it++) {
        if (b.find(*it) != b.end()) sameNum++;
        else totalNum++;
    }
    printf("%.1f%\n", sameNum * 100.0 / totalNum);
}

int main() {
    int n,q,k,s1,s2,val;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &k);
        for (int j=0; j<k; j++) {
            scanf("%d", &val);
            st[i].insert(val);
        }
    }
    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        scanf("%d %d", &s1, &s2);
        compare(st[s1], st[s2]);
    }
    return 0;
}