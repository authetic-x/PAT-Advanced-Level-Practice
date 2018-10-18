//
// Created by authetic on 2018/10/17.
//

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10010;

int dp[maxn] = {0},s[maxn];
int hashTable[210];
int ans=0;

int main() {
    int n,m,l,p;
    scanf("%d %d", &n, &m);
    memset(hashTable, -1, sizeof(hashTable));
    for (int i=0; i<m; i++) {
        scanf("%d", &p);
        hashTable[p] = i;
    }
    scanf("%d", &l);
    int num=0;
    for (int i=0; i<l; i++) {
        scanf("%d", &p);
        if (hashTable[p] != -1) {
            s[num++] = hashTable[p];
        }
    }
    for (int i=0; i<num; i++) {
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            if (s[j]<=s[i] && dp[j]+1>dp[i]) {
                dp[i] = dp[j]+1;
            }
        }
        if (dp[i] > ans) ans = dp[i];
    }
    printf("%d", ans);
    return 0;
}
