//
// Created by authetic on 2018/10/10.
/*
 * 多个加油站待测站点，求到所有楼房的最短路径值最大的那个站点，如果值相同看距离平均值
 * Dijsktra算法问题，字符串G1等用后面的数字加n取代，测试只能拿20分，应该平均值的问题！
 */
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1020;
const int INF = 1000000000;

int n,m,k,DS;
int G[maxn][maxn],d[maxn];
bool vis[maxn] = {false};

void Dijsktra(int s) {
    fill(d, d+maxn, INF);
    memset(vis, false, sizeof(vis));
    d[s] = 0;
    for (int i=0; i<n+m; i++) {
        int u=-1, MIN=INF;
        for (int j=1; j<=n+m; j++) {
            if (!vis[j] && d[j]<MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v=1; v<=n+m; v++) {
            if (!vis[v] && G[u][v]!=INF && d[u]+G[u][v]<d[v]) {
                d[v] = d[u]+G[u][v];
            }
        }
    }
}

int getId(char s[]) {
    int i=0,id=0,len=strlen(s);
    while (i < len) {
        if (s[i] != 'G') {
            id = id*10+(s[i]-'0');
        }
        i++;
    }
    if (s[0] == 'G') return n+id;
    return id;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &DS);
    fill(G[0], G[0]+maxn*maxn, INF);
    int u,v;
    char s1[5],s2[5];
    for (int i=0; i<k; i++) {
        scanf("%s %s", s1, s2);
        u = getId(s1);
        v = getId(s2);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    double ansDis=-1, ansAvg=INF;
    int ansId;
    for (int i=n+1; i<=n+m; i++) {
        Dijsktra(i);
        double minDis=INF,avg=0;
        for (int j=1; j<=n; j++) {
            if (d[j] > DS) break;
            if (d[j] < minDis) {
                minDis = d[j];
            }
            avg += 1.0*d[j] / n;
        }
        if (minDis == -1) continue;
        if (minDis > ansDis) {
            ansDis = minDis;
            ansId = i-n;
            ansAvg = avg;
        } else if (minDis==ansDis && avg<ansAvg) {
            ansAvg = avg/n;
            ansId = i-n;
        }
    }
    if (ansDis == -1) printf("No Solution\n");
    else {
        printf("G%d\n", ansId);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }
    return 0;
}