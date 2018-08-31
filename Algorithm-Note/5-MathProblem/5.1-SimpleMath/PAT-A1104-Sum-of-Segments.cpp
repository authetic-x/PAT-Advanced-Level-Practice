//
// Created by authetic on 2018/8/23.
//

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    double p,ans=0;
    for (int i=1; i<=n; i++) {
        scanf("%lf", &p);
        ans += p * i * (n-i+1);
    }
    printf("%.2f\n", ans);
    return 0;
}