using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "DSqString.h"

//�滻ch1Ϊch2�ĺ���
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
    StrReplace(Dsq,"BBCDEFGAAAAA", 1,5);
    StrTraveres_Sq(Dsq);
    DestroyString_Sq(Dsq);
}
