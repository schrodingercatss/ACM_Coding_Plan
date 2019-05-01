#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 2e5;
typedef pair<int, int> P;
int bcj[5005];
int n, m, cnt, ans;
struct node {
    int u, v, w;
    inline bool operator < (const node &x) const {
        return w < x.w;
    }
} edge[200005];

int Find(int x)
{
    if(bcj[x] < 0) return x;
    return bcj[x] = Find(bcj[x]);
}

void kruskal()
{
    cnt = ans = 0;
    sort(edge, edge + m);
    for(int i = 0; i < m; ++i) {
        int u = Find(edge[i].u), v = Find(edge[i].v);
        if(u == v) continue;
        ans += edge[i].w;
        bcj[v] = u;
        cnt++;
        if(cnt == n - 1) break;   
    }
}



int main()
{
    scanf("%d %d", &n, &m);
    memset(bcj, -1, sizeof bcj);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    kruskal();
    printf("%d\n", ans);
    return 0;
}




