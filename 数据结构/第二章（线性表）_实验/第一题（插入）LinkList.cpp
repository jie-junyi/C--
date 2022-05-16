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
    //移动查找元素
    //一直把p指向i之前的一个结点
    //i从0开始的
    while (p->next&&j<i)
    {
        p=p->next;
        j++;
    }
    //判断i之前是否有元素
    if(j!=i)
        return false;
    //赋值
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