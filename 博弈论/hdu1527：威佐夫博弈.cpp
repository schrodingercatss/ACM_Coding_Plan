/*
*威佐夫博弈：有两堆各若干物品，两人轮流从某一堆或同时从两堆中取同样多的物品，规定每次至少取一个，多着不限，最后取光着胜
*根据推论 a=(向下取整）k*（1+√5)/2，b=a+k时（k为任意非负整数）局势为奇异局势
*我们只需要判断（b-a)*(1+√5)/2是否等于b即可。
*/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,b;
    double t=(1.0+sqrt(5))/2;
    while(cin>>a>>b){
        if(a<b)swap(a,b);
        if((int)((a-b)*t)==b)cout<<"0"<<endl;   //注意括号
        else cout<<"1"<<endl;
    }
    return 0;
}

//写法2：
/*
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a,b;
int main()
{
    while (scanf("%d%d",&a,&b)==2)
    {
        if (a>b) swap(a,b);
        int k=b-a;
        int hh=(double)(k)*(sqrt(5)+1.0)/2.0;
        hh+k==b ?puts("0"):puts("1");
    }
    return 0;
}
*/
