using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "DSqString.h"

//�滻ch1Ϊch2�ĺ���
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
    StrReplace(Dsq,ch1,ch2);
    StrTraveres_Sq(Dsq);
    DestroyString_Sq(Dsq);
}
