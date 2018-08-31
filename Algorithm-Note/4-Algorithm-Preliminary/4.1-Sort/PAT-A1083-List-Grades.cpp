//
// Created by authetic on 2018/8/24.
/*
 * 给出学生信息，按大小输出成绩在范围内的学生信息
 * key: 基础排序题目，但PAT测试有一个是错的，实在不知道
 * 怎么回事，今天被上道排序题折磨到崩溃了，这道放弃了。。。
 */
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50;
int g1,g2;

struct Student {
    char name[15];
    char id[15];
    int grade;
}stu[maxn];

bool cmp(Student a, Student b) {
    return a.grade>b.grade;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    scanf("%d %d", &g1, &g2);
    sort(stu, stu+n, cmp);
    bool flag = false;
    for (int i=0; i<n; i++) {
        if (stu[i].grade>=g1 && stu[i].grade<=g2) {
            printf("%s %s\n", stu[i].name, stu[i].id);
            flag = true;
        }
    }
    if (!flag) {
        printf("NONE\n");
    }
    return 0;
}