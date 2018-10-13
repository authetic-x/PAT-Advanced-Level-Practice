//
// Created by authetic on 2018/10/4.
/*
 * 假设图中的某个结点失效，需要补充多少条边使剩下的图连通起来
 * Note: 实际是利用图的遍历求连通块个数问题，需补充的边数等于
 * 连通块的个数减一
 */
//

# include<cstdio>
# include<vector>
#include <cstring>
# include<queue>
using namespace std;

const int maxn = 1010;

vector<int> vex[maxn];
int N,M,K,lost;
bool vis[maxn] = {false};

void DFS(int v) {
    if (v == lost) return;
    vis[v] = true;
    for (int i=0; i < vex[v].size(); i++) {
        if (!vis[vex[v][i]]) {
            DFS(vex[v][i]);
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i < M; i++) {
        int p1,p2;
        scanf("%d %d", &p1, &p2);
        vex[p1].push_back(p2);
        vex[p2].push_back(p1);
    }
    for (int i=0; i < K; i++) {
        scanf("%d", &lost);
        memset(vis, false, sizeof(vis));
        int block = 0;
        for (int j=1; j <= N; j++) {
            if (j != lost && !vis[j]) {
                DFS(j);
                block++;
            }
        }
        printf("%d\n", block);
    }
    return 0;
}