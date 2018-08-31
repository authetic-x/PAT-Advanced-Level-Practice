//
// Created by authetic on 2018/8/28.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct bign {
    int d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len=0;
    }
}p,q;

bign revert(bign a) {
    bign ans;
    for (int i=a.len-1; i>=0; i--) {
        ans.d[ans.len++] = a.d[i];
    }
    return ans;
}
bign add(bign a, bign b) {
    bign ans;
    int carry=0;
    for (int i=0; i<a.len||i<b.len; i++) {
        int temp = a.d[i]+b.d[i]+carry;
        ans.d[ans.len++] = temp%10;
        carry = temp/10;
    }
    while (carry!=0) {
        ans.d[ans.len++] = carry%10;
        carry /= 10;
    }
    return ans;
}
bool cmp(bign a, bign b) {
    for (int i=0; i<a.len; i++) {
        if (a.d[i]!=b.d[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char temp[11];
    int k;
    scanf("%s %d", temp, &k);
    for (int i=strlen(temp)-1; i>=0; i--) {
        p.d[p.len++] = temp[i]-'0';
    }
    q = revert(p);
    int step=0;
    while (!cmp(p,q)&&step<k) {
        p = add(p,q);
        q = revert(p);
        step++;
    }
    for (int i=p.len-1; i>=0; i--) {
        printf("%d", p.d[i]);
    }
    printf("\n");
    printf("%d\n", step);
    return 0;
}