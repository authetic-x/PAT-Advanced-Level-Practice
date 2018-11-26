//
// Created by authetic on 2018/11/24.
/*
 * 寻找无向图构造成一棵树的最深根节点
 * Key: 先随机选一个初始节点深度遍历，所得的节点为结果的一部分，
 * 然后在这部分节点中再随机算一个节点深度遍历，将所有得到的节点
 * 去重输出即可
 * 看了一下柳婼的解法，不用并查集代码更少，更方便，而且没有错误！
 */
//

#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10010;

int n;
vector<int> G[maxn];
bool isVisit[maxn];
int maxHeight = 0;
vector<int> temp, ans;
set<int> s;

void DFS(int u, int h) {
    if (h > maxHeight) {
        temp.clear();
        temp.push_back(u);
        maxHeight = h;
    } else if (h == maxHeight) {
        temp.push_back(u);
    }
    isVisit[u] = true;
    for (int i = 0; i < G[u].size(); i ++ ) {
        if (!isVisit[G[u][i]]) {
            DFS(G[u][i], h+1);
        }
    }
}

int main() {
    scanf("%d", &n);
    int a, b, s1 = 1, cnt = 0;
    for (int i = 1; i < n; i ++ ) {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= n; i ++ ) {
        if (!isVisit[i]) {
            DFS(i, 1);
            if (i == 1) {
                if (temp.size() != 0) s1 = temp[0];
                for (int j = 0; j < temp.size(); j ++ ) {
                    s.insert(temp[j]);
                }
            }
            cnt++;
        }
    }
    if (cnt > 1) {
        printf("Error: %d components", cnt);
    } else {
        temp.clear();
        maxHeight = 0;
        fill(isVisit, isVisit + maxn, false);
        DFS(s1, 1);
        for (int i = 0; i < temp.size(); i ++ ) {
            s.insert(temp[i]);
        }
        for (auto it = s.begin(); it != s.end(); it ++ ) {
            printf("%d\n", *it);
        }
    }
    return 0;
}