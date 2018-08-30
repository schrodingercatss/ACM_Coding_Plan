/*大臣的旅费
*思路：求最大费用，就是一颗树的直径（最长路），我们可以通过两遍dfs（bfs）来计算最长路。
*这种写法是利用邻接矩阵，当n过大时就无法开数组了，这个时候我们需要使用领接表存储
*/

#include <bits/stdc++.h>
using namespace std;

int maze[1005][1005];
int max_index;
int maxv;
bool vis[1005];
int n;

void dfs(int st,int dis)
{
    bool flag=false;  //表示还有路可以走
    for(int i=1;i<=n;++i){
        if(!vis[i]&&maze[st][i]!=0){  //用0来代表不可达
            flag=true;
            vis[i]=true;
            dfs(i,dis+maze[st][i]);
            vis[i]=false;
        }
    }
    if(!flag){
        if(dis>maxv){
            maxv=dis;
            max_index=st;
        }
    }
}
int main()
{
    int a,b,c;
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        cin>>a>>b>>c;
        maze[a][b]=maze[b][a]=c;
    }
    memset(vis,0,sizeof vis);
    dfs(1,0);
    maxv=0;
    memset(vis,0,sizeof(vis));
    vis[max_index]=true;
    dfs(max_index,0);
    printf("%d\n",maxv*10+(maxv+1)*maxv/2);

    return 0;
}
