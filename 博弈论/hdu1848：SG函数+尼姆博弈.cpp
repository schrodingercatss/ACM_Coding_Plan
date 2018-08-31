/*
*SG值：一个点的SG值就是一个不等于它的后继点的SG的且大于等于零的最小整数
*大概意思：在步骤允许的情况下，与前面一个必败点的差（也就是说这个 差是规定的，能走的，其中一个步数）
*后继点：也就是按照题目要求的走法（比如石子可取的数量，方法）能够一步到达的那个店
*详见博客：http://www.cnblogs.com/ECJTUACM-873284962/p/6921829.html
*/

//f[N]:可改变当前状态的方式，N为方式的种类，f[N]要在getSG之前先预处理
//SG[]:0~n的SG函数值
//vis[]:为x后继状态的集合

#include <bits/stdc++.h>
#define MAXN 1005
#define N 20
using namespace std;
int f[N],SG[MAXN],vis[MAXN];

void getSG(int n)
{
    memset(SG,0,sizeof(SG));
    for(int i=1;i<=n;++i){   //SG[0]=0，默认必败态，从1开始
        memset(vis,0,sizeof vis); //每一次都要将上一状态的后继集合重置
        for(int j=1;j<=N;++j){
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
    f[0]=f[1]=1;
    for(int i=2;i<=16;++i)f[i]=f[i-1]+f[i-2];
    getSG(1000);
    while(cin>>n>>m>>k,n){
        //注意，位运算优先级比等于号低
        if((SG[n]^SG[m]^SG[k])==0)cout<<"Nacci"<<endl;    //尼姆博弈，每个堆(游戏）的SG值的异或和称为Nim和，nim和为0代表先手必败态
        else cout<<"Fibo"<<endl;
    }
    return 0;
}



