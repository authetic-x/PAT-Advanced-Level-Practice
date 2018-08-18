//
// Created by authetic on 2018/8/17.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=510;
const int INF = 100000000;
double minPrice;          //当前找到的最小价格
double Cmax,D,Davg;       //最大容量、距离、单位行驶距离

struct Station {
    double price,dis;
}sta[maxn];

bool cmp(Station a, Station b) {
    return a.dis < b.dis;
}

int main() {
    int N;
    scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &N);
    for (int i=0; i<N; i++) {
        scanf("%lf %lf", &sta[i].price, &sta[i].dis);
    }
    sort(sta, sta+N, cmp);
    if (sta[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    sta[N].price = 0;
    sta[N].dis = D;
    int now=0;                       //当前油站编号
    double ans=0, nowTank=0;         //总花费，当前油量
    double Maxdis = Cmax * Davg;     //满油行驶的最远距离
    while (now < N) {
        int k = -1;
        minPrice = INF;
        for (int i=now+1; i<=N && sta[i].dis<=sta[now].dis+Maxdis; i++) {
            if (sta[i].price < minPrice) {
                k = i;
                minPrice = sta[i].price;
                if (minPrice < sta[now].price) {
                    break;
                }
            }
        }
        if (k==-1) break;
        double need = (sta[k].dis-sta[now].dis)/Davg;
        if (minPrice < sta[now].price) {
            if (need > nowTank) {
                ans += (need-nowTank) * sta[now].price;
                nowTank = 0;
            } else {
                nowTank -= need;
            }
        } else {
            ans += (Cmax-nowTank) * sta[now].price;
            nowTank = Cmax - need;
        }
        now = k;
    }
    if (now == N) {
        printf("%.2f\n", ans);
    } else {
        printf("The maximum travel distance = %.2f\n", sta[now].dis+Maxdis);
    }
    return 0;
}
