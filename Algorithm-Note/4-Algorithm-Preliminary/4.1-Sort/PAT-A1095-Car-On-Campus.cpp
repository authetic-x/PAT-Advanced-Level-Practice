//
// Created by authetic on 2018/8/25.
/*
 * 基于时间的排序题，求时间段中校车在校辆数
 * key: 算你狠，错误硬是没找出来，估计是输入的地方错了，
 * 第六章再来解决你，注意排序的技巧，像这种配对问题，一定是
 * 先将名字一样的放在一起，再求出有效记录数！
 */
//

#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int N,K;
map<string, int>parkTime;

struct Record {
    char id[10];
    int time;
    char status[5];
}rec[maxn], valid[maxn];

bool cmpByIDtime(Record a, Record b) {
    if (!strcmp(a.id, b.id)) return strcmp(a.id, b.id)<0;
    else return a.time < b.time;
}
bool cmpByTime(Record a, Record b) {
    return a.time < b.time;
}
int time2num(int hh, int mm, int ss) {
    return hh*60*60 + mm*60 + ss;
}

int main() {
    scanf("%d %d", &N, &K);
    int hh,mm,ss;
    for (int i=0; i<N; i++) {
        scanf("%s %d:%d:%d %s", rec[i].id, &hh,&mm,&ss,rec[i].status);
        rec[i].time = time2num(hh,mm,ss);
    }
    sort(rec, rec+N, cmpByIDtime);
    int num=0;          //有效记录数
    int maxTime = -1;
    for (int i=0; i<N-1; i++) {
        if (!strcmp(rec[i].id,rec[i+1].id) &&
                !strcmp(rec[i].status, "in") &&
                !strcmp(rec[i+1].status, "out")) {
            valid[num++] = rec[i];
            valid[num++] = rec[i+1];
            int thisTime = rec[i+1].time - rec[i].time;
            if (parkTime.count(rec[i].id)==0) {
                parkTime[rec[i].id] = 0;
            }
            parkTime[rec[i].id] += thisTime;
            maxTime = max(maxTime, parkTime[rec[i].id]);
        }
    }
    sort(valid, valid+num, cmpByTime);
    int now=0, numCar=0;
    for (int i=0; i<K; i++) {
        int h,m,s;
        scanf("%d:%d:%d", &h, &m, &s);
        int time = time2num(h,m,s);
        while (now<num && valid[now].time<=time) {
            if (!strcmp(valid[now].status, "in")) numCar++;
            else numCar--;
            now++;
        }
        printf("%d\n", numCar);
    }
    map<string, int>::iterator it;
    for (it=parkTime.begin(); it!=parkTime.end(); it++) {
        if (it->second == maxTime) {
            printf("%s ", it->first.c_str());
        }
    }
    printf("%02d:%02d:%02d\n", maxTime/3600, maxTime%3600/60, maxTime%60);
    return 0;
}