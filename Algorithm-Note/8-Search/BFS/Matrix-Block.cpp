//
// Created by authetic on 2018/9/11.
//

#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;
int matrix[maxn][maxn];
bool inq[maxn][maxn];
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

struct Node {
    int x,y;
}node;

bool judge(int x, int y) {
    if (matrix[x][y]==0 || !inq[x][y]) return false;
    if (x<0 || y<0 || x>=maxn || y>=maxn) return false;
    return true;
}

// 广度优先
void BFS(int x, int y) {
    queue<Node> q;
    node.x = x;
    node.y = y;
    q.push(node);
    inq[x][y] = true;
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int newx = x+X[i];
            int newy = y+Y[i];
            if (judge(newx, newy)) {
                node.x = newx;
                node.y = newy;
                q.push(node);
                inq[newx][newy] = true;
            }
        }
    }
}

//深度优先
void DFS(int x, int y) {
    for (int i=0; i<4; i++) {
        int newx = x+X[i];
        int newy = y+Y[i];
        if (judge(newx, newy)) {
            inq[newx][newy] = true;
            DFS(newx, newy);
        }
    }
}

int main() {
    for (int i=0; i<maxn; i++) {
        for (int j=0; j<maxn; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int ans=0;
    for (int i=0; i<maxn; i++) {
        for (int j=0; j<maxn; j++) {
            if (matrix[i][j]==1 && inq[i][j]) {
                ans++;
                BFS(i,j);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}