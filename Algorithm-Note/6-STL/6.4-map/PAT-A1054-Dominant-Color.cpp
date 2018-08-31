//
// Created by authetic on 2018/8/30.
/*
 * key: map的简单运用，用cin会超时
 */
//

#include <cstdio>
#include <map>
using namespace std;

map<int,int> color;

int main() {
    int m,n,col;
    scanf("%d %d", &m, &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &col);
            if (color.find(col)!=color.end()) color[col]++;
            else color[col]=1;
        }
    }
    int max=0,ans;
    for (map<int,int>::iterator it=color.begin(); it!=color.end(); it++) {
        if (it->second > max) {
            max = it->second;
            ans = it->first;
        }
    }
    printf("%d\n", ans);
    return 0;
}