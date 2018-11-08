#include <bits/stdc++.h>
#define ForMyLove return 0
using namespace std;
typedef long long ll;
double A[20][40];
ll B[20][40];

int main()
{
    //打表
    for(int m = 0; m <= 9; ++m){
        for(int e = 1; e <= 30; ++e){
            double mt = 1 - pow(2,-1-m);
            double ex = pow(2,e) - 1;
            double t = log10(mt) + ex * log10(2);
            B[m][e] = t;   //把浮点数赋值给整型的，浮点数小数部分会自动截断
            A[m][e] = pow(10,t-B[m][e]);
        }
    }
    string s;
    double a;
    ll b;
    while(cin>> s && s != "0e0"){
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == 'e'){s[i] =' ';break;}
        sscanf(s.c_str(),"%lf %lld", &a, &b);
        for(int m = 0; m <= 9; ++m){
            for(int e = 1; e <= 30; ++e){
                if(b == B[m][e] && (fabs(a - A[m][e]) < 1e-5)){
                    cout<< m << " " << e <<endl;
                    break;
                }
            }
        }
    }
    ForMyLove;
}
