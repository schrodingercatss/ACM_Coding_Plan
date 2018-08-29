#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    while(t--){
        vector<int>v;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>k;
            v.push_back(k);
        }
        cin>>k;
        sort(v.begin(),v.end());
        if(v.size()<=3);
        else{
            for(int i=0;i<n-3;++i){
                if(v[i]+k>v[i+3])v[i+3]=v[i]+k;
            }
        }
        cout<<v.back()+k<<endl;
    }
    return 0;
}
