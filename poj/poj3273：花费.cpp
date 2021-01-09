#include <bits/stdc++.h>
using namespace std;
struct node{
    double dis;
    double p;
}arr[10];

bool cmp(node a,node b)
{
    return a.dis<b.dis;
}
double d1,c,d2,p;
int n;
double fee =0;
int main()
{
    cin>>d1>>c>>d2>>p>>n;
    for(int i=1;i<=n;++i)cin>>arr[i].dis>>arr[i].p;
    arr[0].dis=0,arr[0].p=p;
    arr[n+1].dis=d1,arr[n+1].p=0;
    int palce=0;
    sort(arr+1,arr+n+1,cmp);
    int place=0;  //当前所在车站
    double have=0; //当前剩余油量
    while(place<=n){
        int k=place;
        while(c*d2>=arr[k+1].dis-arr[place].dis && k<=n+1){ //找到比当前i更便宜的车站，直接确定目标
            k++;
            if(arr[k].p<=arr[place].p)break;
        }
        if(k==place){
            cout<<"No Solution"<<endl;    //如果k==i，代表已经没有车站可以再到达了，直接输入无解
            return 0;
        }
        double dist =arr[k].dis-arr[place].dis; //车需要前进的距离
        if(arr[place].p>=arr[k].p){  //前往一个油费更低的加油站，尽量现在所处加油站的油
            if(have<=dist/d2){   //如果当前的油不够到达下一个费用更低的加油站，在本加油站加足到下一个加油站的油
                fee+=(dist/d2-have)*arr[place].p;  //式子经过了化简
                have=0;        //移动到下一个加油站后，没有油了
            }
            else have-=(dist/d2);  //如果剩余油量可以达到，本加油站不加油
        }
        if(arr[k].p>arr[place].p){   //即将移动到一个油费更高的加油站，出发的时候需要加满油
            if(have<=dist/d2){    //当前的油不能到达下一个加油站
                fee+=(c-have)*arr[place].p; //加满
                have=c-dist/d2;  //移动到下一个加油站剩余油量
            }
            else {      //当前的油能到达下一个加油站
                fee+=(c-have+dist/d2)*arr[place].p;  //C-(have-dist/d2)化简
                have=c-dist/d2;  //移动到下一个加油站剩余油量
            }
        }
        place=k;  //移动到下一个加油站
    }
    cout<<fixed<<setprecision(2)<<fee<<endl;

    return 0;
}
