/*
* anti-sg游戏的定义：决策集合为空的操作者胜，其余规则与SG游戏一致。
* 使用SJ定理来解决：
* 对于任意一个Anti-SG游戏，如果定义所有子游戏的SG值为0时游戏结束，先手必胜的条件：
* 1、游戏的SG值为0且所有子游戏SG值均不超过1。
* 2、游戏的SG值不为0且至少一个子游戏SG值超过1。
*/
//这题我们观察可知，SG(x)的值就是x
//比如第一堆的石头数量是4：那么mex{3,2,1,0}=4，所以不需要进行特殊处理SG值。

#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int MOD =1e9+7;
const int maxn =100000;
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main()
{
    int n,x;
    close();
    input(){
        bool flag = false;
        int ans = 0;
        cin>>n;
        _for(i,1,n){
            cin>>x;
            ans ^=x;
            if(x!=1)flag = true;
        }
        if((!ans&&!flag) || (ans&&flag))cout<<"John"<<endl;
        else cout<<"Brother"<<endl;
    }

    return 0;
}
