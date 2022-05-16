using namespace std;
#include <stdlib.h>
#include <iomanip>
#include <iostream>
# include "LinkList.h"
typedef int ElemType;
//����
bool Reverse(LinkList &head, LinkList p)
{
    LinkList s, k, q = head;
    int j = 0;
    while (q->next)
    {
        //����q��ǰ��
        s = q;
        q = q->next;
        //�ҵ�p
        if (q == p)
        {
            j = 1;
            break;
        }
    }
    if (j != 1)
        return false;

    //�ı�������
    s->next = q->next;
    k = s->next->next;
    s->next->next = q;
    q->next = k;
    
    return true;
}

bool MinNumb(LinkList &L){
    LinkList s,k,j,p=L;
    //����ձ�
    if(!p) exit(1);
    int min=p->next->data;
    while(p->next){
        s=p;
        p=p->next;
        if(p->data<min){
            min=p->data;
            k=s;
            j=p;
        }
    }
    if(min%2==0){
        k=j->next;
        j->next=j->next->next;
        free(k);
    }
    else{
        Reverse(L,j);
    }
    return true;
    
}
int main()
{
    LinkList mL, p;
    InitList_L(mL);
    ListInsert_L(mL, 0, 88);
    ListInsert_L(mL, 0, 77);
    ListInsert_L(mL, 0, 11);
    ListInsert_L(mL, 0, 55);
    ListInsert_L(mL, 0, 44);
    ListInsert_L(mL, 0, 33);
    ListTraverse_L(mL);
    MinNumb(mL);
    ListTraverse_L(mL);
    DestroyList_L(mL);
}