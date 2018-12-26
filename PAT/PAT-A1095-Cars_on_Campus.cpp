//
// Created by authetic on 2018/12/26.
/*
 * 我真的是服了！
 */
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10010;

struct Record {
    char id[10];
    int time, flag;
}record[maxn], valid[maxn];

int N, K;
map<string, int> parkTime;

bool cmpByidTime(Record a, Record b) {
    if (strcmp(a.id, b.id) != 0) {
        return strcmp(a.id, b.id) < 0;
    }
    return a.time < b.time;
}

bool cmpByTime(Record a, Record b) {
    return a.time < b.time;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i ++ ) {
        char temp[5];
        int h, m, s;
        scanf("%s %d:%d:%d %s", record[i].id, &h, &m, &s, temp);
        record[i].time = h * 3600 + m * 60 + s;
        if (strcmp("in", temp) == 0) record[i].flag = 1;
        else record[i].flag = -1;
    }
    sort(record, record + N, cmpByidTime);
    int num = 0, maxTime = -1;
    for (int i = 0; i < N-1; i ++ ) {
        if (!strcmp(record[i].id, record[i+1].id) && record[i].flag == 1 &&
            record[i+1].flag == -1) {
            valid[num++] = record[i];
            valid[num++] = record[i+1];
            if (parkTime.count(record[i].id) == 0) {
                parkTime[record[i].id] = 0;
            }
            parkTime[record[i].id] += record[i+1].time - record[i].time;
            if (parkTime[record[i].id] > maxTime) {
                maxTime = parkTime[record[i].id];
            }
        }
    }
    sort(valid, valid + num, cmpByTime);
    int now = 0, numcar = 0;
    for (int i = 0; i < K; i ++ ) {
        int h, m, s, tempTime, tempindex = 0;
        scanf("%d %d %d", &h, &m, &s);
        tempTime = h * 3600 + m * 60 + s;
        while (now < num && tempTime >= valid[now].time) {
            if (valid[now].flag == 1) numcar ++;
            else numcar --;
            now++;
        }
        printf("%d\n", numcar);
    }
    for (map<string, int>::iterator it = parkTime.begin(); it != parkTime.end(); it ++ ) {
        if (it->second == maxTime) {
            printf("%s ", it->first.c_str());
        }
    }
    printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
    return 0;
}