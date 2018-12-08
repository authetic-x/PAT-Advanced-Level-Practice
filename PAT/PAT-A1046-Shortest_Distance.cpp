//
// Created by authetic on 2018/12/8.
/*
 * 有一个测试报段错误，但柳婼同学的又没问题，搞不清楚
 */
//

#include <iostream>
using namespace std;

const int maxn = 10010;

int n, m, sum=0;
int dis[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) {
        int temp;
        scanf("%d", &temp);
        sum += temp;
        dis[i] = sum;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i ++ ) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        int d = dis[b-1] - dis[a-1];
        if (d < sum - d) printf("%d\n", d);
        else printf("%d\n", sum - d);
    }
    return 0;
}