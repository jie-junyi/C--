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

bool List_Delete_Link(LinkList &L,ElemType e){
    LinkList s,p=L;
    //保存存在该x值的信息
    int j=0;
    if(!p) exit(1);
    while(p->next){
        //用s来保存一下p的前驱;
        s=p;
        p=p->next;
        if(p->data==e){
            j=1;
            break;
        }
    }
    if(j!=1) return false;
    //删除
    s->next=p->next;
    //释放一下空间
    free(p);
}
int main(){
    LinkList mL;
    InitList_L(mL);
    ListInsert_L(mL,0,88);
    ListInsert_L(mL,0,88);
    ListInsert_L(mL,0,77);
    ListInsert_L(mL,0,66);
    ListInsert_L(mL,0,88);
    ListTraverse_L(mL);
    int i;
    cin>>i;
    List_Delete_Link(mL,i);
    ListTraverse_L(mL);
    DestroyList_L(mL);

}
