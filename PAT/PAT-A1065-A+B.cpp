//
// Created by authetic on 2018/12/13.
/*
 * 考虑sum溢出的可能情况即可
 */
//

#include <iostream>
using namespace std;

int main() {
    int t;
    long long a, b, c;
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++ ) {
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if (a > 0 && b > 0 && sum < 0) printf("Case #%d: true\n", i);
        else if (a < 0 && b < 0 && sum >= 0) printf("Case #%d: false\n", i);
        else if (a + b > c) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
    return 0;
}