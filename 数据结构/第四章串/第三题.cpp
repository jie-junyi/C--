using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "SLinkString.h"

//…æ≥˝∫Ø ˝
void StrDelete(SLinkString &Dsq, char ch)
{
    SLinkString p=Dsq->next,r,q=Dsq;
    for (int i = 0; p; i++)
    {
        if (p->str == ch)
        {
            q->next=p->next;
            r=p;
            p=p->next;
		    free(r);
        }
        else{
            //’“
            q=p;
            p=p->next;
        }
    }
}

int main()
{
    SLinkString LS;
    char S[50];
    char ch1 = 'A';
    cout << "«Î ‰»Î¥ÆS(∏√∫¨”–◊÷∑˚A)\n";
    cin >> S;

    //∏≥≥ı÷µ
    StrAssign_L(LS, S);

    StrDelete(LS, ch1);
    StrTraveres_L(LS);
    DestroyString_L(LS);
}