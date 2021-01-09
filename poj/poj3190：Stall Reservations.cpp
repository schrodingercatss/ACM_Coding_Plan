#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAXN = 5e4;
int ans[MAXN + 5];
//poj3190：Stall Reservations
struct node {
    int id, l, r, ans;
    inline bool operator < (const node& x) const {
        return l < x.l;
    }
}cow[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cow[i].id = i;
        cin >> cow[i].l >> cow[i].r;
    }
    sort(cow, cow + n);
    priority_queue<P, vector<P>, greater<P> > q;
    for(int i = 0; i < n; ++i) {
        int num = q.size();
        if(num && q.top().first < cow[i].l) {
            cow[i].ans = q.top().second;
            q.pop();
            q.push({cow[i].r, cow[i].ans});
            continue;
        }
        cow[i].ans = ++num;
        q.push({cow[i].r, num});
    }
    cout << q.size() << endl;
    for(int i = 0; i < n; ++i) ans[cow[i].id] = cow[i].ans;
    for(int i = 0; i < n; ++i) cout << ans[i] << endl;
    return 0;
}