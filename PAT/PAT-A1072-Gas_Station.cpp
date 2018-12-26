//
// Created by authetic on 2018/12/17.
/*
 * 稍微复杂点的一道题，看懂题目，所有最小路径中的最大值
 * string比char要好用一些
 */
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1020;
const int INF = 1000000000;

int G[maxn][maxn], d[maxn];
int n, m, k, ds;
bool visit[maxn];

void Dijkstra(int s) {
    fill(d, d+maxn, INF);
    fill(visit, visit+maxn, false);
    d[s] = 0;
    for (int i = 0; i < n+m; i ++ ) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n+m; j ++ ) {
            if (!visit[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        visit[u] = true;
        for (int v = 1; v <= n+m; v ++ ) {
            if (!visit[v] && G[u][v] + d[u] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    fill(G[0], G[0]+maxn*maxn, INF);
    for (int i = 0; i < k; i ++ ) {
        string s, t;
        int tempdis, u, v;
        cin >> s >> t >> tempdis;
        if (s[0] == 'G') {
            s = s.substr(1);
            u = n + stoi(s);
        } else {
            u = stoi(s);
        }
        if (t[0] == 'G') {
            t = t.substr(1);
            v = n + stoi(t);
        } else {
            v = stoi(t);
        }
        G[u][v] = G[v][u] = tempdis;
    }
    int ansid = -1;
    double ansdis = -1, ansaver = INF;
    for (int i = n+1; i <= n+m; i ++ ) {
        Dijkstra(i);
        int mindis = INF;
        double aver = 0;
        for (int j = 1; j <= n; j ++ ) {
            if (d[j] > ds) {
                mindis = -1;
                break;
            }
            if (d[j] < mindis) {
                mindis = d[j];
            }
            aver += 1.0 * d[j];
        }
        if (mindis == -1) continue;
        aver  = aver / n;
        if (mindis > ansdis) {
            ansid = i;
            ansdis = mindis;
            ansaver = aver;
        } else if (aver < ansaver && mindis == ansdis) {
            ansid = i;
            ansaver = aver;
        }
    }
    if (ansdis == -1) printf("No Solution");
    else {
        printf("G%d\n%.1f %.1f", ansid - n, ansdis, ansaver);
    }
    return 0;
}