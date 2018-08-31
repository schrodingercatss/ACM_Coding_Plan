/*
*巴什博弈：设n=(m+1)*r+s，如果n是m+1的倍数，那么肯定是后手赢，如果不是，则先手赢
*这题稍微需要进行一下思维转换，对m进行分类讨论，即可求解。
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m){
        if(m>=n){
            for(int i=n;i<=m;++i){
                if(i==n)cout<<i;
                else cout<<" "<<i;
            }
            cout<<endl;
        }
        else{
            if(n%(m+1)==0)cout<<"none"<<endl;
            else cout<<n%(m+1)<<endl;   //把多余的s取走，就把状态转成了必胜态
        }
    }
    return 0;
}
