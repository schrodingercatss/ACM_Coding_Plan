/*
*斐波那契博弈：有一堆个数为n的石子，游戏双方轮流取石子，满足：
*1.先手不能在第一次把所有石子取完;
*2.之后每次可以取的石子数介于1到对手刚去的石子数的2倍之间（包含1倍和2倍）
*先手胜当且仅当n不是Fibonacci数。换句话说，必败态构成Fibonacci数列。
*
*齐肯多夫定理：任意一个正整数都可以表示为若干个不连续的斐波那契数之和
*/

#include <bits/stdc++.h>
using namespace std;
long long arr[100];
int main()
{
    int n;
    arr[0]=0,arr[1]=1;
    for(int i=2;i<=50;++i)arr[i]=arr[i-1]+arr[i-2];
    while(cin>>n&&n){
        if(binary_search(arr,arr+50,n))cout<<"Second win"<<endl;
        else cout<<"First win"<<endl;
    }
    return 0;
}
