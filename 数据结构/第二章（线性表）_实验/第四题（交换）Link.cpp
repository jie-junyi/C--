using namespace std;
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include "LinkList.h"
typedef int ElemType;

bool Reverse(LinkList &head, LinkList p)
{
    LinkList s, k, q = head;
    int j = 0;
    while (q->next)
    {
        //保存q的前驱
        s = q;
        q = q->next;
        //找到p
        if (q == p)
        {
            j = 1;
            break;
        }
    }
    if (j != 1)
        return false;

    //改变三条线
    s->next = q->next;
    k = s->next->next;
    s->next->next = q;
    q->next = k;
    return true;

}
int main()
{
    LinkList mL, p;
    InitList_L(mL);
    ListInsert_L(mL, 0, 88);
    ListInsert_L(mL, 0, 77);
    ListInsert_L(mL, 0, 66);
    ListInsert_L(mL, 0, 55);
    ListInsert_L(mL, 0, 44);
    ListInsert_L(mL, 0, 33);
    p = mL;
    for (int i = 0; i < 3; i++)
        p = p->next;
    ListTraverse_L(mL);
    Reverse(mL, p);
    ListTraverse_L(mL);
    DestroyList_L(mL);
}