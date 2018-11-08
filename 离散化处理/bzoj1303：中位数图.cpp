#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int arr[maxn],l[maxn<<1],r[maxn<<1],sum[maxn];  //l和r的下标为了防止出现负数加了n，所以要两倍长度。
typedef long long ll;

inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, b, pos;
    ll ans = 0;
    n = read(), b = read();
    for(int i = 1; i <= n; ++i){
        arr[i] = read();
        if(arr[i] > b)arr[i] = 1;     //离散化处理，等于b赋值0，大于b赋值1，小于b赋值-1
        else if(arr[i] == b){arr[i] = 0;pos = i;}
        else arr[i] = -1;
    }

    //因为为了防止负数下标加了一个n，所以l[n],r[n]相当于l[0],r[0],因为l和r代表从pos位置延生出去的前缀和，所以0相当于只有b这一个数。
    l[n] = r[n] = 1;

    for(int i = pos - 1; i >= 1; --i){
        sum[i] = sum[i + 1] + arr[i];
        l[sum[i] + n]++;   //加上n，防止下标出现负数
    }

    for(int i = pos + 1; i <= n; ++i){
        sum[i] = sum[i - 1] + arr[i];
        r[sum[i] + n]++;  //加上n，防止下标出现负数
    }
    //根据乘法乘法原理，对应相乘相加即可(左段和右段相等即可)
    for(int i = 0; i <= 2 * n - 1; ++i)
        ans += l[i] * r[2 * n - i];

    cout<< ans <<endl;

    return 0;
}
