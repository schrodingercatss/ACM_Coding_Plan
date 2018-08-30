/*大臣的旅费
*思路：求最大费用，就是一颗树的直径（最长路），我们可以通过两遍dfs（bfs）来计算最长路。
*这种写法是利用邻接表建树，虽然麻烦，但是可以节约许多空间，效率也不错,在数据较大的时候适合使用。
*/

#include <bits/stdc++.h>
using namespace std;
#define N 23333

//u代表起始点，v代表终点，w代表权值

struct Edge{
    int v,w;
    Edge(int vv,int ww):v(vv),w(ww){} //构造函数
};

int n;
int max_dis,ed;
vector<vector<Edge>>G;  //先不分配空间，在下面利用resize函数根据n来分配可以节约空间

void dfs(int u,int father,int dis)  //这里没有利用数组来标记，而是利用判断是否是父结点，来判断是否走过了这个点
{
    if(dis>max_dis)max_dis=dis,ed=u;
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i].v,w=G[u][i].w;
        if(v==father)continue;
        dfs(v,u,dis+w);
    }
}


int main()
{
    int u,v,w;
    scanf("%d",&n);
    G.clear();
    G.resize(n+2); //根据n来分配空间
    for(int i=1;i<n;++i){
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    max_dis=0;
    dfs(1,-1,0);
    dfs(ed,-1,0);
    printf("%d\n",max_dis*10+(max_dis+1)*max_dis/2);

    return 0;
}
