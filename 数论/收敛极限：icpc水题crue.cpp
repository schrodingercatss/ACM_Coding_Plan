/*https://nanti.jisuanke.com/t/29366
*icpc16年青岛赛区水题，观察可知，这题在n的位数大于等于7后就收敛于一个值，其实是傅里叶级数，收敛于PI*PI/6,不过不知道也没啥，可以打表找
*/
#include <bits/stdc++.h>
using namespace std;

const int N =1e6+5;
double arr[N];
int main()
{
    for(int i=1;i<1000000;++i)arr[i]=arr[i-1]+(double)1.0/i/i;
    string str;
    int t;
    while(cin>>str){
        if(str.size()>=7)cout<<"1.64493"<<endl;
        else{
            sscanf(str.c_str(),"%d",&t);
            cout<<fixed<<setprecision(5)<<arr[t]<<endl;
        }
    }
    return 0;
}

