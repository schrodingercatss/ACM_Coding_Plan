#include <bits/stdc++.h>
using namespace std;
struct node{
    double dis;
    double p;
}arr[10];

bool cmp(node a,node b)
{
    return a.dis<b.dis;
}
double d1,c,d2,p;
int n;
double fee =0;
int main()
{
    cin>>d1>>c>>d2>>p>>n;
    for(int i=1;i<=n;++i)cin>>arr[i].dis>>arr[i].p;
    arr[0].dis=0,arr[0].p=p;
    arr[n+1].dis=d1,arr[n+1].p=0;
    int palce=0;
    sort(arr+1,arr+n+1,cmp);
    int place=0;  //��ǰ���ڳ�վ
    double have=0; //��ǰʣ������
    while(place<=n){
        int k=place;
        while(c*d2>=arr[k+1].dis-arr[place].dis && k<=n+1){ //�ҵ��ȵ�ǰi�����˵ĳ�վ��ֱ��ȷ��Ŀ��
            k++;
            if(arr[k].p<=arr[place].p)break;
        }
        if(k==place){
            cout<<"No Solution"<<endl;    //���k==i�������Ѿ�û�г�վ�����ٵ����ˣ�ֱ�������޽�
            return 0;
        }
        double dist =arr[k].dis-arr[place].dis; //����Ҫǰ���ľ���
        if(arr[place].p>=arr[k].p){  //ǰ��һ���ͷѸ��͵ļ���վ������������������վ����
            if(have<=dist/d2){   //�����ǰ���Ͳ���������һ�����ø��͵ļ���վ���ڱ�����վ���㵽��һ������վ����
                fee+=(dist/d2-have)*arr[place].p;  //ʽ�Ӿ����˻���
                have=0;        //�ƶ�����һ������վ��û������
            }
            else have-=(dist/d2);  //���ʣ���������Դﵽ��������վ������
        }
        if(arr[k].p>arr[place].p){   //�����ƶ���һ���ͷѸ��ߵļ���վ��������ʱ����Ҫ������
            if(have<=dist/d2){    //��ǰ���Ͳ��ܵ�����һ������վ
                fee+=(c-have)*arr[place].p; //����
                have=c-dist/d2;  //�ƶ�����һ������վʣ������
            }
            else {      //��ǰ�����ܵ�����һ������վ
                fee+=(c-have+dist/d2)*arr[place].p;  //C-(have-dist/d2)����
                have=c-dist/d2;  //�ƶ�����һ������վʣ������
            }
        }
        place=k;  //�ƶ�����һ������վ
    }
    cout<<fixed<<setprecision(2)<<fee<<endl;

    return 0;
}
