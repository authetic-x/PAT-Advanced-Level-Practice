//
// Created by authetic on 2018/8/15.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=100010;
struct student {
    char id[10];
    char name[10];
    int grade;
}stu[maxn];

bool cmp1(student a, student b) {
    return strcmp(a.id,b.id) < 0;
}
bool cmp2(student a, student b) {
    if (strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
    else return strcmp(a.id,b.id)<0;
}
bool cmp3(student a, student b) {
    if (a.grade!=b.grade) return a.grade<b.grade;
    else return strcmp(a.id,b.id)<0;
}

int main() {
    int n,k;
    scanf("%d %d", &n,&k);
    for (int i=0; i<n; i++) {
        scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].grade);
    }
    if (k==1) {
        sort(stu, stu+n, cmp1);
    } else if (k==2) {
        sort(stu, stu+n, cmp2);
    } else {
        sort(stu, stu+n, cmp3);
    }
    for (int i=0; i<n; i++) {
        printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    }
    return 0;
}
