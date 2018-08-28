#include <bits/stdc++.h>
using namespace std;
int arr[40][40];
int n;

void solve()
{
    int person = pow(2,n);
    arr[1][1]=1;
    int k=1;  //代表当前方阵大小
    do{
        for(int i=1;i<=k;++i)
            for(int j=1;j<=k;++j){
                arr[i][j+k]=arr[i][j]+k;  //构造右上角方阵
                arr[i+k][j]=arr[i][j+k];  //构造左下角方阵
                arr[i+k][j+k]=arr[i][j];  //构造右下角方阵
        }
        k*=2;
    }while(!(k==person));
    for(int i=1;i<=person;++i){
        for(int j=1;j<=person;++j)
            cout<<setw(4)<<arr[i][j];
        cout<<endl;
    }
}
int main()
{
    while(cin>>n){
        solve();
    }

    return 0;
}
