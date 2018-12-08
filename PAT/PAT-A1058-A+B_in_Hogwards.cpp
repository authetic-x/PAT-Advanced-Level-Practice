//
// Created by authetic on 2018/12/8.
//

#include <iostream>
using namespace std;

int main() {
    long long g1, s1, k1, g2, s2, k2, g;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &g1, &s1, &k1, &g2, &s2, &k2);
    long long sum = k1 + s1 * 17 + g1 * 17 * 29 + k2 + s2 * 17 + g2 * 17 * 29;
    g = sum / (17 * 29);
    sum = sum % (17 * 29);
    printf("%lld.%lld.%lld", g, sum / 29, sum % 29);
    return 0;
}