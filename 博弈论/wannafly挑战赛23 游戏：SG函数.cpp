#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int SG[MAXN];
bool vis[MAXN];
vector<int>arr[MAXN];
int s[MAXN];
int n;
void getSG(int n)
{
    for(int i=1;i<=n;++i){   //因为SG[0]=0是必败态
        memset(vis,false,sizeof vis);  //将访问状态重置
        for(int j=0;j<arr[i].size();++j) vis[SG[i-arr[i][j]]]=true;
        for(int j=0;;++j){
            if(!vis[j]){
                SG[i]=j;
                break;
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<MAXN;++i)
        for(int j=i;j<MAXN;j+=i)arr[j].push_back(i);  //预处理，求出1-MAXN内各个数的约数，然后放入vector中
    getSG(100000);
    int ans=0,cnt=0;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        ans^=SG[s[i]];
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<arr[s[i]].size();++j){
            //注意异或的优先级
            if(SG[s[i]-arr[s[i]][j]]==(ans^SG[s[i]]))//因为取的石子数d必须这堆石子数m的约数，arr[s[i]]这个vector中存储的是s[i]的约数
                cnt++;        //因为先手的目的是为了使异或和为0，我们只需要判断，取走d个石头后，其他堆的异或和是否跟剩下的SG[m-d]相同，因为相同的数异或的结果是0
        }
    }
    cout<<cnt<<endl;
}
