/*
*基础快速幂：求x的n次方
*例如求2的13次方时，我们可以先计算出2*2=4的值，这样2的13次方可以写成4*4*4*4*4*4*2(此处多一个2)的形式，再计算4*4=16的值，改写成16*16*16*2的值，这样只花了5次就得到了结果
*/
#include <bits/stdc++.h>
using namespace std;

int power(int x,int n)
{
    if(n==1)return x;
    int c=power(x,n/2);
    if(!(n&1))
        return c*c;
    else
        return c*c*x;
}
int main()
{
    int x,n;
    cin>>x>>n;
    cout<<power(x,n)<<endl;
}
