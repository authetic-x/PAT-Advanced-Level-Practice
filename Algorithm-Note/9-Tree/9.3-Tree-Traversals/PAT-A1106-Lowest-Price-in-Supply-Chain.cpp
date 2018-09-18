//
// Created by authetic on 2018/9/14.
/*
 * 供应商零售商问题，求最低价格
 * Note: 这类问题都差不多，创建静态树，遍历，深度遍历代码少，
 * 会方便一些，然后总是看错题目，不是零售商的位置，而是个数！
 */
//

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;

vector<int> node[maxn];
int n,num=0;
double p,r,ans=100000000000;


void DFS(int root, int level) {
    if (node[root].empty()) {
        double price = p * pow(1+r, level);
        if (price<ans) {
            ans = price;
            num = 1;
        } else if (price==ans) num++;
    }
    for (int i=0; i<node[root].size(); i++) {
        DFS(node[root][i], level+1);
    }
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    r /= 100;
    for (int i=0; i<n; i++) {
        int k,child;
        scanf("%d", &k);
        for (int j=0; j<k; j++) {
            scanf("%d", &child);
            node[i].push_back(child);
        }
    }
    DFS(0,0);
    printf("%.4f %d\n", ans, num);
    return 0;
}