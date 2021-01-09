#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAXN = 1e3;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
int n, d, num;

struct point {
    int x, y;
    double l, r;
    inline bool operator < (const point& x) const {
        return l < x.l;
    }
} p[MAXN + 5];

void slove()
{
    for(int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
    bool flag = true;
    for(int i = 0; i < n; ++i) {
        if(p[i].y > d) {
            flag = false;
            break;
        }
    }
    if(!flag) {
        cout << "Case " << ++num << ": -1" << endl;
        return;
    }
    for(int i = 0; i < n; ++i) {
        double k = sqrt((double)d * d - (double)p[i].y * p[i].y);
        p[i].l = p[i].x - k, p[i].r = p[i].x + k;
    }
    sort(p, p + n);
    int ans = 1;
    double pos = INF;
    for(int i = 0; i < n; ++i) {
        if(pos + eps < p[i].l) {
            ans++;
            pos = p[i].r;
        }
        else pos = min(pos, p[i].r);
    }
    cout << "Case " << ++num << ": " << ans << endl;
}

int main()
{
    while(cin >> n >> d, n) slove();
    return 0;
}