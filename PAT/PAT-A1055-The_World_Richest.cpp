//
// Created by authetic on 2018/12/8.
/*
 * 有点自做聪明了，可以直接暴力解决，多次排序必定超时，每个年龄段最多取100
 * 可以做个优化
 */
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Man {
    char name[10];
    int age, wealth;
}man[maxn];

int n, k, m;
int minA, maxA;
vector<Man> v;
vector<int> book(205, 0);

bool cmp(Man a, Man b) {
    if (a.wealth != b.wealth) return a.wealth > b.wealth;
    else if (a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++ ) {
        scanf("%s", man[i].name);
        scanf("%d %d", &man[i].age, &man[i].wealth);
    }
    sort(man, man+n, cmp);
    for (int i = 0; i < n; i ++ ) {
        if (book[man[i].age] < 100) {
            v.push_back(man[i]);
            book[man[i].age]++;
        }
    }
    for (int i = 0; i < k; i ++ ) {
        scanf("%d %d %d", &m, &minA, &maxA);
        printf("Case #%d:\n", i + 1);
        int flag = 0;
        for (int j = 0; j < v.size(); j ++ ) {
            if (flag == m) break;
            if (v[j].age >= minA && v[j].age <= maxA) {
                printf("%s %d %d\n", v[j].name, v[j].age, v[j].wealth);
                flag++;
            }
        }
        if (flag == 0) printf("None\n");
    }
    return 0;
}