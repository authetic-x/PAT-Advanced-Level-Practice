//
// Created by authetic on 2018/12/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int num, talent, virtue;
};

vector<Node> v[4];

bool cmp(Node a, Node b) {
    if (a.virtue + a.talent != b.virtue + b.talent) {
        return a.virtue + a.talent > b.virtue + b.talent;
    } else if (a.virtue != b.virtue) {
        return a.virtue > b.virtue;
    } else {
        return a.num < b.num;
    }
}

int main() {
    int n, low, high;
    scanf("%d %d %d", &n, &low, &high);
    int total = n;
    Node temp;
    for (int i = 0; i < n; i ++ ) {
        scanf("%d %d %d", &temp.num, &temp.virtue, &temp.talent);
        if (temp.virtue < low || temp.talent < low) {
            total--;
            continue;
        }
        if (temp.virtue >= high && temp.talent >= high) v[0].push_back(temp);
        else if (temp.virtue >= high) v[1].push_back(temp);
        else if (temp.virtue >= temp.talent) {
            v[2].push_back(temp);
        } else v[3].push_back(temp);
    }
    printf("%d\n", total);
    for (int i = 0; i < 4; i ++ ) {
        sort(v[i].begin(), v[i].end(), cmp);
        for (int j = 0; j < v[i].size(); j ++ ) {
            printf("%d %d %d\n", v[i][j].num, v[i][j].virtue, v[i][j].talent);
        }
    }
    return 0;
}