#include <bits/stdc++.h>
#define ForMyLove return 0
using namespace std;
const int maxn = 100;
char s[maxn + 5], t[maxn + 5];

int main()
{
    int slen, tlen, ans1, ans2, i, j;
    while(cin>> s){
        cin>> t;
        slen = strlen(s);
        tlen = strlen(t);

        //s在左，t在右
        for(i = 0; i < slen; ++i){
            for(j = 0; j < tlen && i + j < slen; ++j){   //i + j < slen防止越界
                if(s[i + j] == '2' && t[j] =='2')
                    break;
            }
            if(j == tlen || i + j == slen)
                break;
        }
        ans1 = i + tlen;
        if(ans1 <slen) ans1 = slen;     //出现这种情况表示一个字符串包含另一个字符串，下面同理

        //t在左,s在右
        for(j = 0; j < tlen; ++j){
            for(i = 0; i < slen && j + i < tlen; ++i){
                if(t[j + i] =='2' && s[i] =='2')
                    break;
                }
            if(i == slen || j + i == tlen)
                break;
        }
        ans2 = j + slen;
        if(ans2 < tlen) ans2 = tlen;
        cout<< min(ans1, ans2) <<endl;
    }
    return 0;
}
