//
// Created by authetic on 2018/10/9.
/*
 * 最小生成树，prim算法
 */
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
const int INF = 1000000000;

int G[maxn][maxn],d[maxn],n;
bool vis[maxn] = {false};

int prim() {
    fill(d, d+maxn, INF);
    d[0] = 0;
    int ans = 0;
    for (int i=0; i<n; i++) {
        int u = -1,MIN=INF;
        for (int j=0; j<n; j++) {
            if (!vis[j] && d[j]<MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return -1;
        vis[u] = true;
        ans += d[u];
        for (int v=0; v<n; v++) {
            if (!vis[v] && G[u][v]!=INF && G[u][v]<d[v]) {
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}
