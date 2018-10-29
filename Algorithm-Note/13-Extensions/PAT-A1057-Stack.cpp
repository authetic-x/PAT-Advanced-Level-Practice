//
// Created by authetic on 2018/10/29.
//

#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 100010;
const int sqrN = 316;

int block[sqrN], table[maxn];
stack<int> st;

void PeekMedian(int k) {
    int sum=0, idx=0;
    while (sum+block[idx] < k) {
        sum += block[idx++];
    }
    int num = idx * sqrN;
    while (sum+table[num] < k) {
        sum += table[num++];
    }
    printf("%d\n", num);
}

void Push(int x) {
    st.push(x);
    block[x / sqrN]++;
    table[x]++;
}

void Pop() {
    int x = st.top();
    st.pop();
    block[x / sqrN]--;
    table[x]--;
    printf("%d\n", x);
}

int main() {
    int n, x;
    char cmd[20];
    memset(block, 0, sizeof(block));
    memset(table, 0, sizeof(table));

    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        scanf("%s", cmd);
        if (strcmp(cmd, "Push") == 0) {
            scanf("%d", &x);
            Push(x);
        } else if (strcmp(cmd, "Pop") == 0) {
            if (st.empty()) {
                printf("Invalid\n");
            } else {
                Pop();
            }
        } else {
            int k = (st.size()/2==0) ? st.size()/2 : (st.size()+1)/2;
            PeekMedian(k);
        }
    }
    return 0;
}