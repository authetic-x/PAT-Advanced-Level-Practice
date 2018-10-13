//
// Created by authetic on 2018/10/5.
/*
 * Dijsktra算法问题，求单源最短路径
 * 可以用结构体，也可以多开一个二维数组，深度遍历那里
 * 有一点麻烦，设计弹入弹出问题，PAT测试只能拿到18分，
 * 两个测试过不了，I don't know why! 直接再写了一个不用DFS版的
 * 还是有一个测试过不了！
 */
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

int n,m,st,ed,G[maxn][maxn],cost[maxn][maxn];
int d[maxn],c[maxn];
int pre[maxn];
bool vis[maxn] = {false};

void Dijkstra(int s) {
    fill(d, d+maxn, INF);
    fill(c, c+maxn, INF);
    for (int i=0; i<n; i++) pre[i] = i;
    d[s] = 0;
    c[s] = 0;
    for (int i=0; i<n; i++) {
        int u=-1, MIN=INF;
        for (int j=0; j<n; j++) {
            if (!vis[j] && d[j]<MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v=0; v<n; v++) {
            if (!vis[v] && G[u][v]!=INF) {
                if (d[u]+G[u][v] < d[v]) {
                    d[v] = d[u]+G[u][v];
                    pre[v] = u;
                    c[v] = c[u]+cost[u][v];
                } else if (d[u]+G[u][v]==d[v]) {
                    if (c[u]+G[u][v] < c[v]) {
                        c[v] = c[u]+cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void printPath(int v) {
    if (v == st) {
        printf("%d ", v);
        return;
    }
    printPath(pre[v]);
    printf("%d ", v);
}

int main() {
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    fill(G[0], G[0]+maxn*maxn, INF);
    int u,v;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &u, &v);
        scanf("%d %d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    printPath(ed);
    printf("%d %d\n", d[ed], c[ed]);
    return 0;
}