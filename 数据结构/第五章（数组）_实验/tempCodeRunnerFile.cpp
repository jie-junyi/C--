#include"stdlib.h"
#include"iostream"
using namespace std;

int main()
{
    int m,n;    //m行n列
    int i,j;
    int maxj[20]={0},mini[20]={0};
    int a[20][20]={0};
    cout<<"请分别输入行和列：";
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        cout<<"请输入第"<<i<<"行元素：";
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }//输入m*n矩阵元素

    for(i=0;i<m;i++)
    {
        mini[i]=a[i][0];
        for(j=1;j<n;j++)
        {
            if(a[i][j]<mini[i])mini[i]=a[i][j];
        }
    }//求每行的最小值是多少，并用mini记录
    for(j=0;j<n;j++)
    {
        maxj[j]=a[0][j];
        for(i=1;i<m;i++)
        {
            if(a[i][j]>maxj[j])maxj[j]=a[i][j];
        }
    }//求每列的最大值是多少，并用maxj记录
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if((mini[i]==maxj[j])&&(mini[i]==a[i][j]))cout<<a[i][j];//当该元素的值等于本行的最小值、等于本列的最大值时，即为马鞍点，输出该元素
        }
    }
    return 0;
}