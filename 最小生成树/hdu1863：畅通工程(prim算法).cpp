#include <bits/stdc++.h>
using namespace std;
const int N = 1e2;
const int INF = 0x3f3f3f3f;
bool vis[N + 5];
int dis[N + 5]; 
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
        bool flag = false;
        //找到没有使用过的且离当前点边权最小的点
        for(int j = 1; j <= n; ++j)
            if(!vis[j] && dis[j] < dis[k]) {
                k = j;
                flag = true;
            }
        if(!flag) {
            puts("?");
            return;
        }
        vis[k] = true;
        ans += dis[k];
        for(int j = 1; j <= n; ++j) {
            //如果dis[k] > maze[k][j],则更新生成树到每一个非树顶点的距离（松弛）
            if(dis[j] > maze[k][j]) dis[j] = maze[k][j];
        }
    }
    printf("%d\n", ans);
}
int main()
{
    int a, b, c;
    while(cin >> m >> n, m) {
        init();
        for(int i = 0; i < m; ++i) {
            cin >> a >> b >> c;
            maze[a][b] = maze[b][a] = c;
        }
        prim();
    }
    return 0;
}

