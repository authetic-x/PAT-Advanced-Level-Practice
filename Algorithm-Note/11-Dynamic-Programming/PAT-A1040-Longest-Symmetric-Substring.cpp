//
// Created by authetic on 2018/10/17.
/*
 * 判断一个字符串中回文字符串的最大长度
 * Note: 基本dp问题，子串长度依次从1开始计算，
 * 直接用gets()PAT会报编译错误，可以用cin.get()
 */
//

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1010;

int dp[maxn][maxn];
char s[maxn];

int main() {
    cin.get(s, 1001);
    memset(dp, 0, sizeof(dp));
    int ans = 1;
    int len = strlen(s);
    for (int i=0; i<len; i++) {
        dp[i][i] = 1;
        if (i < len-1) {
            if (s[i] == s[i+1]) {
                ans = 2;
                dp[i][i+1] = 1;
            }
        }
    }
    for (int L=3; L<=len; L++) {
        for (int i=0; i+L-1<len; i++) {
            int j = i+L-1;
            if (s[i] == s[j] && dp[i+1][j-1]==1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}