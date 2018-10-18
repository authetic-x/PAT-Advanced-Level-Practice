//
// Created by authetic on 2018/10/16.
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int s[maxn],dp[maxn],a[maxn];

int main() {
    int n;
    bool flag = false;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) flag=true;
    }
    if (!flag) {
        printf("%d %d\n", a[0], a[n-1]);
        return 0;
    }
    dp[0] = a[0];
    s[0] = 0;
    for (int i=1; i<n; i++) {
        if (dp[i-1]+a[i] > a[i]) {
            dp[i] = dp[i-1]+a[i];
            s[i] = s[i-1];
        } else {
            dp[i] = a[i];
            s[i] = i;
        }
    }
    int k=0;
    for (int i=1; i<n; i++) {
        if (dp[i] > dp[k]) k=i;
    }
    printf("%d %d %d\n", dp[k], a[s[k]], a[k]);
    return 0;
}