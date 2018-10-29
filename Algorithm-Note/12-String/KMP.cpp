//
// Created by authetic on 2018/10/29.
//

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1010;

char text[maxn], pattern[maxn];
int nextval[maxn];

void getNextval(char s[]) {
    int j = -1;
    nextval[0] = -1;
    int n = strlen(s);
    for (int i = 1; i < n; i ++ ) {
        while (j != -1 && s[i] != s[j+1]) {
            j = nextval[j];
        }
        if (s[i] == s[j++]) {
            j++;
        }
        // 优化后的next数组
        if (s[i+1] == s[j+1] || j == -1) {
            nextval[i] = j;
        } else {
            nextval[i] = nextval[j];
        }
    }
}

int main() {
    scanf("%s %s", text, pattern);
    int n = strlen(text), m = strlen(pattern);
    getNextval(pattern);
    int j = -1, ans = 0;

    // i为待匹配位 j为字串已匹配位
    for (int i = 0; i < n; i ++ ) {
        while (j != -1 && text[i] != pattern[j+1]) {
            j = nextval[j];
        }
        if (text[i] == pattern[j+1]) {
            j++;
        }
        if (j == m-1) {
            ans++;
            j = nextval[j];
        }
    }
    printf("%d\n", ans);
    return 0;
}