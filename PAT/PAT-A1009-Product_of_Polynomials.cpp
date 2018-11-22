//
// Created by authetic on 2018/11/22.
/*
 * 多项式相乘，浪费了很多无辜的时间
 */
//

#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

struct Pn {
    int ex;
    double coe;
}pn[15];

map<int, double, greater<int>> mp;

int main() {
    int m, n, ex;
    double coe;
    scanf("%d", &m);
    for (int i = 0; i < m ; i ++ ) {
        scanf("%d %lf", &pn[i].ex, &pn[i].coe);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        scanf("%d %lf", &ex, &coe);
        for (int j = 0; j < m; j ++ ) {
            if (mp.find(pn[j].ex + ex) != mp.end()) {
                mp[pn[j].ex + ex] += pn[j].coe * coe;
            } else {
                mp[pn[j].ex + ex] = pn[j].coe * coe;
            }
        }
    }
    printf("%d", mp.size());
    for (map<int, double>::iterator it = mp.begin(); it != mp.end(); it ++ ) {
        printf(" %d %.1f", it->first, it->second);
    }
    return 0;
}