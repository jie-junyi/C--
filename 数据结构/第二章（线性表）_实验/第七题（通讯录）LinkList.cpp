using namespace std;
#include <stdlib.h>
#include <iomanip>
#include <iostream>

typedef struct DNode
{
    char *name;
    char *address;
    char *phone;

} DNode;

typedef DNode ElemType;

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

bool ListInsert_L(LinkList &L, ElemType e)
{
    LinkList p, s, k;
    p = L;
    k = L;
    while (p->next)
    {
        k = p;
        p = p->next;
        if (p->data.name[0] >= e.name[0])
        {
            break;
        }
    }
    if ((s = (LNode *)malloc(sizeof(LNode))) == NULL)
        exit(1);
    //插在p的前面
    s->data = e;
    s->next = p;
    k->next = s;
    return true;
} // ListInsert_L

LNode *LocateElem_L(LinkList L, ElemType e)
{
    LinkList p;
    p = L->next;
    while (p && p->data.name != e.name)
        p = p->next;
    return p;
} // LocateElem_L

void ListTraverse_L(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        cout << setw(6) << p->data.name <<" "<<p->data.address<<" " << p->data.phone;
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

int main()
{
    LinkList mL, p;
    InitList_L(mL);
    DNode e1, e2, e3;
    e1.name = "zhangsan";
    e1.address = "wuhan";
    e1.phone = "19933267518";
    ListInsert_L(mL,e1);
    ListTraverse_L(mL);
    DestroyList_L(mL);
    return 0;
}