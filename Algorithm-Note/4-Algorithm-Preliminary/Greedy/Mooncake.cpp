//
// Created by authetic on 2018/8/17.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
struct mooncake {
    double store;
    double sell;
    double price;
}mo[maxn];
bool cmp(mooncake a, mooncake b) {
    return a.price>b.price;
}

int main() {
    int n,num;
    scanf("%d %d", &n, &num);
    for (int i=0; i<n; i++) {
        scanf("%lf", &mo[i].store);
    }
    for (int i=0; i<n; i++) {
        scanf("%lf", &mo[i].sell);
        mo[i].price = mo[i].sell/mo[i].store;
    }
    sort(mo, mo+n, cmp);
    double ans = 0;
    for (int i=0; i<n; i++) {
        if (num >= mo[i].store) {
            ans += mo[i].price*mo[i].store;
            num -= mo[i].store;
        } else {
            ans += mo[i].price*num;
            break;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}
