//
// Created by authetic on 2018/9/27.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn = 2010;

map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> gang;

int G[maxn][maxn] = {0}, weight[maxn] = {0};
int n, k, numPerson=0;
bool vis[maxn] = {false};

void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
    vis[nowVisit] = true;
    numMember++;
    if (weight[nowVisit] > weight[head]) {
        head = nowVisit;
    }
    for (int i=0; i<n; i++) {
        if (G[nowVisit][i] > 0) {
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if (!vis[i]) {
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}

void DFSTrave() {
    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            int head=i, numMember=0, totalValue=0;
            DFS(i, head, numMember, totalValue);
            if (numMember>2 && totalValue>k) {
                gang[intToString[head]] = numMember;
            }
        }
    }
}

int change(string str) {
    if (stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];
    } else {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}

int main() {
    cin >> n >> k;
    string str1, str2;
    int w;
    for (int i=0; i<n; i++) {
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        G[id1][id2] += w;
        G[id2][id1] += w;
        weight[id1] += w;
        weight[id2] += w;
    }
    DFSTrave();
    cout << gang.size() << endl;
    map<string, int>::iterator it;
    for (it = gang.begin(); it != gang.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}