using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "DSqString.h"
bool Equalsubstr(DSqString S, DSqString &sub)
{

    int i = 0, j, k, head, max, count;
    head = 0;  //保存其 最大子串的i
    max = 1; // max 记录最大值
    for (i = 0, j = 1; i < S.length && j < S.length; i = j, j++)
    {
        count = 1;
        while (S.str[i] == S.str[j])
        {
            j++;
            count++;
        }
        if (count > max) //发现新的最长等值子患，更新head 和 max{
        {
            head = i;
            max = count;
        }
    }
    if (max > 1)
    {
        if (!(sub.str = (char *)malloc(max * sizeof(char))))
            return false;
        for (k = 0; k < max; k++)
            sub.str[k] = S.str[k + head];
        sub.length = max;
        return true;
    }
    else
        return false;
}

int main(){
   DSqString Dsq,Sub;
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
    Equalsubstr(Dsq,Sub);
    //遍历
    StrTraveres_Sq(Sub);
    DestroyString_Sq(Dsq);
    DestroyString_Sq(Sub);
}
