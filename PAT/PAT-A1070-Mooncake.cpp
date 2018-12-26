//
// Created by autheitc on 2018/12/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mooncake {
    double amount;
    double price, p;
};

bool cmp(Mooncake a, Mooncake b) {
    return a.p > b.p;
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    vector<Mooncake> v;
    Mooncake temp;
    for (int i = 0; i < n; i ++ ) {
        scanf("%lf", &temp.amount);
        v.push_back(temp);
    }
    for (int i = 0; i < n; i ++ ) {
        scanf("%lf", &v[i].price);
        v[i].p = v[i].price / v[i].amount;
    }
    sort(v.begin(), v.end(), cmp);
    double ans = 0;
    int index = 0;
    while (d > 0 && index < v.size()) {
        if (d >= v[index].amount) {
            d -= (int)v[index].amount;
            ans += v[index].price;
        } else {
            ans += v[index].price * (d / v[index].amount);
            d = 0;
        }
        index++;
    }
    printf("%.2f", ans);
    return 0;
}