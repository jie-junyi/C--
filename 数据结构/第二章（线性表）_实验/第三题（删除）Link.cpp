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
    //������ڸ�xֵ����Ϣ
    int j=0;
    //����ձ�
    if(!p) exit(1);
    //��Ԫ��
    while(p->next){
        //��s������һ��p��ǰ��;
        p=p->next;
        if(p->data==e){
            j=1;
            break;
        }
    }
    if(j!=1) return false;
    
    //�ҵ���һ����,ɾ��������������
    while(p->next){
        s=p;
        p=p->next;
        if(p->data==e){
            s->next=p->next;
            //�����ͷŽ��
            k=p;
            //!!!!!!!!����pָ����һ������==p,���ǵ�ǰ��
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