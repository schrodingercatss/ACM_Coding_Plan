/*
*题目：有两个人和一辆只能带一人的自动驾驶汽车，问：怎么利用汽车使两人尽快同时从A出发到达B地
*他们的步行速度一样。第一行输入3和整数，A到B地的距离，步行速度和车速。
*输出：最短时间,一个两位数的浮点数
*思路：二分法，假设甲骑小车到达C点后步行，然后小车回头去接乙，最后他们俩同时到达，这样花费的时间最短。
*注意：浮点数不能直接判断相等，需要设置精度
*/
#include <bits/stdc++.h>
#define exp 1e-4
using namespace std;

void solve(int dis,int v1,int v2)
{

    double t1,t2,t3,t4;
    double lo=0,hi=dis;
    do{
        double mid=(hi+lo)/2.0;
        t1=mid/v2; //甲乘车到c点耗时
        t2=t1+(dis-mid)/v1; //甲耗费的总时间
        t3=(mid-t1*v1)/(v1+v2); //小车回到遇到乙耗费的时间，乙向右，小车向左，所以相对速度应该是（a+b)
        t4=t1+t3+(dis-(t1+t3)*v1)/v2; //乙耗费的总时间
        if(t2<t4)hi=mid;
        else lo=mid;

    }while(fabs(t2-t4)>exp);
    printf("%.2f\n",t2);
}
int main()
{
    int dis,v1,v2;
    while(cin>>dis>>v1>>v2){
        solve(dis,v1,v2);
    }
    return 0;
}
