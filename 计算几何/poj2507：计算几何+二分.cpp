/*
*思路：设底边为w，交点距左边的距离为a，化简得到：1=c/sqrt(x*x-w*w)+c/sqrt(y*y-w*w) 这个式子
*因为底边不会超过斜边，所以找x，y中最小的边为上界，0为下界，精度为1e-8，然后进行二分
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
double x,y,c;

bool judge(double w)
{
    return 1-c/sqrt(x*x-w*w)-c/sqrt(y*y-w*w)>0;
}

double solve()
{
    double l=0,r=min(x,y),m=0;
    while(r-l>1e-8){
        m=(l+r)/2;
        if(judge(m))l=m;
        else r=m;
    }
    return m;
}
int main()
{

    while(cin>>x>>y>>c)
        printf("%.3f\n",solve());
    return 0;
}
