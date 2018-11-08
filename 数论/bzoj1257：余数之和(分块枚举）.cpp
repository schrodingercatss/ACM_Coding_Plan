#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//详见博客：https://blog.csdn.net/loi_dqs/article/details/50522975
int main()
{
    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll ans = (ll)n * k;
    if(n > k) n = k;   //因为我们改成了区间贡献乘法(当n>k时,n/i = 0,这样后面的数字可以省略)

    ll l, r, w;
    for(ll i = 1; i <= n; i = r + 1){
        w = k / i;
        l = i,r = k / w;
        if(r > n) r = n;  //右区间的最大长度不能超过n，如果超过了n，则让最大长度为n
        ans -= (r - l + 1) * w * (l + r) / 2;
    }
    printf("%lld\n",ans);

    return 0;

}
