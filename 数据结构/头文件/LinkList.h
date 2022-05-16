using namespace std;
#include <stdlib.h>
#include <iomanip>
#include <iostream>
typedef int ElemType;
typedef struct Node
{
  ElemType data;
  struct Node *next;
} LNode, *LinkList;

void InitList_L(LinkList &L)
{
  L = (LNode *)malloc(sizeof(LNode));
  if (!L)
    exit(1);
  L->next = NULL;
} // InitList_L

int ListLength_L(LinkList L)
{
  LinkList p;
  int k = 0;
  p = L->next;
  while (p)
  {
    k++;
    p = p->next;
  }
  return k;
} // ListLength_L

LNode *LocateElem_L(LinkList L, ElemType e)
{
  LinkList p;
  p = L->next;
  while (p && p->data != e)
    p = p->next;
  return p;
} // LocateElem_L

bool ListInsert_L(LinkList &L, int i, ElemType e)
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

bool ListDelete_L(LinkList &L, int i, ElemType &e)
{
  LinkList p, q;
  int j;
  p = L;
  j = 0;
  while (p->next->next && j < i - 1)
  {
    p = p->next;
    j++;
  }
  if (j != i - 1)
    return false;
  q = p->next;
  p->next = q->next;
  e = q->data;
  free(q);
  return true;
} // ListDelete_L

bool GetElem_L(LinkList L, int i, ElemType &e)
{
  LinkList p;
  int j;
  p = L;
  j = 0;
  while (p->next && j < i)
  {
    p = p->next;
    j++;
  }
  if (j != i)
    return false;
  e = p->data;
  return true;
} // GetElem_L

void CreateList_L_Rear(LinkList &L, ElemType a[], int n)
{
  LinkList p, q;
  int i;
  L = (LinkList)malloc(sizeof(LNode));
  q = L;
  for (i = 0; i < n; i++)
  {
    p = (LinkList)malloc(sizeof(LNode));
    p->data = a[i];
    q->next = p;
    q = p;
  }
  q->next = NULL;
} // CreateList_L_Rear

void CreateList_L_Front(LinkList &L, ElemType a[], int n)
{
  LinkList p;
  int i;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  for (i = n - 1; i >= 0; i--)
  {
    p = (LinkList)malloc(sizeof(LNode));
    p->data = a[i];
    p->next = L->next;
    L->next = p;
  }
} // CreateList_L_Front

void ListTraverse_L(LinkList L)
{
  LinkList p = L->next;
  while (p)
  {
    cout << setw(6) << p->data;
    p = p->next;
  }
  cout << endl;
} // ListTraverse_L

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
