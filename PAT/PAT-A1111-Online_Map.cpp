//
// Created by authetic on 2018/12/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 520;
const int INF = 1000000000;

struct Node {
    int v, dis, time;
};

int n, m, s, t, d[maxn], f[maxn], d_pre[maxn], f_pre[maxn];
vector<Node> G[maxn];
bool visit[maxn];

void Dijstra(int s, bool shortest) {
    fill(d, d+maxn, INF);
    fill(f, f+maxn, INF);
    d[s] = 0;
    f[s] = 0;
    for (int i = 0; i < n; i ++ ) {
        int u = -1, MIN = INF;
        if (shortest) {
            for (int j = 0; j < n; j ++ ) {
                if (!visit[j] && d[j] < MIN) {
                    u = j;
                    MIN = d[j];
                }
            }
        } else {
            for (int j = 0; j < n; j ++ ) {
                if (!visit[j] && f[j] < MIN) {
                    u = j;
                    MIN = f[j];
                }
            }
        }
        if (u == -1) return;
        visit[u] = true;
        for (int j = 0; j < G[u].size(); j ++ ) {
            int v = G[u][j].v;
            if (shortest) {
                if (!visit[v]) {
                    if (G[u][j].dis + d[u] < d[v]) {
                        d[v] = G[u][j].dis + d[u];
                        f[v] = f[u] + G[u][j].time;
                        d_pre[v] = u;
                    } else if (G[u][j].dis + d[u] == d[v]) {
                        if (f[u] + G[u][j].time < f[v]) {
                            f[v] = f[u] + G[u][j].time;
                            d_pre[v] = u;
                        }
                    }
                }
            } else {
                if (!visit[v]) {
                    if (G[u][j].time + f[u] < f[v]) {
                        d[v] = G[u][j].dis + d[u];
                        f[v] = f[u] + G[u][j].time;
                        f_pre[v] = u;
                    } else if (G[u][j].time + f[u] == f[v]) {
                        if (d[u] + G[u][j].dis < d[v]) {
                            f[v] = f[u] + G[u][j].time;
                            f_pre[v] = u;
                        }
                    }
                }
            }
        }
    }
}

void dfs(int root, vector<int> &v, bool shortest) {
    if (root == s) {
        v.push_back(root);
        return;
    }
    if (shortest) {
        dfs(d_pre[root], v, shortest);
    } else {
        dfs(f_pre[root], v, shortest);
    }
    v.push_back(root);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i ++ ) {
        int u, v, one_way, d, time;
        Node node;
        scanf("%d %d %d %d %d", &u, &v, &one_way, &d, &time);
        node.v = v;
        node.dis = d;
        node.time = time;
        G[u].push_back(node);
        if (!one_way) {
            node.v = u;
            G[v].push_back(node);
        }
    }
    scanf("%d%d", &s, &t);
    Dijstra(s, true);
    //Dijstra(s, false);
    for (int i = 0; i < n; i ++ ) {
        cout << d_pre[i] << " ";
    }
    /*
    vector<int> shortest, fastest;
    dfs(t, shortest, true);
    dfs(t, fastest, false);
    for (int i = 0;i < shortest.size(); i ++ ) {
        printf("%d ", shortest[i]);
    }*/
    return 0;
}