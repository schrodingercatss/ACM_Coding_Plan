### Problem A Large Digits

**题目传送门：** https://atcoder.jp/contests/abc187/tasks/abc187_a

**解题思路：**

给你两个数字$A$和$B$, 求其笛卡尔积，并输出较大的那个值。


**Code:**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int s1 = 0, s2 = 0;
    for(int i = 0; i < 3; ++i) {
        s1 += a[i] - '0';
        s2 += b[i] - '0';
    }
    cout << max(s1, s2) << endl;
    return 0;
}
```

### Problem B Gentle Pairs

**题目传送门：** https://atcoder.jp/contests/abc187/tasks/abc187_b

**解题思路：**
给你n个点，让你求满足两点间斜率在$[-1, 1]$的直线条数，题目保证不会出现斜率为无穷大的情况。

直接for循环遍历求一边即可，如果担心浮点误差可以将不等式：$-1 <=\frac{y2-y1}{x2-x1} <= 1$, 也即不等式$|\frac{y2-y1}{x2-x1}| <= 1$的分母乘过去

化成：$|y2-y1| <= |x2-x1|$


**Code:**

```cpp
#include <bits/stdc++>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for(auto& [x, y] : A) cin >> x >> y;
    int ans = 0;
    for(int i = 0; i < N; i++) 
        for(int j = i + 1; j < N; j++){
            auto [x1, y1] = A[i];
            auto [x2, y2] = A[j];
            if(abs(y1 - y2) <= abs(x1 - x2)) ans++;
    }
    cout << ans << endl;
}

```

### Problem C 1-SAT

**题目传送门：** https://atcoder.jp/contests/abc187/tasks/abc187_c

**解题思路：**
给你N个字符串$s1, s_2 ... s_n$，每个字符串都由小写字母组成，前面有至多1个`!`。
请你找到任意一个字符串S，使得`!`+S也存在于这个序列，输出S，否则输出`satisfiable`。

我们只要使用一个set，存储所有的字符串，然后判断`!` + S是否在set中即可。
 
**Code:**

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    for(auto &s: S) cin >> s;
    unordered_set<string> h(S.begin(), S.end());
    for(auto &s: S) {
        if(h.count("!" + s)) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}
```

### Problem D Choose Me

**题目传送门：** https://atcoder.jp/contests/abc187/tasks/abc187_d

**解题思路：**
有N个村庄，每个村庄有$A_i$票投给Aoki，$B_i$票投给takahashi，takahashi可以去任意个村庄演讲，演讲完后，所有的票都会投给它，而没有演讲的村庄准备投给他的票都会作废，现在请问他至少要去多少个村庄演讲，才可以成功当选市长。


观察知，如果takahashi去第i个村庄演讲，那么Aoki减少$A_i$票，takahashi增加$A_i + B_i$票，那么，从总体上来看，相当于takahashi增加了$2*A_i + B_i$票。

我们初始设一个票数差X = $-\sum A_i$，每次演讲完后，$X +=  2 * A_i + B_i$,当票数差大于0时，即可成功当选市长。

**注:** 这题容易WA的地方就是不能直接贪心每次取和大的一个村庄，因为可能出现以下的情况：

比如:
```
5 2
4 3
3 5
```
那么我们按和排序选的是$3 + 5$，则票数差为$2 * 3 + 5 = 11$，而如果选$5 + 2$的话，则票数差为$2 * 5 + 2 = 12$，即按和最大的情况贪心来选择并不能取到最优解。

**Code:**

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() 
{
    int N;
    cin >> N;
    ll X = 0;
    vector<ll> vec(N);
    for(int i = 0; i < N; ++i) {
        ll A, B;
        cin >> A >> B;
        X -= A;
        vec[i] = 2 * A + B;
    }
    sort(vec.begin(), vec.end());
    ll ans = 0;
    while(X <= 0) {
        X += vec.back();
        vec.pop_back();
        ans++;
    }
    cout << ans << endl;

    return 0;
}
```

### Problem E Through Path

**题目传送门：** https://atcoder.jp/contests/abc187/tasks/abc187_e

**解题思路：**

不会

**Code:**

```cpp

```

### Problem F

**题目传送门：** https://atcoder.jp/contests/abc187/tasks/abc187_f

**解题思路：**
不会

**Code:**

```cpp

```