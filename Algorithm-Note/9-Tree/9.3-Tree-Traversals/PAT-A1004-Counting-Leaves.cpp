//
// Created by authetic on 2018/9/14.
/*
 * 给出树关系，求每层的叶子结点数
 * Note: 静态树问题，此类题目都差不多，DFS BFS都可以！
 */
//

#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 110;

vector<int> node[maxn];
int n,m,max_h=1;
int leaf[maxn] = {0};

void DFS(int root, int level) {
    if (level>max_h) max_h=level;
    if (node[root].empty()) {
        leaf[level]++;
        return;
    }
    for (int i=0; i<node[root].size(); i++) {
        DFS(node[root][i], level+1);
    }
}

int main() {
    int root,k,child;
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &root, &k);
        for (int j=0; j<k; j++) {
            scanf("%d", &child);
            node[root].push_back(child);
        }
    }
    DFS(1,1);
    printf("%d", leaf[1]);
    for (int i=2; i<=max_h; i++) {
        printf(" %d", leaf[i]);
    }
    return 0;
}