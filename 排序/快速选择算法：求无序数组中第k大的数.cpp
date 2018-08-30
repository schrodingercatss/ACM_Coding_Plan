/*
*快速选择算法：找出第k大的数
*
*/
#include <bits/stdc++.h>
using namespace std;

int Partition(int a[],int lo,int hi)
{
    int i=lo,j=hi,pivot=a[lo];
    while(i<j){
        while(i<j&&a[j]>=pivot)j--;
        a[i]=a[j];
        while(i<j&&a[i]<=pivot)i++;
        a[j]=a[i];
    }
    a[i]=pivot;
    return i;
}

int quickSelect(int a[],int lo,int hi,int k)
{
    int i=lo,j=hi-lo;
    while(i<=j){
        int index=Partition(a,i,j);
        if(index==k-1)return a[index];
        else if(index<k-1)i=index+1;
        else j=index-1;
    }
    return 0;
}
int main()
{
    int arr[]={1,4,5,3,2};
    cout<<quickSelect(arr,0,4,3)<<endl;

    return 0;
}
