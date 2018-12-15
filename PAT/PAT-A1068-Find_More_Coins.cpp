//
// Created by authetic on 2018/12/13.
/*
 * 01背包动态规划，注意路径的记录方式，先从大到小排序，再从
 * 后到前遍历
 */
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int d[110], w[maxn];
bool choice[maxn][110];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &w[i]);
    }
    sort(w+1, w+n+1, cmp);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = m; j >= w[i]; j -- ) {
            if (d[j] <= d[j-w[i]]+w[i]) {
                d[j] = d[j-w[i]] + w[i];
                choice[i][j] = true;
            }
        }
    }
    if (d[m] != m) printf("No Solution");
    else {
        vector<int> path;
        int v = m, index = n;
        while (v > 0) {
            if (choice[index][v]) {
                v -= w[index];
                path.push_back(w[index]);
            }
            index --;
        }
        for (int i = 0; i < path.size(); i ++ ) {
            printf("%d", path[i]);
            if (i != path.size()-1) printf(" ");
        }
    }
    return 0;
}