//
// Created by hp on 2018/8/16.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=100010;
struct people {
    char name[10];
    int age;
    int worth;
}pro[maxn],val[maxn];
bool cmp(people a, people b) {
    if (a.worth!=b.worth) return a.worth>b.worth;
    else if (a.age!=b.age) return a.age<b.age;
    else return strcmp(a.name, b.name) < 0;
}

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%s %d %d", pro[i].name, &pro[i].age, &pro[i].worth);
    }
    sort(pro, pro+n, cmp);
    int age[210] = {0};
    int num=0;
    for (int i=0; i<n; i++) {
        if (age[pro[i].age] < 100) {
            age[pro[i].age]++;
            val[num++] = pro[i];
        }
    }
    for (int i=0; i<k; i++) {
        int max_num,max_age,min_age;
        scanf("%d %d %d", &max_num, &min_age, &max_age);
        printf("Case #%d:\n", i+1);
        int count=0;
        for (int j=0; j<num && count<max_num; j++) {
            if (val[i].age>=min_age&&val[i].age<=max_age) {
                count++;
                printf("%s %d %d\n", val[i].name, val[i].age, val[i].worth);
            }
        }
        if (count==0) {
            printf("None\n");
        }
    }
    return 0;
}
