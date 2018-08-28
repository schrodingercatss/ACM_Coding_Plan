#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll x,ll n)
{
    int ans=1;
    while(n){
        if(n&1)ans*=x;
        x*=x;
        n>>=1;
    }
    return ans;
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<power(x,n)<<endl;

    return 0;
}
