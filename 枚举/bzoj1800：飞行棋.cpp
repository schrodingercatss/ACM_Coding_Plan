#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 30;
int n,arr[maxn];

//圆的内接矩形的对角线是圆的直径
int main()
{
    cin>> n;
    arr[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    if(arr[n]&1){   //arr[n]是整个圆的周长，因为输入的弧长都是整数，如果弧长的一半出现小数，则不可能有矩形出现
        puts("0");
        return 0;
    }
    int ans = 0;
    for(int i= 1; i <= n; ++i){    //暴力枚举，如果两点之间的弧长等于周长的一半，那么就计算半径数加1
        for(int j = i + 1; j <= n; ++j){
            if(arr[j] - arr[i] == (arr[n] >> 1))ans++;
        }
    }
    cout<< (ans * (ans - 1) >> 1);

    return 0;
}
