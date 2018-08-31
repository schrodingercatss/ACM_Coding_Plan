/*
*尼姆博弈：在三堆(可推广至n堆）中两人轮流取任意多的物品，每次至少取1个，最后取光者胜
*对于任意奇异局势(a,b,c),a^b^c=0
*如果(a,b,c)为非奇异局势，我们可以将c减去a^b，然后变成奇异局势（a,b,c-a^b)
*推广到4堆(a,b,c,d)为非奇异局势我们可以将四堆的任意一堆（前提有足够的能减去）假设为d，d-a^b^c,可构造奇异局势
*/


#include <bits/stdc++.h>
using namespace std;
int arr[105];
int main()
{
    int n,ans,cnt;
    while(cin>>n,n){
        ans=cnt=0;
        for(int i=0;i<n;++i){
            cin>>arr[i];
            ans^=arr[i];
        }
        if(ans==0)puts("0");
        else{
            for(int i=0;i<n;++i){
                int k=ans^arr[i];    //ans^a[i]相当于其他值的异或，一个数异或2次得0,0异或任何值都为它本身，如果某一堆能减去k,就能构成奇异局势。
                if(arr[i]>=k)cnt++;
            }
            cout<<cnt<<endl;
        }

    }
    return 0;
}
