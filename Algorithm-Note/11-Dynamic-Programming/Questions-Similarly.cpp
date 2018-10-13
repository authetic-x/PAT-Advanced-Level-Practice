//
// Created by authetic on 2018/10/11.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// 数塔问题
int Pogoda_Problem(int **f, int n) {
    int dp[n+1][n+1];
    for (int i=1; i<=n; i++) {
        dp[n][i] = f[n][i];
    }
    for (int i=n-1; i>=1; i--) {
        for (int j=1; j<=i; j++) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];
        }
    }
    return dp[1][1];
}

// The sum of largest continuous subsequence
int SLCS(int s[], int n) {
    int dp[n+1];
    dp[0] = 0;
    int ans = -1;
    for (int i=1; i<=n; i++) {
        dp[i] = max(dp[i-1], dp[i-1]+s[i]);
        if (dp[i] > ans) ans = dp[i];
    }
    return ans;
}

// Longest Increasing sequence
int LIS(int s[], int n) {
    int dp[n+1];
    int ans = -1;
    for (int i=1; i<=n; i++) {
        dp[i] = 1;
        for (int j=1; j<=i; j++) {
            if (s[j]<=s[i] && dp[j]+1>dp[i]) {
                dp[i] = dp[j]+1;
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Longest common subsequence
int LCS(char A[], char B[]) {
    int lenA=strlen(A), lenB=strlen(B);
    int dp[lenA+1][lenB+1];
    for (int i=0; i<=lenA; i++) {
        dp[i][0] = 0;
    }
    for (int i=0; i<=lenB; i++) {
        dp[0][i] = 0;
    }
    for (int i=1; i<=lenA; i++) {
        for (int j=1; j<=lenB; j++) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[lenA][lenB];
}

// Longest palindromic substring
int LPS(char s[]) {
    int len=strlen(s), ans=1;
    int dp[len+1][len+1];
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<len; i++) {
        dp[i][i] = 1;
        if (i < len-1) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                ans = 2;
            }
        }
    }
    for (int L=3; L<=len; L++) {
        for (int i=0; i+L-1<len; i++) {
            int j = i+L-1;
            if (s[i]==s[j] && dp[i+1][j-1]==1) {
                dp[i][j] = L;
                ans = L;
            }
        }
    }
    return ans;
}

int main() {

}