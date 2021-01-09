#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2500;
struct Cow {
    int l, r;
    inline bool operator < (const Cow& x) const {
        return l < x.l;
    }
}cow[MAXN + 5];

struct Spf {
    int s, c;
    inline bool operator < (const Spf& x) const {
        return s < x.s;
    }
}spf[MAXN + 5];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> cow[i].l >> cow[i].r;
    for(int i = 1; i <= m; ++i) cin >> spf[i].s >> spf[i].c;
    sort(cow + 1, cow + n + 1);
    sort(spf + 1, spf + m + 1);
    int ans = 0, cur = 1;
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 1; i <= m; ++i) {
        while(cur <= n && cow[cur].l <= spf[i].s) q.push(cow[cur++].r);
        while(spf[i].c && q.size()) {
            int t = q.top(); q.pop();
            if(t < spf[i].s) continue;
            ans++, spf[i].c--;
        }
    }
    cout << ans << endl;
    return 0;
}