#include <bits/stdc++.h>
#define ForMyLove return 0
using namespace std;

struct rec{
    int length; //长
    int width; //宽
}arr[6];

bool cmp(rec a, rec b)
{
    if(a.length == b.length)
        return a.width < b.width;
    return a.length < b.length;
}

int main()
{
    while(cin>> arr[0].length >> arr[0].width){
        if(arr[0].length > arr[0].width) swap(arr[0].length, arr[0].width);

        for(int i = 1; i < 6; ++i){
            cin>> arr[i].length >> arr[i].width;
            if(arr[i].length > arr[i].width) swap(arr[i].length, arr[i].width);
        }
        sort(arr,arr+6,cmp); //对矩形进行排序

        bool flag = true;
        for(int i = 0; i < 6; i += 2)
            if(arr[i].length != arr[i+1].length || arr[i].width != arr[i+1].width) flag = false;
        if(arr[0].length != arr[2].length || arr[0].width != arr[4].length || arr[2].width != arr[4].width) flag = false;

        if(flag) cout<< "POSSIBLE" <<endl;
        else cout<< "IMPOSSIBLE" <<endl;
    }
    return 0;
}
