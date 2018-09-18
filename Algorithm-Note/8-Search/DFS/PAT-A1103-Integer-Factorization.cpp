//
// Created by authetic on 2018/9/12.
/*
 * 给出数n,k,p, 求k个p次方的数的和等于n的序列，输出总和最大且字典序最大的序列
 * Note: 深度遍历，类似于背包问题，不同的是可以重复选择，按题目要求，从x^p恰好小于
 * n的数开始递归，根据递归的顺序，所得的结果一定是总值最大且字典序最大，对于此类题目，
 * 就是选择与不选择的问题，关于重复，只考虑+1或者不+1即可！
*/
//

#include <cstdio>
#include <vector>
using namespace std;

vector <int> fac, ans, temp;
int n,p,k,maxFacSum = -1;

int power(int n) {
    int ans=n;
    for (int i=0; i<p-1; i++) {
        ans *= n;
    }
    return ans;
}

void init() {
    int i=0,temp=0;
    while (temp<=n) {
        fac.push_back(temp);
        temp = power(++i);
    }
}

void DFS(int index, int nowK, int sum, int facSum) {
    if (nowK==k && sum==n) {
        if (facSum > maxFacSum) {
            maxFacSum = facSum;
            ans = temp;
        }
        return;
    }
    if (nowK>k || sum>n) return;
    if (index>0) {
        temp.push_back(index);
        DFS(index, nowK+1, sum+fac[index], facSum+index);
        temp.pop_back();
        DFS(index-1, nowK, sum, facSum);
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &p);
    init();
    DFS(fac.size()-1, 0,0,0);
    if (maxFacSum==-1) printf("Impossible\n");
    else {
        printf("%d = ", n);
        for (int i=0; i<ans.size(); i++) {
            if (i!=ans.size()-1) printf("%d^%d + ", ans[i], p);
            else printf("%d^%d\n", ans[i], p);
        }
    }
    return 0;
}