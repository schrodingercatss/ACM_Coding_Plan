#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow_mod(ll a,ll b,ll c)
{
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%c;
        a=(a*a)%c;
        b>>=1;
    }
    return ans;
}

int main()
{
    int a,b,n;
    while(cin>>a>>b>>n){
        cout<<pow_mod(a,b,n)<<endl;
    }

    return 0;
}
