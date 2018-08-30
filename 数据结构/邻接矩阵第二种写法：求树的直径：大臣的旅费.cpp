/*大臣的旅费
*思路：求最大费用，就是一颗树的直径（最长路），我们可以通过两遍dfs（bfs）来计算最长路。
*这种写法是利用邻接表建树，比上一种对内存的占用要小，数据量超过1w时建议使用这种建树。
*/

#include <bits/stdc++.h>
using namespace std;
#define N 23333

//u代表起始点，v代表终点，w代表权值
vector<pair<int,int>>G[N+5];
long long max_dis,ed;

void dfs(int st,int father,int dis)
{
    if(dis>max_dis)max_dis=dis,ed=st;
    for(int i=0;i<G[st].size();++i){
        if(G[st][i].first==father)continue;
        int v=G[st][i].first,w=G[st][i].second;
        dfs(v,st,dis+w);
    }
}

int main()
{
    int n,u,v,w;
    cin>>n;
    for(int i=1;i<n;++i){
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    dfs(1,0,0);
    dfs(ed,0,0);
    cout<<(max_dis+1)*max_dis/2+10*max_dis<<endl;

    return 0;
}
