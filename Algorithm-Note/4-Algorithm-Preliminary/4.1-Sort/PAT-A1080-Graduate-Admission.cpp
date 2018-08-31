//
// Created by authetic on 2018/8/25.
/*
 * 模拟学校录取过程
 * key: 依旧是一道基础排序题，30分原因可能是比较麻烦，
 * 少见的需要设置两个结构体，不过失误率有所降低，坑都是
 * 自己挖的，注意命名和排序的临界问题！
 */
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 40010;
int N,M,K;                //学生数，学校数，选择数

struct Student {
    int id;
    int ge;
    int gi;
    int choice[6];
    int rank;
}stu[maxn];
struct School {
    int quota;
    int num=0;
    int student[maxn]={0};
    int lastAdmit;
}sch[100];

bool cmp(Student a, Student b) {
    if ((a.ge+a.gi)!=(b.ge+b.gi)) return (a.ge+a.gi)>(b.ge+b.gi);
    else return a.ge>b.ge;
}

int main() {
    scanf("%d %d %d", &N,&M,&K);
    for (int i=0; i<M; i++) {
        scanf("%d", &sch[i].quota);
    }
    for (int i=0; i<N; i++) {
        stu[i].id = i;
        scanf("%d %d", &stu[i].ge, &stu[i].gi);
        for (int j=1; j<=K; j++) {
            scanf("%d", &stu[i].choice[j]);
        }
    }
    sort(stu, stu+N, cmp);
    stu[0].rank = 0;
    for (int i=0; i<N; i++) {
        if (i>0) {
            if ((stu[i].ge+stu[i].gi)==(stu[i-1].ge+stu[i-1].gi)
                    && stu[i].ge==stu[i-1].ge) {
                stu[i].rank = stu[i-1].rank;
            } else {
                stu[i].rank = i;
            }
        }
        for (int j=1; j<=K; j++) {
            int k = stu[i].choice[j];
            if (sch[k].quota-sch[k].num>0) {
                sch[k].num++;
                sch[k].student[sch[k].num] = stu[i].id;
                sch[k].lastAdmit = stu[i].id;
                break;
            } else if (i>0&&stu[i].rank==stu[i-1].rank){
                if (stu[i-1].id==sch[k].lastAdmit) {
                    sch[k].num++;
                    sch[k].student[sch[k].num] = stu[i].id;
                    sch[k].lastAdmit = stu[i].id;
                    break;
                }
            }
        }
    }
    for (int i=0; i<M; i++) {
        if (sch[i].num!=0) {
            sort(sch[i].student+1, sch[i].student+sch[i].num+1);
            for (int j=1; j<=sch[i].num-1; j++) {
                printf("%d ", sch[i].student[j]);
            }
            printf("%d", sch[i].student[sch[i].num]);
        }
        printf("\n");
    }
    return 0;
}