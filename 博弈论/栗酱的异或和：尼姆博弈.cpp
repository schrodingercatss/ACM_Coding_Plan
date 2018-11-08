#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int ans=0;
        for(int i=1;i<=n;++i){
            cin>>arr[i];
            ans^=arr[i];
        }
        if(arr[k]>(arr[k]^ans))cout<<"Yes"<<endl; //当第k堆的石子数大于其他堆的异或和时，一定能拆分第k堆，使他们的异或和为0。(不能取等于，因为至少需要取一个)
        else cout<<"No"<<endl;      //这是如果选的这一堆的个数大于等于这个异或和的时候，那么我们就可以取走相应的数量让个数与异或和相等，否则就不行。
    }
    return 0;
}
