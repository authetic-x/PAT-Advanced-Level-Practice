//
// Created by authetic on 2018/9/27.
/*
 * 模拟微博转发机制，求限定层数内的最大转发数
 * Note: 图的遍历问题，因为涉及到层数，用BFS会比较合适，用
 * 邻接表存储图，vector存储一个结构体结点，id和layer，注意
 * 每个结点存储的是关注者，表示可以被转发，
 * 与题目输入的不同，其次每次遍历后要需要重置inq数组！
 */
//

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 1010;

struct Node {
    int id;
    int layer;
};

int n,L;
vector<Node> Adj[maxn];
bool inq[maxn] = {false};

int BFS(int s) {
    int numForward = 0;
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[s] = true;
    while (!q.empty()) {
        Node topNode = q.front();
        q.pop();
        int id = topNode.id;
        for (int i=0; i < Adj[id].size(); i++) {
            Node next = Adj[id][i];
            next.layer = topNode.layer+1;
            if (!inq[next.id] && next.layer <= L) {
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}

int main() {
    scanf("%d %d", &n, &L);
    Node user;
    int numFollow,id;
    for (int i=1; i<=n; i++) {
        user.id = i;
        scanf("%d", &numFollow);
        for (int j=0; j<numFollow; j++) {
            scanf("%d", &id);
            Adj[id].push_back(user);
        }
    }
    int numQuery, s;
    scanf("%d", &numQuery);
    for (int i=0; i<numQuery; i++) {
        memset(inq, false, sizeof(inq));
        scanf("%d", &s);
        int forwards = BFS(s);
        printf("%d\n", forwards);
    }
    return 0;
}