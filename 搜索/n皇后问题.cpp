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

int pos[maxn];
int tot,n;
bool vis[3][maxn];
void dfs(int cur)
{
    if(cur == n)tot++;
    else{
        for(int i = 0; i < n; ++i){
            if(!vis[0][i] && !vis[1][i+cur] && !vis[2][i-cur+n]){  //分别代表当前点的上一列，副对角线，主对角线是否有棋子，加n的目的是防止负数
                pos[cur] = i;
                vis[0][i] = vis[1][i+cur] = vis[2][i-cur+n] = true;
                dfs(cur+1);
                vis[0][i] = vis[1][i+cur] = vis[2][i-cur+n] = false;
            }
        }
    }
}
int main()
{
    cin>>n;
    dfs(0);
    cout<< tot <<endl;

    return 0;
}
