/*
*巴什博弈：设n=(m+1)*r+s，如果n是m+1的倍数，那么肯定是后手赢，如果不是，则先手赢
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n%(m+1)==0)cout<<"second"<<endl;
        else cout<<"first"<<endl;
    }
}
