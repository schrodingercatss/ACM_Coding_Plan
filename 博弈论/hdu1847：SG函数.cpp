#include <bits/stdc++.h>
#define MAXN 1005
#define N 20
using namespace std;
int f[N],SG[MAXN],vis[MAXN];
  //SG函数的值为0，代表先手必败态，否则必胜
void getSG(int n)
{
    memset(SG,0,sizeof(SG));
    for(int i=1;i<=n;++i){   //SG[0]=0，默认必败态，从1开始
        memset(vis,0,sizeof vis); //每一次都要将上一状态的后继集合重置
        for(int j=0;j<=N;++j){
            if(f[j]>i)break;
            vis[SG[i-f[j]]]=1;   //将后继状态的SG函数值进行标记
        }
        for(int j=0;;++j){  //查询当前后继状态SG值中最小的非零值
            if(!vis[j]){
                SG[i]=j;
                break;
            }
        }
    }
}

int main()
{
    int n,m,k;
    f[0]=1;
    for(int i=1;i<=15;++i)f[i]=f[i-1]*2;
    getSG(1000);
    while(cin>>n){
        if(SG[n])cout<<"Kiki"<<endl;
        else cout<<"Cici"<<endl;
    }
    return 0;
}



