//
// Created by authetic on 2018/9/6.
/*
 * 老鼠排名
 * Note: 题目没看懂，输入是分组的顺序，注意排名，
 * 每组被刷下的老鼠排名为group+1， 没看懂题目时看这一句懵了，
 * 主要是队列的基本运用，将每组胜者入队，其他的出队即可！
 */
//

#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1010;

struct Mouse {
    int weight;
    int rank;
}mouse[maxn];

queue<int> q;

int main() {
    int np,ng,order;
    scanf("%d %d", &np, &ng);
    for (int i=0; i<np; i++) {
        scanf("%d", &mouse[i].weight);
    }
    for (int i=0; i<np; i++) {
        scanf("%d", &order);
        q.push(order);
    }
    int temp=np,group;
    while (q.size()!=1) {
        if (temp%ng==0) group = temp/ng;
        else group = temp/ng+1;
        for (int i=0; i<group; i++) {
            int k = q.front();
            for (int j=0; j<ng; j++) {
                if (i*ng+j>=temp) break;
                int front = q.front();
                if (mouse[k].weight < mouse[front].weight) {
                    k = front;
                }
                mouse[front].rank = group+1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;
    }
    mouse[q.front()].rank = 1;
    for (int i=0; i<np; i++) {
        if (i!=np-1) {
            printf("%d ", mouse[i].rank);
        } else {
            printf("%d\n", mouse[i].rank);
        }
    }
    return 0;
}