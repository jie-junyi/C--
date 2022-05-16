using namespace std;
#include <stdlib.h>
#include <iomanip>
#include <iostream>

typedef int ElemType;
typedef struct Node
{
  ElemType data;
  struct Node *next;
  struct Node *prior;
} LNode, *LinkList;

void InitList_L_1(LinkList &L)
{
  L = (LNode *)malloc(sizeof(LNode));
  if (!L)
    exit(1);
  L->next = NULL;
} // InitList_L

bool ListInsert_L_1(LinkList &L, int i, ElemType e)
{
  LinkList p, s;
  int j;
  p = L;
  j = 0;
  while (p->next && j < i)
  {
    p = p->next;
    j++;
  }
  if (j != i )
    return false;

  if ((s = (LNode *)malloc(sizeof(LNode))) == NULL)
    exit(1);
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
} // ListInsert_L

bool QianQu(LinkList &L){
    LinkList s,k,j,p=L;
    //´¦Àí¿Õ±í
    if(!p) exit(1);

    while(p->next){
        s=p;
        p=p->next;
        p->prior=s;
    }
    p->next=L;
    L->prior=p;
    return true;
}
void ListTraverse_L_1(LinkList L)
{
  LinkList p = L->next;
  while (p)
  { 
    cout << setw(6) << p->data;
    p = p->next;
    if(p==L->next)
    break;
  }
  cout << endl;
} // ListTraverse_L

void ListTraverse_L_2(LinkList L){
    LinkList p=L->prior;
    while(p)
    {
        cout << setw(6) << p->data;
        p = p->prior;
        if(p==L->prior)
            break;
    }
    cout << endl;
}
void DestroyList_L(LinkList &L)
{
  LinkList p, p1;
  p = L;
  while (p)
  {
    p1 = p;
    p = p->next;
    free(p1);
  }
  L = NULL;
} // DestroyList_L
int main()
{
    LinkList mL;
    InitList_L_1(mL);
    ListInsert_L_1(mL, 0, 88);
    ListInsert_L_1(mL, 0, 77);
    ListInsert_L_1(mL, 0, 11);
    ListInsert_L_1(mL, 0, 55);
    ListInsert_L_1(mL, 0, 44);
    ListInsert_L_1(mL, 0, 22);
    ListTraverse_L_1(mL);
    QianQu(mL);
    ListTraverse_L_2(mL);
    DestroyList_L(mL);
}
