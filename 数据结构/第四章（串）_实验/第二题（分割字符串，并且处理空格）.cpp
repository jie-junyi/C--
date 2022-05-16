using namespace std;
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "SLinkString.h"

bool FenGe(SLinkString S1, SLinkString &S2, SLinkString &S3, int n)
{
    int i = 0, j;
    char ch[50];
    char ch1[50];
    //排除前面为空格的东西
    S1=S1->next;
    for (; S1->str == ' '; i++)
        S1 = S1->next;
    //判断S2的长度是否符合
    if (n > StrLength_L(S1) - i)
    {
        cout << "S2的长度n不符合要求" << endl;
        return false;
    }
    //赋值
    for (j = 0; j < n; j++)
    {
        ch[j] = S1->str;
        S1 = S1->next;
    }
    j--;
    //直到把后面的替换成非空格
    while(ch[j]==' ')
    {
        ch[j]=S1->str;
        S1=S1->next;
        if(S1==NULL)
        {
            cout <<"S2不符合规定"<<endl;
            return false;
        }
    }
    j=0;
    while(S1)
    {
        ch1[j++]=S1->str;
        S1=S1->next;
    }
    StrAssign_L(S2,ch);
    StrAssign_L(S3,ch1);
    return true;
}
int main()
{
    SLinkString S1, S2, S3;
    char ch[100];
    int n;
    cout << "请输入一行字符串:";
    gets(ch);
    StrAssign_L(S1, ch);
    cout << "请输入S2的长度: ";
    cin >> n;
    FenGe(S1, S2, S3, n);
    StrTraveres_L(S2);
    StrTraveres_L(S3);
    return 0;
}