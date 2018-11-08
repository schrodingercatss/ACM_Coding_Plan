#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
#define pi 4*atan(1.0)
//#define e exp(1)
#define rep(i,a,n) for(int i=a;i<n;++i)
#define _for(i,a,n)for(int i=a;i<=n;++i)
#define pb push_back
#define mp make_pair=1e9+7;
#define all(x) (x).begin(),(x).end()
#define input() int t;cin>>t;while(t--)
#define close() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mt(arr,n) memset(arr,n,sizeof(arr))
#define inf ~0u>>1
#define INF 0x3f3f3f3f
#define esp 1e-6
const int MOD = 1e9+7;
const int maxn = 1005;
using namespace std;
const int N = 20;
typedef long long ll;
typedef pair<ll,ll>P;

int maze[maxn][maxn],lowcost[maxn],cost[maxn];
bool vis[maxn];
int v,e,ans;

inline void init()
{
    mt(maze,INF);
    mt(lowcost,0);
    mt(vis,false);
}
void prim()
{
    int minv,pos;
    ans = 0,lowcost[1] = 0,vis[1] = true;
    for(int i = 2; i <= v; ++i) lowcost[i] =maze[1][i];  //默认从点1开始

    for(int i = 2; i <= v; ++i){
        minv = INF;
        for(int j = 1; j <= v; ++j){
            if(!vis[j] && lowcost[j] < minv){   //寻找离生成树最小的点
                minv = lowcost[j];    
                pos = j;
            }
        }
        vis[pos] = true;
        ans += minv;
        for(int j = 1; j <= v; ++j){   //更新各个点离最小生成树的距离
            if(!vis[j] && lowcost[j] > maze[pos][j])
                lowcost[j] = maze[pos][j];    //lowcost记录的是离到生成树最短的距离
        }
    }
}
int main()
{
    int a,b,c;
    close();
    input(){
        init();
        cin>>v>>e;
        _for(i,1,e){
            cin>>a>>b>>c;
            maze[a][b] = maze[b][a] = c;
        }
        _for(i,1,v)
            cin>>cost[i];

        sort(cost+1,cost+v+1);  //排序寻找接线最便宜的点
        prim();
        cout<< ans+cost[1] <<endl;
    }
    return 0;
}
