//
// Created by authetic on 2018/10/20.
/*
 * 选硬币问题
 * Note：方法一 DFS遍历 先给硬币排序，最先遍历到的结果就是答案，但只能得29分
 * 方法二
 */
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int coins[maxn],N,M;
vector<int> temp,ans,temp_cmp;
int dp[maxn][110];

void DFS(int i, int w) {
    if (w+coins[i] > M || i==N) return;
    if (w+coins[i] == M) {
        temp.push_back(coins[i]);
        // 与当前ans作比较
        if (ans.empty()) {
            ans = temp;
        }
        temp.pop_back();
        return;
    }
    temp.push_back(coins[i]);
    DFS(i+1, w+coins[i]);
    temp.pop_back();
    DFS(i+1, w);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i=1; i<N; i++) {
        scanf("%d", &coins[i]);
    }
    sort(coins+1, coins+N+1);
    for (int i=1; i<=N; i++) {
        for (int v=coins[i]; v<=M; v++) {
            
        }
    }
}