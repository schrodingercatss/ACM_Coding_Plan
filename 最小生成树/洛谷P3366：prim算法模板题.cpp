#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 5e3;
const int INF = 0x3f3f3f3f;
bool vis[N + 5];
int dis[N + 5]; //存储生成树到其他非树节点的距离
int maze[N + 5][N + 5];
int n, m, ans;
inline void init()
{
    ans = 0;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i <= n; ++i) 
        for(int j = 0; j <= n; ++j)
            maze[i][j] = maze[j][i] = i == j ? 0 : INF;
}

void prim()
{
    for(int i = 0; i <= n; ++i) dis[i] = maze[1][i];
    dis[1] = 0;
    vis[1] = true;
    for(int i = 1; i < n; ++i) {
        int k = 0;
        //找到没有使用过的且离当前点边权最小的点
        for(int j = 1; j <= n; ++j)
            if(!vis[j] && dis[j] < dis[k]) k = j;
        vis[k] = true;
        ans += dis[k];
        for(int j = 1; j <= n; ++j) {
            //如果dis[k] > maze[k][j],则更新生成树到每一个非树顶点的距离（松弛）
            if(dis[j] > maze[k][j]) dis[j] = maze[k][j];
        }
    }
}

int main()
{
    int x, y, z;
    scanf("%d %d", &n, &m);
    init();
    while(m--) {
        scanf("%d %d %d", &x, &y, &z);
        maze[x][y] = maze[y][x] = min(maze[x][y], z);
    }
    prim();
    printf("%d\n", ans);
    return 0;
}