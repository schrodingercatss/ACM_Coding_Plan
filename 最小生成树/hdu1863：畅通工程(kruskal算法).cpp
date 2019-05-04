#include <bits/stdc++.h>
using namespace std;
int n, m, ans, cnt;
int bcj[105];
bool vis[105];

struct node {
    int u, v, w;
    inline bool operator < (const node &x) const {
        return w < x.w;
    }
} edge[105];

inline void init()
{
    memset(vis, false, sizeof vis);
    memset(bcj, -1, sizeof bcj);
}

int Find(int x)
{
    if(bcj[x] < 0) return x;
    return bcj[x] = Find(bcj[x]);
}

void kruskal()
{
    ans = cnt = 0;
    sort(edge, edge + m);
    for(int i = 0; i < m; ++i) {
        int u = Find(edge[i].u), v = Find(edge[i].v);
        if(u == v) continue;
        bcj[v] = u;
        ans += edge[i].w;
        cnt ++;
        if(cnt == n - 1) break;
    }
    for(int i = 2; i <= n; ++i) {
        if(Find(1) != Find(i)) {
            puts("?");
            return;
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
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        }
        kruskal();
    }
    return 0;
}