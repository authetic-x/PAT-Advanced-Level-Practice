//
// Created by authetic on 2018/11/26.
/*
 * 求中位数，按位相加找到mid输出就行了，没加k[n+1]那一行报了
 * 很多段错误不知道为什么
 */
//

#include <iostream>

using namespace std;

const int maxn = 200010;

int n, m, k[maxn];

int main() {
    int temp;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &k[i]);
    }
    k[n + 1] = 0x7fffffff;
    cin >> m;
    int mid = (n + m + 1) / 2, i = 1, count = 0;
    for (int j = 1;j <= m; j ++ ) {
        scanf("%d", &temp);
        while (k[i] < temp) {
            count++;
            if (count == mid) cout << k[i];
            i++;
        }
        count++;
        if (count == mid) cout << temp;
    }
    while (i <= n) {
        count++;
        if (count == mid) cout << k[i];
        i++;
    }
    return 0;
}