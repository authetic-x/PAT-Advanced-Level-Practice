//
// Created by authetic on 2018/11/2.
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 111;
const int INF = 1000000000;

struct Custom {
    int cometime;
    int servetime;
}newCustomer;

vector<Custom> custom;
int c,k;
int endTime[maxn];

bool cmp (Custom a, Custom b) {
    return a.cometime < b.cometime;
}

int convert(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int main() {
    int tolTime = 0;
    int stTime = convert(8, 0, 0);
    int edTime = convert(17, 0, 0);
    scanf("%d %d", &c, &k);
    int hh, mm, ss, servetime;
    for (int i = 0; i < k; i ++ ) endTime[i] = stTime;
    for (int i = 0; i < c; i ++ ) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &servetime);
        int cometime = convert(hh, mm, ss);
        if (cometime > edTime) continue;
        newCustomer.cometime = cometime;
        newCustomer.servetime = (servetime <= 60) ? servetime * 60 : 3600;
        custom.push_back(newCustomer);
    }
    sort(custom.begin(), custom.end(), cmp);
    for (int i = 0; i < custom.size(); i ++ ) {
        int minEndtime = INF, idx = -1;
        for (int j = 0; j < k; j ++ ) {
            if (endTime[j] < minEndtime) {
                idx = j;
                minEndtime = endTime[j];
            }
        }
        if (endTime[idx] <= custom[i].cometime) {
            endTime[idx] = custom[i].cometime + custom[i].servetime;
        } else {
            tolTime += (endTime[idx] - custom[i].cometime);
            endTime[idx] += custom[i].servetime;
        }
    }
    if (custom.size() == 0) printf("0.0\n");
    else {
        printf("%.1f\n", tolTime / 60.0 / custom.size());
    }
    return 0;
}