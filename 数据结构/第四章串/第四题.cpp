using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "DSqString.h"
bool Equalsubstr(DSqString S, DSqString &sub)
{

    int i = 0, j, k, head, max, count;
    head = 0;  //������ ����Ӵ���i
    max = 1; // max ��¼���ֵ
    for (i = 0, j = 1; i < S.length && j < S.length; i = j, j++)
    {
        count = 1;
        while (S.str[i] == S.str[j])
        {
            j++;
            count++;
        }
        if (count > max) //�����µ����ֵ�ӻ�������head �� max{
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
    cout << "�����봮S(�ú����ַ�A)\n";
    cin >> S;

    //����ֵ
    if (StrAssign_Sq(Dsq, S))
    {
        cout << "��ʼ�����ɹ�\n";
    }
    else
    {
        cout << "��ʼ����ʧ��";
    }
    Equalsubstr(Dsq,Sub);
    //����
    StrTraveres_Sq(Sub);
    DestroyString_Sq(Dsq);
    DestroyString_Sq(Sub);
}
