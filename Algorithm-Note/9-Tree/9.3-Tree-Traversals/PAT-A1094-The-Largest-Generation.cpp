//
// Created by authetic on 2018/9/14.
/*
 * 给出家庭关系，求哪一代的人数最多
 * Note: 静态树问题，深度遍历要比层次遍历代码少的多，尽管效率一样，
 * 但我下面写的层次遍历代码显得很臃肿，变量太多，所以用深度遍历会好些！
 */
//

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 110;

struct Node {
    int layer;
    vector<int> child;
}node[maxn];

int n,m;
int layer[maxn] = {0};
int lay=0;
void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    node[root].layer=1;
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        layer[node[f].layer]++;
        if (node[f].layer>lay) lay=node[f].layer;
        if (!node[f].child.empty()) {
            for (int i=0; i<node[f].child.size(); i++) {
                int index = node[f].child[i];
                node[index].layer = node[f].layer+1;
                q.push(index);
            }
        }
    }
}

//补充深度遍历写法
int hashTable[maxn] = {0};
void DFS(int index, int level) {
    hashTable[level]++;
    for (int i=0; i<node[index].child.size(); i++) {
        DFS(node[index].child[i], level+1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int root,k,child;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &root, &k);
        for (int j=0; j<k; j++) {
            scanf("%d", &child);
            node[root].child.push_back(child);
        }
    }
    layerOrder(1);
    int ans=0,pos;
    for (int i=1; i<=lay; i++) {
        if (layer[i]>ans) {
            ans = layer[i];
            pos = i;
        }
    }
    printf("%d %d\n", ans, pos);
    return 0;
}