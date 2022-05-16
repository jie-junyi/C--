using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "DSqString.h"

//替换ch1为ch2的函数
void StrReplace(DSqString &Dsq, char *ch, int i, int j)
{
    int q = 0;
    for (int k = i ; k < j-1; k++, q++)
    {
        Dsq.str[k]=ch[q];
    }
}

int main()
{
    DSqString Dsq;
    char S[50];
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
    StrReplace(Dsq,"BBCDEFGAAAAA", 1,5);
    StrTraveres_Sq(Dsq);
    DestroyString_Sq(Dsq);
}
