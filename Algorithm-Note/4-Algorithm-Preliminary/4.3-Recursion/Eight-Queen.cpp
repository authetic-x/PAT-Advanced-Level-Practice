//
// Created by authetic on 2018/8/16.
//
#include <cstdio>
#include <cmath>
#include <cstdlib>

const int maxn = 10;
bool hashtable[10] = {false};
int p[maxn]={0},n=8,count=0;

void generate(int index) {
    if (index == n+1) {
        count++;
        return;
    }
    for (int i=1; i<=n; i++) {
        if (!hashtable[i]) {
            bool flag = true;
            for (int pre=1; pre<index; pre++) {
                if (abs(index-pre)==abs(i-p[pre])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                p[index] = i;
                hashtable[i] = true;
                generate(index+1);
                hashtable[i] = false;
            }
        }
    }
}

int main() {
    generate(1);
    printf("%d", count);
    return 0;
}
