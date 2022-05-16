using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "DSqString.h"

//删除函数
void StrDelete(DSqString &Dsq, char ch)
{
    for (int i = 0; i < Dsq.length; i++)
    {
        if (Dsq.str[i] == ch)
        {
            StrDelete_Sq(Dsq, i, 1);
            i--;
        }
    }
}

int main()
{
    DSqString Dsq;
    char S[50];
    char ch1 = 'A';
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
    StrDelete(Dsq, ch1);
    StrTraveres_Sq(Dsq);
    DestroyString_Sq(Dsq);
}
