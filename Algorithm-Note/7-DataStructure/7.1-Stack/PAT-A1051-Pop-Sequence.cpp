//
// Created by authetic on 2018/9/6.
/*
 * 将一组数列顺序入栈，判断给出的出栈序列是否可行
 * key: 栈的基本运用，不用麻烦的标记变量，直接再入栈的
 * 过程中判断，最后看栈的大小是否越界即可
 */
//

#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1010;

int m,n,k;
stack<int> s;
int arr[maxn];

int main() {
    scanf("%d %d %d", &m, &n, &k);
    while (k--) {
        while (!s.empty()) s.pop();
        for (int i=1; i<=n; i++) {
            scanf("%d", &arr[i]);
        }
        int cur=1;
        bool flag = true;
        for (int i=1; i<=n; i++) {
            s.push(i);
            if (s.size()>m) {
                flag = false;
                break;
            }
            while (!s.empty() && s.top()==arr[cur]) {
                s.pop();
                cur++;
            }
        }
        if (s.empty() && flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}