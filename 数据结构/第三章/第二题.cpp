using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
typedef int ElemType;

typedef struct Node {
 ElemType data;
struct  Node *next;
}LNode,*LinkQueue;

void InitQueue_L(LinkQueue &L){
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    if(!L) exit(1);
}//尾指针指向头结点

bool EnQueue_L(LinkQueue &L,ElemType e){
    LinkQueue s;
    if((s=(LNode*)malloc(sizeof(LNode)))==NULL) return false;
    s->data=e;
    //将尾指针指向新节点，并且后续为队首
    if(L->next==NULL){
        s->next=L;
        L->next=s;
        L=s;
     }
    else{
        s->next=L->next;
        L->next=s;
        L=s;
    }
    return 0;
}

bool DeQueue_L(LinkQueue &L,ElemType &e){
    LinkQueue s;
    if(!L==NULL) return false;
    if(L->next==NULL) {
        free(L);
        return true;
    }
    
    else{
    s=L->next;
    e=s->data;
    L->next=s->next;
    free(s);
    return true;
    }
}

