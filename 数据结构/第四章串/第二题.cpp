using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "DSqString.h"

//ɾ������
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
    StrDelete(Dsq, ch1);
    StrTraveres_Sq(Dsq);
    DestroyString_Sq(Dsq);
}
