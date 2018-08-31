//
// Created by authetic on 2018/8/26.
/*
 * key： 注意进制转换
 */
//

#include <cstdio>
#include <cmath>
using namespace std;

int n,radix,d[111];

bool isPrime(int num) {
    if (num<=1) return false;
    int n = (int) sqrt(num);
    for (int i=2; i<=n; i++) {
        if (num%i==0) {
            return false;
        }
    }
    return true;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        if (n<0) break;
        scanf("%d", &radix);
        if (!isPrime(n)) {
            printf("No\n");
        } else {
            int count=0;
            do {
                d[count++] = n%radix;
                n /= radix;
            }while(n!=0);
            for (int i=0; i<count; i++) {
                n = n*radix + d[i];
            }
            if (isPrime(n)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}