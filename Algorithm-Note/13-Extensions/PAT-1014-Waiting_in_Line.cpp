//
// Created by authetic on 2018/11/2.
//

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1010;

struct Window {
    int endTime, popTime;
    queue<int> q;
}window[20];

// 窗口数，窗口人数上限，人数，查询数
int n, m, k, query, q;
int ans[maxn], needTime[maxn];

int convert(int hh, int mm) {
    return hh * 60 + mm;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &query);
    for (int i = 0; i < k; i ++ ) {
        scanf("%d", &needTime[i]);
    }
    for (int i = 0; i < n; i ++ ) {
        window[i].endTime = window[i].popTime = convert(8, 0);
    }
    int index = 0;
    for (int i = 0; i < min(m*n, k); i ++ ) {
        window[index % n].q.push(index);
        window[index % n].endTime += needTime[index];
        if (index < n) window[index].popTime = needTime[index];
        ans[index] = window[index % n].endTime;
        index++;
    }
    for (; index < k; index++) {
        int idx = -1, minTime = 1 << 30;
        for (int i = 0; i < n; i ++ ) {
            if (window[i].popTime < minTime) {
                idx = i;
                minTime = window[i].popTime;
            }
        }
        Window& w = window[idx];
        w.q.pop();
        w.q.push(index);
        w.endTime += needTime[index];
        // attention +=
        w.popTime += needTime[w.q.front()];
        ans[index] = w.endTime;
    }
    for (int i = 0; i < query; i ++ ) {
        scanf("%d", &q);
        if (ans[q-1] - needTime[q-1] >= convert(17, 0)) {
            printf("Sorry\n");
        }
        printf("%02d:%02d\n", ans[q-1] / 60, ans[q-1] % 60);
    }
    return 0;
}