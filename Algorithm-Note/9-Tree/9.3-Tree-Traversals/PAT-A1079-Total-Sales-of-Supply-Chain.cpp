//
// Created by authetic on 2018/9/14.
/*
 * 供应商与零售商问题 求最大价值
 * Note: 静态树，创建树，然后深度遍历到叶子结点，依次
 * 相加即可求出总价值之和！
 */
//

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;

struct Node {
    double data;
    vector<int> child;
}node[maxn];

double p,r,ans=0;
int n;

void DFS(int root, int depth) {
    if (node[root].child.empty()) {
        ans += node[root].data * pow(1+r,depth);
        return;
    }
    for (int i=0; i<node[root].child.size(); i++) {
        DFS(node[root].child[i], depth+1);
    }
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    r /= 100;
    int k,child;
    for (int i=0; i<n; i++) {
        scanf("%d", &k);
        if (k==0) {
            scanf("%lf", &node[i].data);
        } else {
            for (int j=0; j<k; j++) {
                scanf("%d", &child);
                node[i].child.push_back(child);
            }
        }
    }
    DFS(0,0);
    printf("%.1f\n", ans*p);
    return 0;
}