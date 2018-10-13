//
// Created by authetic on 2018/10/11.
/*
 * 条条大路通罗马
 * Note: Dijsktra算法问题，求最短路径个数可以用vector存储后计算
 * 也可以用数组直接存储，字符串转索引不用用hash，直接用两个map，然后
 * 注意求点数，边的条数的写法！
 */
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

const int maxn = 210;
const int INF = 1000000000;

int n,k,G[maxn][maxn],weight[maxn];
int num[maxn],pt[maxn],w[maxn],d[maxn],pre[maxn];
bool vis[maxn] = {false};
map<string, int> strToInt;
map<int, string> intToStr;

void Dijkstra(int s) {
    fill(d, d+maxn, INF);
    memset(num, 0, sizeof(num));
    memset(pt, 0, sizeof(pt));
    memset(w, 0, sizeof(w));
    for (int i=0; i<maxn; i++) pre[i] = i;
    d[s] = 0;
    num[s] = 1;
    w[s] = weight[s];
    for (int i=0; i<n; i++) {
        int u=-1, MIN=INF;
        for (int j=0; j<n; j++) {
            if (!vis[j] && d[j]<MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v=0; v<n; v++) {
            if (!vis[v] && G[u][v]!=INF) {
                if (d[u]+G[u][v] < d[v]) {
                    d[v] = d[u]+G[u][v];
                    pre[v] = u;
                    num[v] = num[u];
                    pt[v] = pt[u]+1;
                    w[v] = w[u]+weight[v];
                } else if (d[u]+G[u][v] == d[v]) {
                    num[v] += num[u];
                    if (w[u]+weight[v] > w[v]) {
                        w[v] = w[u]+weight[v];
                        pt[v] = pt[u]+1;
                        pre[v] = u;
                    } else if (w[u]+weight[v] == w[v]) {
                        double uAvg = 1.0*(w[u]+weight[v])/(pt[u]+1);
                        double vAvg = 1.0*w[v]/pt[v];
                        if (uAvg > vAvg) {
                            pre[v] = u;
                            pt[v] = pt[u]+1;
                        }
                    }
                }
            }
        }
    }
}

void print(int v) {
    if (v == 0) {
        cout << intToStr[v];
        return;
    }
    print(pre[v]);
    cout << "->" << intToStr[v];
}

int main() {
    string st,c1,c2;
    cin >> n >> k >> st;
    intToStr[0] = st;
    strToInt[st] = 0;
    for (int i=1; i<=n-1; i++) {
        cin >> c1 >> weight[i];
        intToStr[i] = c1;
        strToInt[c1] = i;
    }
    fill(G[0], G[0]+maxn*maxn, INF);
    for (int i=0; i<k; i++) {
        cin >> c1 >> c2;
        int u=strToInt[c1], v=strToInt[c2];
        cin >> G[u][v];
        G[v][u] = G[u][v];
    }
    Dijkstra(0);
    int rom = strToInt["ROM"];
    printf("%d %d %d %d\n", num[rom], d[rom], w[rom], w[rom]/pt[rom]);
    print(rom);
    return 0;
}