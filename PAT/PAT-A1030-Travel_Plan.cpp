//
// Created by authetic on 2018/11/30.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 510;
const int INF = 100000000;

int n, m, G[maxn][maxn], Cost[maxn][maxn];
int d[maxn], c[maxn], pre[maxn];
bool visit[maxn] = {false};

void Dijstra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for (int i = 0; i < n; i ++ ) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j ++ ) {
            if (d[j] < MIN && !visit[j]) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;;
        visit[u] = true;
        for (int v = 0; v < n; v ++ ) {
            if (G[u][v] != INF && !visit[v]) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + Cost[u][v];
                    pre[v] = u;
                } else if (d[u] + G[u][v] == d[v] && c[u] +
                    Cost[u][v] < c[v]) {
                    c[v] = c[u] + Cost[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}

void PrintPath(int v, int st) {
    if (v == st) {
        printf("%d", v);
        return;
    }
    PrintPath(pre[v], st);
    printf(" %d", v);
}

int main() {
    int st, ed, c1, c2;
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    fill(G[0], G[0] + maxn*maxn, INF);
    for (int i = 0; i < m; i ++ ) {
        scanf("%d %d", &c1, &c2);
        scanf("%d %d", &G[c1][c2], &Cost[c1][c2]);
        G[c2][c1] = G[c1][c2];
        Cost[c2][c1] = Cost[c1][c2];
    }
    Dijstra(st);
    PrintPath(ed, st);
    printf(" %d %d\n", d[ed], c[ed]);
    return 0;
}