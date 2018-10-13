//
// Created by authetic on 2018/10/10.
//

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

int cm,n,sp,m;
int G[maxn][maxn],d[maxn],weight[maxn];
int minNeed=INF,minRemain=INF;
bool vis[maxn] = {false};
vector<int> pre[maxn];
vector<int> temp,path;

void Dijsktra(int s) {
    fill(d, d+maxn, INF);
    d[s] = 0;
    for (int i=0; i<n; i++) {
        int u=-1, MIN=INF;
        for (int j=0; j<=n; j++) {
            if (!vis[j] && d[j]<MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v=0; v<=n; v++) {
            if (!vis[v] && G[u][v]!=INF) {
                if (d[u]+G[u][v] < d[v]) {
                    d[v] = d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u]+G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v) {
    if (v == 0) {
        temp.push_back(v);
        int need=0, remain=0;
        for (int i=temp.size()-1; i>=0; i--) {
            int id = temp[i];
            if (weight[id] > 0) {
                remain += weight[id];
            } else {
                if (remain >= abs(weight[id])) {
                    remain -= abs(weight[id]);
                } else {
                    need += abs(weight[id]) - remain;
                    remain = 0;
                }
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minRemain = remain;
            path = temp;
        } else if (need==minNeed && remain<minRemain) {
            minRemain = remain;
            path = temp;
        }
        temp.pop_back();
        return;
    }
    temp.push_back(v);
    for (int i=0; i<pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    temp.pop_back();
}

int main() {
    scanf("%d %d %d %d", &cm, &n, &sp, &m);
    for (int i=1; i<=n; i++) {
        scanf("%d", &weight[i]);
        weight[i] -= cm/2;
    }
    int u,v;
    fill(G[0], G[0]+maxn*maxn, INF);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijsktra(0);
    DFS(sp);
    printf("%d ", minNeed);
    for (int i=path.size()-1; i>=0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf("->");
    }
    printf(" %d", minRemain);
    return 0;
}