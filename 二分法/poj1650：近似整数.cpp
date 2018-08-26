#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
void solve(double a,int l)
{
    double minv=INF;
    int n=1,d=1;
    int t1=n,t2=d;
    while(n<=l&&d<=l){
        double exp=a-(double)n/d;
        double exp1=fabs(exp);
        if(exp1<minv){
            minv=exp1;
            t1=n,t2=d;
        }
        if(exp>0)n++;
        else d++;
    }
    cout<<t1<<" "<<t2<<endl;
}
int main()
{
    double a;
    int l;
    while(cin>>a>>l){
        solve(a,l);
    }
    return 0;
}
