//
// Created by authetic on 2018/8/16.
//

#include <cstdio>
#include <cstring>

const int maxn = 10010;
bool hashtable[128] = {false};

int main() {
    char str1[maxn];
    char str2[maxn];
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i=0; i<len2; i++) {
        int a = str2[i];
        hashtable[a] = true;
    }
    for (int i=0; i<len1; i++) {
        int a = str1[i];
        if (!hashtable[a]) {
            printf("%c", str1[i]);
        }
    }
    return 0;
}
