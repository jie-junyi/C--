#include "iostream"
#include "stdlib.h"
using namespace std;
#define N 3

void jiafa(int a[][N],int b[][N],int c[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}

void chengfa(int a[][N],int b[][N],int c[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
           int sum=0;
           for(int k=0;k<N;k++)
           {
               int x;
               x=a[i][k]*b[k][j];
               sum+=x;
           }
           c[i][j]=sum;
        }
    }
}

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
    int a[N][N],b[N][N],c[N][N];
    cout<<"请输入矩阵A的元素"<<endl;
    shuru(a);
    cout<<"请输入矩阵B的元素"<<endl;
    shuru(b);
    cout<<"矩阵相加："<<endl;
    jiafa(a,b,c);
    shuchu(c);
    cout<<"矩阵相乘："<<endl;
    chengfa(a,b,c);
    shuchu(c);

}
