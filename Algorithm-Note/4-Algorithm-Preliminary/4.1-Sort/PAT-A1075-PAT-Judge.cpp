//
// Created by authetic on 2018/8/24.
/*
 * 模拟PAT的排名过程。
 * key: 题目没有什么难度，基础排序题
 * 但这样的题总是搞得很麻烦，题目一开始没看清楚，
 * 在许多小地方浪费了很多时间，尤其是中间将变量n写了i,
 * 检查了几遍硬是没看出来，代价巨大。。。
 * 不过这也从侧面证明了自己的变量命名还是不够规范，容易出错。
 */
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int N,K,M;                  //用户数，问题数，提交数
int pro[6];

struct User {
    int id;
    int total_socre;
    int problem[6];
    bool flag;
    int perfect;
}user[maxn];

void init() {
    for (int i=1; i<=N; i++) {
        user[i].id = i;
        user[i].total_socre = 0;
        user[i].flag = false;
        user[i].perfect = 0;
        memset(user[i].problem, -1, sizeof(user[i].problem));
    }
}

bool cmp(User a, User b) {
    //if (a.flag!=b.flag) return a.flag>b.flag;
    if (a.total_socre!=b.total_socre) return a.total_socre>b.total_socre;
    else if (a.perfect!=b.perfect) return a.perfect>b.perfect;
    else return a.id < b.id;
}

int main() {
    scanf("%d %d %d", &N, &K, &M);
    for (int i=1; i<=K; i++) {
        scanf("%d", &pro[i]);
    }
    init();
    for (int i=0; i<M; i++) {
        int n,p,score;
        scanf("%d %d %d", &n, &p, &score);
        if (score != -1) {
            user[n].flag = true;
        }
        if (user[n].problem[p]==-1 && score==-1) {
            user[n].problem[p] = 0;
        }
        if (user[n].problem[p] < score) {
            if (score == pro[p]) {
                user[n].perfect++;
            }
            user[n].problem[p] = score;
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=K; j++) {
            if (user[i].problem[j]!=-1) {
                user[i].total_socre += user[i].problem[j];
            }
        }
    }
    sort(user+1, user+N+1, cmp);
    int rank = 1;
    for (int i=1; i<=N && user[i].flag; i++) {
        if (i>1 && user[i].total_socre!=user[i-1].total_socre) {
            rank = i;
        }
        printf("%d %05d %d", rank, user[i].id, user[i].total_socre);
        for (int j=1; j<=K; j++) {
            if (user[i].problem[j]!=-1) {
                printf(" %d", user[i].problem[j]);
            } else {
                printf(" -");
            }
        }
        printf("\n");
    }
    return 0;
}