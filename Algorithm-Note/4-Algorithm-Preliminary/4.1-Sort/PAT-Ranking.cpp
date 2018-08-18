//
// Created by authetic on 2018/8/15.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 30010;
struct student {
    char number[15];
    int score;
    int location;
    int l_rank,f_rank;
}stu[maxn];

bool cmp(student a, student b) {
    if (a.score!=b.score) return a.score>b.score;
    else return strcmp(a.number,b.number)<0;
}

int main() {
    int n,num=0,k;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &k);
        for (int j=0; j<k; j++) {
            scanf("%s %d", stu[num].number, &stu[num].score);
            stu[num].location = i+1;
            num++;
        }
        sort(stu+num-k, stu+num, cmp);
        stu[num-k].l_rank = 1;
        for (int j=1; j<k; j++) {
            if (stu[num-k+j].score==stu[num-k+j-1].score) {
                stu[num-k+j].l_rank = stu[num-k+j-1].l_rank;
            } else {
                stu[num-k+j].l_rank = j+1;
            }
        }
    }
    sort(stu, stu+num, cmp);
    stu[0].f_rank = 1;
    printf("%d\n", num);
    printf("%s %d %d %d\n", stu[0].number, stu[0].f_rank, stu[0].location, stu[0].l_rank);
    for (int i=1; i<num; i++) {
        if (stu[i].score==stu[i-1].score) {
            stu[i].f_rank = stu[i-1].f_rank;
        } else {
            stu[i].f_rank = i+1;
        }
        printf("%s %d %d %d\n", stu[i].number, stu[i].f_rank, stu[i].location, stu[i].l_rank);
    }
    return 0;
}