//
// Created by authetic on 2018/8/27.
/*
 * 将一个整数作质因子分解
 * key: Simple problem, get a list of prime first, which's maximum
 * will not bigger than the n. Next, sorted them and put them in a
 * circle to judge whether the prime is a factor of the n.
 */
//

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const int maxn = 1000000;
ll primeArray[maxn];

struct prime {
    ll num;
    int count=0;
}pri[20];

bool isPrime(ll n) {
    if (n<=1) return false;
    for (int i=2; i<=sqrt(n); i++) {
        if (n%i==0) return false;
    }
    return true;
}

int init(ll n) {
    int count=0;
    for (int i=2; i<=sqrt(n); i++) {
        if (isPrime(i)) {
            primeArray[count++] = i;
            primeArray[count++] = n/i;
        }
    }
    return count;
}

int main() {
    ll n;
    scanf("%lld", &n);
    int len = init(n);
    printf("%lld=", n);
    sort(primeArray, primeArray+len);
    int count=0;
    if (isPrime(n) || n==1) {
        printf("%lld\n", n);
        return 0;
    }
    for (int i=0; i<len; i++) {
        bool flag = false;
        if (n==1) break;
        while (n%primeArray[i]==0) {
            flag = true;
            if (pri[count].count==0) {
                pri[count].num = primeArray[i];
                pri[count].count = 1;
            } else {
                pri[count].count++;
            }
            n /= primeArray[i];
        }
        if (flag) count++;
    }
    for (int i=0; i<count; i++) {
        if (i==0) {
            if (pri[i].count==1) printf("%lld", pri[i].num);
            else printf("%lld^%d", pri[i].num, pri[i].count);
        } else {
            if (pri[i].count==1) printf("*%lld", pri[i].num);
            else printf("*%lld^%d", pri[i].num, pri[i].count);
        }
    }
    printf("\n");
    return 0;
}