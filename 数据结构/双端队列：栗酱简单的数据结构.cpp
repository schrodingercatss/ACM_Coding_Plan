#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int>dq;
    int n,m,a,op;
    cin>>n>>m;
    while(m--){
        cin>>op;
        if(op==1){
            cin>>a;
            dq.push_front(a);
        }
        else if(op==2)dq.pop_front();
        else if(op==3){
            cin>>a;
            dq.push_back(a);
        }
        else if(op==4)dq.pop_back();
        else if(op==5)reverse(dq.begin(),dq.end());
        else if(op==6){
            cout<<dq.size()<<endl;
            for(auto it=dq.begin();it!=dq.end();++it){
                if(it==dq.begin())cout<<*it;
                else cout<<" "<<*it;
            }
            puts("");
        }
        else sort(dq.begin(),dq.end());
    }
    return 0;
}
