using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "SLinkString.h"

//…æ≥˝∫Ø ˝
void StrReplace(SLinkString &Dsq, char* ch,int i,int j)
{
    SLinkString p=Dsq->next;
    for(int k=0;k<i;k++){
        p=p->next;
    }
    int q=0;
    for (int k = i ; k < j-1; k++,q++)
    {
       p->str=ch[q];
       p=p->next;
    }
}

int main()
{
    SLinkString LS;
    char S[50];
    cout << "«Î ‰»Î¥ÆS(∏√∫¨”–◊÷∑˚A)\n";
    cin >> S;

    //∏≥≥ı÷µ
    StrAssign_L(LS, S);

    StrReplace(LS,"BBCDEFGBBBBBB",1,5);
    StrTraveres_L(LS);
    DestroyString_L(LS);
}