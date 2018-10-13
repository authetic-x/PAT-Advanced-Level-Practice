//
// Created by authetic on 2018/10/4.
/*
 * 将图看成树，求使树的高度最大的结点
 * Note: 判断图是否连通，并求图的最大深度问题，用到了并查集，
 * 也可以用遍历实现，但是比较麻烦，因为中间没有用bool数组记录
 * 已访问的结点，直接在函数中传入了一个pre变量，求图的最大深度
 * 好像用这种方式更方便一些！
 */
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int N;
vector<int> vex[maxn];
int father[maxn];
bool isRoot[maxn] = {false};

int findFather(int i) {
    int x = i;
    while (x != father[x]) {
        x = father[x];
    }
    int a = i;
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int f1 = findFather(a);
    int f2 = findFather(b);
    if (f1 != f2) {
        father[f1] = f2;
    }
}

void init() {
    for (int i=0; i<N; i++) {
        father[i] = i;
    }
}

int calBlock() {
    int block = 0;
    for (int i=1; i<=N; i++) {
        isRoot[findFather(i)] = true;
    }
    for (int i=1; i<=N; i++) {
        block += isRoot[i];
    }
    return block;
}

int maxH = 0;
vector<int> temp, ans;

void DFS(int v, int height, int pre) {
    if (height > maxH) {
        temp.clear();
        maxH = height;
        temp.push_back(v);
    } else if (height == maxH) {
        temp.push_back(v);
    }
    for (int i=0; i < vex[v].size(); i++) {
        if (vex[v][i] == pre) continue;
        DFS(vex[v][i], height+1, v);
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N-1; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        vex[a].push_back(b);
        vex[b].push_back(a);
    }
    int block = calBlock();
    if (block > 1) {
        printf("Error: %d components\n", block);
    } else {
        DFS(1, 1, -1);
        ans = temp;
        DFS(ans[0], 1, -1);
        for (int i=0; i<temp.size(); i++) {
            ans.push_back(temp[i]);
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans[0]);
        for (int i=1; i<ans.size(); i++) {
            if (ans[i] != ans[i-1]) {
                printf("%d\n", ans[i]);
            }
        }
    }
    return 0;
}