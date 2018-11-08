#include<stdio.h>
#include<cstring>
#include<algorithm>
#define ForMyLove return 0
using namespace std;
const int maxn = 1103+1e4;
int rec[maxn];    //记录各位小数
int vis[maxn];   //记录被除数出现的次数
int who[maxn];   //实时记录下标位置
int main()
{
    int a, b, t;

    while(~scanf("%d %d", &a, &b)){
        memset(vis, 0, sizeof(vis));
        memset(rec, 0, sizeof(rec));
        t = a;
        int cnt = 0;
        rec[cnt++] = a / b;
        a = a % b;
        while(!vis[a] && a){
            vis[a] = cnt;
            who[cnt] = a;
            rec[cnt++] = a * 10 / b;
            a = a * 10 % b;
        }
        printf("%d/%d = %d.", t, b, rec[0]);

        for(int i = 1; i < cnt && i <= 50 ;i++){
            if(a && who[i] == a) printf("(");  //如果是循环节的起始位置，则输出左括号
            printf("%d",rec[i]);
        }
        if(!a) printf("(0");
        if(cnt > 50) printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", a==0 ? 1 : cnt-vis[a]); //小数总长度减循环起始的长度，等于循环节长度
    }
    ForMyLove;
}
