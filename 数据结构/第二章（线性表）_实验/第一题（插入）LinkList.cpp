using namespace std;
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include "LinkList.h"

typedef int ElemType;
/**
typedef struct Node
{
  ElemType data;
  struct Node *next;
} LNode, *LinkList;*/

bool List_Inserts_Link(LinkList &L,int i,ElemType e){
    LinkList s,p=L;
    int j=0;
    //�ƶ�����Ԫ��
    //һֱ��pָ��i֮ǰ��һ�����
    //i��0��ʼ��
    while (p->next&&j<i)
    {
        p=p->next;
        j++;
    }
    //�ж�i֮ǰ�Ƿ���Ԫ��
    if(j!=i)
        return false;
    //��ֵ
    s=(LNode*)malloc(sizeof(LNode));
    if(!s) exit(1);
    s->data=e;
    s->next=p->next;
    p->next=s;
}
int main(){
    LinkList mL;
    InitList_L(mL);
    ListInsert_L(mL,0,88);
    List_Inserts_Link(mL,0,55);
    ListTraverse_L(mL);
    DestroyList_L(mL);

}