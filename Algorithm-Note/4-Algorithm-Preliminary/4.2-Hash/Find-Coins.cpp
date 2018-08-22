//
// Created by authetic on 2018/8/16.
/*
 * 找硬币，将给出的序列的两个数组合成目标数，多解情况最小优先
 * key: 可以用hash方式存储或者二分法，hash简单些
 */
//

#include <cstdio>

const int maxn = 1005;
int hashtable[maxn] = {0};
int amount;

int main() {
    int n;
    scanf("%d %d", &n, &amount);
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        hashtable[a]++;
    }
    for (int i=0; i<maxn; i++) {
        if (hashtable[i] && hashtable[amount-i]) {
            if (i==amount-i && hashtable[i]<=1) {
                continue;
            }
            printf("%d %d\n", i, amount-i);
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}
