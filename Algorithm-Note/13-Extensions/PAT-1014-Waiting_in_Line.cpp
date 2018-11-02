//
// Created by authetic on 2018/11/2.
//

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1010;
const int INF = 1000000000;

struct Window {
    int endTime, popTime;
    queue<int> q;
}window[20];

// 窗口数，窗口人数上限，人数，查询数
int n, m, k, query, q;
int ans[maxn], needTime[maxn];

int convertTime(int hh, int mm) {
    return hh * 60 + mm;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &query);
    for (int i = 0; i < k;  i ++ ) {
        scanf("%d", &needTime[i]);
    }
    for (int i = 0; i < n; i ++ ) {
        window[i].endTime = window[i].popTime = convertTime(8, 0);
    }
    int index = 0;
    for (int i = 0; i < min(n*m, k); i ++ ) {
        window[index % n].q.push(index);
        window[index % n].endTime += needTime[index];
        ans[index] = window[index % n].endTime;
        if (index < n) window[index % n].popTime = needTime[index];
        index++;
    }
    for (; index < k; index ++ ) {
        int idx = -1, minTime = INF;
        for (int i = 0; i < n; i ++ ) {
            if (window[i].popTime < minTime) {
                idx = i;
                minTime = window[i].popTime;
            }
        }
        window[idx].q.push(index);
        window[idx].endTime += needTime[index];
        ans[index] = window[idx].endTime;
        window[idx].q.pop();
        window[idx].popTime += needTime[window[idx].q.front()];
    }
    for (int i = 0; i < query; i ++ ) {
        scanf("%d", &q);
        if (ans[q-1] - needTime[q-1] >= convertTime(17, 0)) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", ans[q-1]/60, ans[q-1]%60);
        }
    }
    return 0;
}