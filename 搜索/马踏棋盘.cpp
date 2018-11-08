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

int vis[10][10];
int n,m,tot;

bool inboard(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)return false;
    return true;
}

void dfs(int x,int y,int cur)
{
    if(inboard(x,y) && !vis[x][y]){  //该点在棋盘中，并且没有被访问过
        cur++;
        vis[x][y] = cur; //记录当前的步数
        if(cur == n * m){
            tot++;
            cout <<  "Case#" << tot <<endl;
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j)
                    printf("%4d",vis[i][j]);
                cout<<endl;
            }
            vis[x][y] = 0;
            return;
        }
        else{
            dfs(x-1,y-2,cur);
            dfs(x-1,y+2,cur);
            dfs(x-2,y-1,cur);
            dfs(x-2,y+1,cur);
            dfs(x+1,y-2,cur);
            dfs(x+1,y+2,cur);
            dfs(x+2,y-1,cur);
            dfs(x+2,y+1,cur);
            vis[x][y] = 0;
        }
    }
    else return;
}

int main()
{
    cin>> n >> m;  //棋盘的行数和列数
    dfs(0,0,0);  //默认马的位置在点(0,0)处
    cout<< tot <<endl;
    return 0;
}
