/**
 * �������������n���������Ϊ������ż������,
 * �������Ƿֱ�ѹ������ջ�У�Ȼ������Ļ�������ջ����
 *  �ɹ�������
 */
using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <cstdlib> // Header file �����

#include"SqStack.h"
typedef int ElemType;

int main()
{
    SqStack S, B;
    //��ʼ��
    InitStack_Sq(S);
    InitStack_Sq(B);
    //���������2
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
