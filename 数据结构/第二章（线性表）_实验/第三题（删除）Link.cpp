using namespace std;
#include <stdlib.h>
#include <iomanip>
#include <iostream>
# include "LinkList.h"
typedef int ElemType;
/**
typedef struct Node
{
  ElemType data;
  struct Node *next;
} LNode, *LinkList;*/

bool List_Delete_equal(LinkList &L,ElemType e){
   LinkList s,k,p=L;
    //保存存在该x值的信息
    int j=0;
    //处理空表
    if(!p) exit(1);
    //找元素
    while(p->next){
        //用s来保存一下p的前驱;
        p=p->next;
        if(p->data==e){
            j=1;
            break;
        }
    }
    if(j!=1) return false;
    
    //找到第一个了,删除接下来其他的
    while(p->next){
        s=p;
        p=p->next;
        if(p->data==e){
            s->next=p->next;
            //用来释放结点
            k=p;
            //!!!!!!!!不能p指向下一个，得==p,还是到前驱
            p=s;
            free(k);
        }
    }
    return true;
}
int main(){
    LinkList mL;
    InitList_L(mL);
    ListInsert_L(mL,0,88);
    ListInsert_L(mL,0,88);
    ListInsert_L(mL,0,77);
    ListInsert_L(mL,0,66);
    ListInsert_L(mL,0,88);
    ListInsert_L(mL,0,88);
    ListInsert_L(mL,0,88);
    ListTraverse_L(mL);
    int i;
    cin>>i;
    List_Delete_equal(mL,i);
    ListTraverse_L(mL);
    DestroyList_L(mL);

}