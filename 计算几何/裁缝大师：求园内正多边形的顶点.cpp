/*
*很简单的几何题，我们可以圆分成n份，相对应的角度与圆的交点就是对应正n边形的几个顶点
*这里要注意的是浮点误差，要避免出现-0.00的情况
*/
#include <bits/stdc++.h>
#define esp 1e-9
#define PI 4*atan(1.0)
using namespace std;
int main()
{
    int t;
    double x,y,r,n;
    double x1,y1;
    cin>>t;
    while(t--){
        cin>>x>>y>>r>>n;
        double part=PI*2.0/n;
        double now=part;
        printf("%.2f %.2f\n",x+r,y);
        for(int i=1;i<n;++i){
            x1=x+r*cos(-now),y1=y+r*sin(-now);
            if(fabs(x1)<esp)x1=0;   //控制精度，因为可能会出现-.0000000000000024222 这种情况，然后printf截取前2位，就会输出-0.00这种非法情况
            if(fabs(y1)<esp)y1=0;
            printf("%.2f %.2f\n",x1,y1);
            now+=part;
        }
    }
    return 0;
}

