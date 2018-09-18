//
// Created by authetic on 2018/9/12.
//

#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int x,y,z;
}node;

int X[6] = {0,0,0,0,1,-1};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {1,-1,0,0,0,0};

int pixel[1290][130][61];
bool inq[1290][130][61] = {false};
int m,n,slice,T;

int judge(int x, int y, int z) {
    if (x<0||x>=m||y<0||y>=n||z<0||z>=slice) return false;
    if (inq[x][y][z] || pixel[x][y][z]==0) return false;
    return true;
}

int BFS(int x, int y, int z) {
    int tot = 0;
    queue<Node> q;
    node.x = x;
    node.y = y;
    node.z = z;
    q.push(node);
    inq[x][y][z] = true;
    while (!q.empty()) {
        Node temp = q.front();
        q.pop();
        tot++;
        for (int i=0; i<6; i++) {
            int newx = temp.x+X[i];
            int newy = temp.y+Y[i];
            int newz = temp.z+Z[i];
            if (judge(newx,newy,newz)) {
                node.x=newx, node.y=newy, node.z=newz;
                q.push(node);
                inq[newx][newy][newz] = true;
            }
        }
    }
    if (tot>=T) return tot;
    return 0;
}

int main() {
    scanf("%d %d %d %d", &m, &n, &slice, &T);
    for (int z=0; z<slice; z++) {
        for (int x=0; x<m; x++) {
            for (int y=0; y<n; y++) {
                scanf("%d", &pixel[x][y][z]);
            }
        }
    }
    int ans = 0;
    for (int z=0; z<slice; z++) {
        for (int x=0; x<m; x++) {
            for (int y=0; y<n; y++) {
                if (pixel[x][y][z]==1 && inq[x][y][z]==false) {
                    ans += BFS(x,y,z);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}