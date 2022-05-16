/**
 * 将计算机产生的n个随机数分为奇数、偶数两组,
 * 并将它们分别压入两个栈中，然后在屏幕上输出出栈序列
 *  成功！！！
 */
using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <cstdlib> // Header file 随机数

#include"SqStack.h"
typedef int ElemType;

int main()
{
    SqStack S, B;
    //初始化
    InitStack_Sq(S);
    InitStack_Sq(B);
    //随机数种子2
    srand(2);
    int a[10], b[10];
    int j = 0, k = 0;
    for (int i = 0; i < 20; i++)
    {
        int x;
        x = rand();
        if (x % 2 == 0)
        {
            a[j] = x;
            j++;
        }
        else
        {
            b[k] = x;
            k++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        Push_Sq(S,a[i]);
    }
    for (int i = 0; i < k; i++)
    {
        Push_Sq(B,b[i]);
    }
    for (int i = 0; i < j; i++)
    {   
        int x;
        Pop_Sq(S,x);
        cout<<x<<" ";
    }
    cout<<endl;
    for (int i = 0; i < k; i++)
    {   
        int x;
        Pop_Sq(B,x);
        cout<<x<<" ";
    }
    DestroyStack_Sq(S);
    DestroyStack_Sq(B);
}
