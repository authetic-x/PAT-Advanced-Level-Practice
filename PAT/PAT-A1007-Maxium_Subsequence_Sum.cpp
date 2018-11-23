//
// Created by authetic on 2018/11/22.
/*
 * 最大连续子序列
 */
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10010;

int a[maxn], s[maxn], dp[maxn];

int main() {
    int n;
    bool flag = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) flag = true;
    }
    if (!flag) {
        printf("0 %d %d", a[0], a[n-1]);
        return 0;
    }

    dp[0] = a[0];
    s[0] = 0;
    for (int i = 1; i < n; i ++ ) {
        if (dp[i-1] + a[i] > a[i]) {
            dp[i] = dp[i-1] + a[i];
            s[i] = s[i-1];
        } else {
            dp[i] = a[i];
            s[i] = i;
        }
    }
    int k = 0;
    for (int i = 0; i < n; i ++ ) {
        if (dp[i] > dp[k]) {
            k = i;
        }
    }
    printf("%d %d %d", dp[k], a[s[k]], a[k]);
    return 0;
}