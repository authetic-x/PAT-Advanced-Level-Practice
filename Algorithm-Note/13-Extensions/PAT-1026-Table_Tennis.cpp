//
// Created by authetic on 2018/11/2.
/*
 * 模拟排队问题
 * 目前花了最长时间的题目，本身不难，但是很复杂，细节处理不好就通不过
 * 这类题目做法一般是先把用户时间整数化，按时间排序存放在vector里面；然后
 * 将各个窗口信息存在数组里，每次找出最先空闲的窗口，算出下次结束时间
 * 和用户等待时间， 依次遍历完vector里的用户数。
 */
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int K = 110;
const int INF = 1000000000;

struct Player {
    int arriveTime, playTime, startTime;
    int isVip;
}newPlayer;

struct Table {
    int endTime, serveNum;
    int isVip;
}table[K];

vector<Player> player;

bool cmpArriveTime(Player a, Player b) {
    return a.arriveTime < b.arriveTime;
}

bool cmpStartTime(Player a, Player b) {
    return a.startTime < b.startTime;
}

int convertTime(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int nextVipPlayer(int vipi) {
    vipi++;
    while (vipi < player.size() && player[vipi].isVip == 0) {
        vipi++;
    }
    return vipi;
}

void allowTable(int pId, int tId) {
    if (player[pId].arriveTime <= table[tId].endTime) {
        player[pId].startTime = table[tId].endTime;
    } else {
        player[pId].startTime = player[pId].arriveTime;
    }
    table[tId].endTime = player[pId].startTime + player[pId].playTime;
    table[tId].serveNum++;
}

int main() {
    int n, k, m, vipTable;
    int stTime = convertTime(8, 0, 0);
    int edTime = convertTime(21, 0, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        int hh, mm, ss, playTime, isVip;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &playTime, &isVip);
        newPlayer.arriveTime = convertTime(hh, mm, ss);
        if (newPlayer.arriveTime > edTime) continue;
        newPlayer.playTime = playTime <= 120 ? playTime*60 : 7200;
        newPlayer.isVip = isVip;
        newPlayer.startTime = edTime;
        player.push_back(newPlayer);
    }
    scanf("%d %d", &k, &m);
    for (int i = 1; i <= k; i ++ ) {
        table[i].isVip = 0;
        table[i].endTime = stTime;
        table[i].serveNum = 0;
    }
    for (int i = 0; i < m; i ++ ) {
        scanf("%d", &vipTable);
        table[vipTable].isVip = 1;
    }
    sort(player.begin(), player.end(), cmpArriveTime);
    int i = 0, vipi = -1;
    vipi = nextVipPlayer(vipi);
    while (i < player.size()) {
        int idx = -1, minEndTime = INF;
        for (int j = 1; j <= k; j ++ ) {
            if (table[j].endTime < minEndTime) {
                idx = j;
                minEndTime = table[j].endTime;
            }
        }
        if (table[idx].endTime >= edTime) break;
        if (player[i].isVip == 1 && i < vipi) {
            i++;
            continue;
        }
        if (table[idx].isVip == 1) {
            if (player[i].isVip == 1) {
                allowTable(i, idx);
                vipi = nextVipPlayer(vipi);
                i++;
            } else {
                if (vipi < player.size() && player[vipi].arriveTime
                        <= table[idx].endTime) {
                    allowTable(vipi, idx);
                    vipi = nextVipPlayer(vipi);
                } else {
                    allowTable(i, idx);
                    i++;
                }
            }
        } else {
            if (player[i].isVip == 0) {
                allowTable(i, idx);
                i++;
            } else {
                int idxVIP = -1, minTime = INF;
                for (int j = 1; j <= k; j ++ ) {
                    if (table[j].isVip == 1 && table[j].endTime < minTime) {
                        idxVIP = j;
                        minTime = table[j].endTime;
                    }
                }
                if (idxVIP != -1 && player[i].arriveTime >= table[idxVIP].endTime) {
                    allowTable(i, idxVIP);
                    vipi = nextVipPlayer(vipi);
                    i++;
                } else {
                    allowTable(i, idx);
                    vipi = nextVipPlayer(vipi);
                    i++;
                }
            }
        }
    }
    sort(player.begin(), player.end(), cmpStartTime);
    for (i = 0; i < player.size() && player[i].startTime < edTime; i ++ ) {
        int t1 = player[i].arriveTime;
        int t2 = player[i].startTime;
        printf("%02d:%02d:%02d ", t1/3600, t1%3600/60, t1%60);
        printf("%02d:%02d:%02d ", t2/3600, t2%3600/60, t2%60);
        printf("%.0f\n", round((t2 - t1) / 60.0));
    }
    for (i = 1; i <= k; i ++ ) {
        printf("%d", table[i].serveNum);
        if (i != k) printf(" ");
    }
    return 0;
}