//
// Created by authetic on 2018/8/16.
//

#include <cstdio>
#include <cstring>

const int maxn = 1010;
int hashtable[80]={0},miss=0;
int change(char c) {
    if (c>='0'&&c<='9') return c - '0';
    else if (c>='a'&&c<='z') return c-'a'+10;
    else return c - 'A'+36;
}

int main() {
    char str1[maxn];
    char str2[maxn];
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i=0; i<len1; i++) {
        hashtable[change(str1[i])]++;
    }
    for (int i=0; i<len2; i++) {
        hashtable[change(str2[i])]--;
        if (hashtable[change(str2[i])] < 0) {
            miss++;
        }
    }
    if (miss==0) {
        printf("Yes %d\n", len1-len2);
    } else {
        printf("No %d\n", miss);
    }
    return 0;
}