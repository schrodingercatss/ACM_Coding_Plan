#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int arr[100005];
int main()
{
    int n,m;
    while(cin>>n>>m){
        int lo=0,hi=0;
        for(int i=0;i<n;++i){
            cin>>arr[i];
            lo=max(arr[i],lo); //把n天中花费最多的那一天的花费作为下界low（相当于把n天分为n组）
            hi+=arr[i];  //把所有天数的总花费作为上界high（相当于把n天都分作1组）
        }
        while(lo<hi){  //可能在low==high之前，分组数就已经=m，但是mid并不是最优，因此要继续二分
            int sum=0;
            int cnt=1; ////当前mid值能把n天分成的组数(初始把全部天数作为1组)
            int mid=(hi-lo)/2+lo;
            for(int i=0;i<n;++i){
                if(sum+arr[i]>mid){
                    sum=arr[i];
                    cnt++;
                }
                else{
                    sum+=arr[i];
                }
            }
            if(cnt>m)lo=mid+1;  //mid值偏小，下界后移
            else if(cnt<m)hi=mid; //mid值偏大，上界前移
            else hi=mid;       //如果cnt=m，可能mid不是最优解，所以继续二分
        }
        cout<<hi<<endl;//循环结束时lo和hi的值是一样的，输出其中一个即可
    }
    return 0;
}
