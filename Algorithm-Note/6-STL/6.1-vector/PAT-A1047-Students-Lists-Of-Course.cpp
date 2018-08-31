//
// Created by authetic on 2018/8/28.
/*
 * 存储学生选课信息，输出每门课的学生
 * vector的基本运用，不过用vector直接存学生姓名最后
 * 一组测试内存会爆掉，所以只能存储整形，开一个二维字符数组
 * 存学生姓名，写一个比较函数给vector内容排序即可！
 */
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 2510;

vector<int> cor[maxn];
char name[40010][5];

bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    int n,k;
    scanf("%d %d", &n,&k);
    for (int i=0; i<n; i++) {
        int id,num;
        scanf("%s %d", name[i], &num);
        for (int j=0; j<num; j++) {
            scanf("%d", &id);
            cor[id].push_back(i);
        }
    }
    for (int i=1; i<=k; i++) {
        sort(cor[i].begin(), cor[i].end(), cmp);
        printf("%d %d\n", i, cor[i].size());
        for (vector<int>::iterator it=cor[i].begin(); it!=cor[i].end(); it++) {
            printf("%s\n", name[*it]);
        }
    }
    return 0;
}