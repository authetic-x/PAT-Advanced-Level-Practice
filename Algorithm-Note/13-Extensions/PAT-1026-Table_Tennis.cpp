//
// Created by authetic on 2018/11/2.
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
    bool isVip;
}newPlayer;

struct Table {
    int endTime, serveNum;
    bool isVip;
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
    while (vipi < player.size() && vipi == 0) {
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
    scanf("%d", &n);
    int stTime = convertTime(8, 0, 0);
    int edTime = convertTime(21, 0, 0);
    for (int i = 0; i < n; i ++ ) {
        int hh, mm, ss, playTime, isVIP;
        scanf("%02d:%02d:%02d %d %d", &hh, &mm, &ss
                , &playTime, &isVIP);
        newPlayer.arriveTime = convertTime(hh, mm, ss);
        if (newPlayer.arriveTime >= edTime) continue;
        newPlayer.startTime = edTime;
        newPlayer.playTime = playTime <= 120 ? playTime*60 : 7200;
        newPlayer.isVip = isVIP;
        player.push_back(newPlayer);
    }
    scanf("%d %d", &k, &m);
    for (int i = 0; i < k; i ++ ) {
        table[i].endTime = stTime;
        table[i].serveNum = table[i].isVip = 0;
    }
    for (int i = 0; i < m; i ++ ) {
        scanf("%d", &vipTable);
        table[vipTable-1].isVip = 1;
    }
    sort(player.begin(), player.end(), cmpArriveTime);
    int i = 0, vipi = -1;
    vipi = nextVipPlayer(vipi);

    while (i < player.size()) {
        int idx = -1, minEndTime = INF;
        for (int j = 0;j < k; j ++ ) {
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
                if (vipi == i) vipi = nextVipPlayer(vipi);
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
                int VIPidx = -1, minEndVIPTime = INF;
                for (int j = 0; j < k; j ++ ) {
                    if (table[j].isVip == 1 && table[j].endTime < minEndVIPTime) {
                        VIPidx = j;
                        minEndVIPTime = table[j].endTime;
                    }
                }
                if (VIPidx != -1 && player[i].arriveTime >= table[VIPidx].endTime) {
                    allowTable(i, VIPidx);
                    if (i == vipi) vipi = nextVipPlayer(vipi);
                    i++;
                } else {
                    allowTable(i, idx);
                    if (vipi == i) vipi = nextVipPlayer(vipi);
                    i++;
                }
            }
        }
    }
    sort(player.begin(), player.end(), cmpStartTime);
    for (i = 0; i < player.size() && player[i].startTime<edTime; i ++ ) {
        int t1 = player[i].arriveTime;
        int t2 = player[i].startTime;
        printf("%02d:%02d:%02d ", t1/3600, t1%3600/60, t1%60);
        printf("%02d:%02d:%02d ", t2/3600, t2%3600/60, t2%60);
        printf("%.0f\n", round(t2-t1) / 60.0);
    }
    for (i = 0; i < k; i ++ ) {
        printf("%d", table[i].serveNum);
        if (i != k-1) printf(" ");
    }
    return 0;
}