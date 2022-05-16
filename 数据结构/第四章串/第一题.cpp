using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "DSqString.h"

//替换ch1为ch2的函数
void StrReplace(DSqString &Dsq, char ch1, char ch2)
{
    for (int i = 0; i < Dsq.length; i++)
    {
        if (Dsq.str[i] == ch1){
            Dsq.str[i] =ch2;
            
        }
            
    }
}

int main()
{
    DSqString Dsq;
    char S[50];
    char ch1='A',ch2='B';
    cout << "请输入串S(该含有字符A)\n";
    cin >> S;

    //赋初值
    if (StrAssign_Sq(Dsq, S))
    {
        cout << "初始化串成功\n";

    }
    else
    {
        cout << "初始化串失败";
    }
    StrReplace(Dsq,ch1,ch2);
    StrTraveres_Sq(Dsq);
    DestroyString_Sq(Dsq);
}
