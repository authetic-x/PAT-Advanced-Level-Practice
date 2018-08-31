//
// Created by authetic on 2018/8/27.
/*
 * 再一次变量名写错！！！ No meaningful wrong!
 */
//

#include <cstdio>
#include <cmath>

const int maxn = 10010;

int arr[maxn],mSize,num;

bool isPrime(int n) {
    if (n<=1) return false;
    bool flag = true;
    for (int i=2; i<=sqrt(n); i++) {
        if (n%i==0) {
            flag = false;
        }
    }
    return flag;
}

int main() {
    scanf("%d %d", &mSize, &num);
    while(!isPrime(mSize)) {
        mSize++;
    }
    for (int i=0; i<mSize; i++) {
        arr[i] = -1;
    }
    for (int i=0; i<num; i++) {
        int temp;
        scanf("%d", &temp);
        int pos = temp%mSize;
        if (arr[pos]==-1) {
            arr[pos] = temp;
            if (i==0) printf("%d", pos);
            else printf(" %d", pos);
        } else {
            int j;
            for (j=1; j<mSize; j++) {
                pos = (temp+j*j)%mSize;
                if (arr[pos]==-1) {
                    arr[pos] = temp;
                    if (i==0) printf("%d", pos);
                    else printf(" %d", pos);
                    break;
                }
            }
            if (j>=mSize) {
                if (i==0) printf("-");
                else printf(" -");
            }
        }
    }
    printf("\n");
    return 0;
}