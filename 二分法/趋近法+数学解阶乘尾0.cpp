/*
*题目跟上一道一样，都是求最小自然数n满足阶乘尾0个数为q
*这里我们可以用等比数列去优化它， Q=N/5+N/(5²)+N/(5³)..... =4Q*[(5^k)/(5^k-1)]
*观察到，当k趋于无穷时，整个比例式趋于1，所以我们可以计算出N=4Q的末尾0个数，然后与Q进行比较
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    int ans=0;
    while(n){
        n/=5;
        ans+=n;
    }
    return ans;
}

int main()
{
    int n;
    while(cin>>n){
            if(!n){cout<<1<<endl;continue;}
        //这里是一个技巧，这里利用c语言整除的技巧，把ans的初始值化成5的倍数，这样就不会有多余数字了,并且，只用从小加到大，不用再从大减到小了
        int ans=4*n/5*5;
        while(solve(ans)<n)ans+=5;  //如果零的个数小于n，就往上加5
        if(n==solve(ans))cout<<ans<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
