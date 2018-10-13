//
// Created by authetic on 2018/10/13.
/*
 * 关于DAG(Directed Acyclic Graph)的拓扑排序
 */
//

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1010;

vector<int> G[maxn];
int n,m,inDgree[maxn];

bool topological_sort() {
    int num=0;
    queue<int> q;
    for (int i=0; i<n; i++) {
        if (inDgree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        printf("%d ", u);
        num++;
        for (int i=0; i<G[u].size(); i++) {
            int v = G[u][i];
            inDgree[v]--;
            if (inDgree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (num == n) return true;
    else return false;
}