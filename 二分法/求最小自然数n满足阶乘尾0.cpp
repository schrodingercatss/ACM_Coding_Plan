/*
*找到最小自然数n，使n！在十进制下包含Q个0
*方法：二分法
*/
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int slove(int n)
{
    int ans=0;
    while(n){
        n/=5;
        ans+=n;
    }
    return ans;
}

void Binary_search(int n)
{
    int lo=1,hi=50000000;
    int ans=INF;
    while(lo<=hi){
        int mid=(hi-lo)/2+lo;
        int t=slove(mid);
        if(t==n&&mid<ans)ans=mid;
        if(t<n)lo=mid+1;
        else if(t>=n)hi=mid-1;
    }
    if(ans!=INF)cout<<ans<<endl;
    else cout<<"no"<<endl;

}
int main()
{
    int n;
    while(cin>>n)
    Binary_search(n);

    return 0;
}
