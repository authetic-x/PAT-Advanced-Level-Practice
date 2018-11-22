//
// Created by authetic on 2018/11/22.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10010;

int s[maxn], dp[maxn], ind[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &s[i]);
    }
    dp[0] = -1000000000;
    ind[0] = 0;
    for (int i = 1; i < n; i ++ ) {
        if (dp[i-1] + s[i] > s[i]) {
            dp[i] = dp[i-1] + s[i];
            ind[i] = ind[i-1];
        } else {
            dp[i] = s[i];
            ind[i] = i;
        }
    }
    int k = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (dp[i] > dp[k]) {
            k = i;
        }
    }
    if (dp[k] < 0) {
        printf("0 %d %d", s[1], s[n]);
    } else {
        printf("%d %d %d", dp[k], s[ind[k]], s[k]);
    }
    return 0;
}