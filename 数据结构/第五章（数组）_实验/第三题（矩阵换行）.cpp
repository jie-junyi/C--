#include "iostream"
#include "stdlib.h"
using namespace std;
#define N 3

//平均数
void average(int a[][N],int b[])
{
    for(int i=0;i<N;i++)
    {
        int sum=0;
        for(int j=0;j<N;j++)
        {
            sum+=a[i][j];
        }
        b[i]=sum/N;
    }
}
//输入
void shuru(int a[][N])
{
    for(int i=0;i<N;i++)
    {
        cout<<"请输入第"<<i+1<<"行元素:";
        for(int j=0;j<N;j++)
        {
            int x;
            cin>>x;
            a[i][j]=x;
        }
    }
}
//换行
void huanhang(int a[][N],int i,int k)
{
    for(int j=0;j<N;j++)
    {
        int b;
        b=a[i][j];
        a[i][j]=a[k][j];
        a[k][j]=b;
    }
}
void shuchu(int a[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int a[N][N],aver[N];
    int k,temp;
    cout<<"请输入矩阵的元素"<<endl;
    shuru(a);
    average(a,aver);

    //比较换行
    for(int i=0;i<N;i++)
    {
        k=i;
        for(int j=i+1;j<N;j++)
        {
            if(aver[j]<aver[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            huanhang(a,i,k);
            temp=aver[i];
            aver[i]=aver[k];
            aver[k]=temp;
        }
    }
    shuchu(a);
}