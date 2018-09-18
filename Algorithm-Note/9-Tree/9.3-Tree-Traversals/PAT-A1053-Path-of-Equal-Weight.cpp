//
// Created by authetic on 2018/9/15.
/*
 * 给出树的结构，求与给定值相等的权值路径，按字典序大到小排序
 * Note: 这个题稍微有点难，还是用静态树的结构，深度遍历，一开始想用
 * vector存储各个路径然后排序输出，但不知道怎么写递归结构，可以先给
 * 每个结点的子结点按权值排序，这样递归的路径就自动排序了！
 */
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110;

struct Node {
    int weight;
    vector<int> child;
}node[maxn];

int n,m,s;
int path[maxn];

bool cmp(int a, int b) {
    return node[a].weight>node[b].weight;
}

void DFS(int root, int numNode, int sum) {
    if (sum>s) return;
    if (sum==s) {
        if (!node[root].child.empty()) return;
        for (int i=0; i<numNode; i++) {
            printf("%d", node[path[i]].weight);
            if (i<numNode-1) printf(" ");
            else printf("\n");
        }
        return;
    }
    for (int i=0; i<node[root].child.size(); i++) {
        int child = node[root].child[i];
        path[numNode] = child;
        DFS(child, numNode+1, sum+node[child].weight);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i=0; i<n; i++) {
        scanf("%d", &node[i].weight);
    }
    int root,k,child;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &root, &k);
        for (int j=0; j<k; j++) {
            scanf("%d", &child);
            node[root].child.push_back(child);
        }
        sort(node[root].child.begin(), node[root].child.end(), cmp);
    }
    path[0] = 0;
    DFS(0,1,node[0].weight);
    return 0;
}