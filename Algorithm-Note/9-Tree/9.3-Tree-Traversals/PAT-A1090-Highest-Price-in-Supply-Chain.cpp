//
// Created by authetic on 2018/9/14.
/*
 * 供应商、零售商问题，求最大价格
 * Note: 静态树，深度遍历求最大价格和深度即可，
 * 一开始为了创建树还要写个递归，给出的父结点可以直接创建，
 * 自己太蠢了！
 */
//

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;

vector<int> node[maxn];
double p,r,ans=0;
int n,num=0;

void DFS(int root, int depth) {
    if (node[root].empty()) {
        double price = p * pow(1+r, depth);
        if (price>ans) {
            ans = price;
            num=1;
        } else if (price==ans) num++;
    }
    for (int i=0; i<node[root].size(); i++) {
        DFS(node[root][i], depth+1);
    }
}

int main() {
    int head;
    scanf("%d %lf %lf", &n, &p, &r);
    r /= 100;
    int father;
    for (int i=0; i<n; i++) {
        scanf("%d", &father);
        if (father!=-1) node[father].push_back(i);
        else head = i;
    }
    DFS(head,0);
    printf("%.2f %d\n", ans, num);
    return 0;
}