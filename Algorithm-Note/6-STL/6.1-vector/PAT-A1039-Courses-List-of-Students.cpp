//
// Created by authetic on 2018/8/28.
/*
 * 存储选课信息，然后根据学生姓名查找输出选课信息
 * key: 数据量过大，不可能线性存储，循环输出，所以先
 * 将学生姓名化为hash整型，用vector存储选了哪些课，再
 * 直接输出即可！
 */
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 26*26*26*10+1;
vector<int> stu[maxn];

int getId(char name[]) {
    int id=0;
    for (int i=0; i<3; i++) {
        id = id*26 + (name[i]-'A');
    }
    id = id*10 + (name[3]-'0');
    return id;
}

int main() {
    int N,K,courseId;
    char name[5];
    scanf("%d %d", &N, &K);
    for (int i=0; i<K; i++) {
        int num;
        scanf("%d %d", &courseId, &num);
        for (int j=0; j<num; j++) {
            scanf("%s", name);
            int id = getId(name);
            stu[id].push_back(courseId);
        }
    }
    for (int i=0; i<N; i++) {
        scanf("%s", name);
        int id = getId(name);
        sort(stu[id].begin(), stu[id].end());
        printf("%s %d", name, stu[id].size());
        for (int j=0; j<stu[id].size(); j++) {
            printf(" %d", stu[id][j]);
        }
        printf("\n");
    }
    return 0;
}