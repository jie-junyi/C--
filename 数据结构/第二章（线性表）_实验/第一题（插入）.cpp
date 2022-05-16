using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "SqList.h"

#define LISTINCREMENT 10 //��Ĭ�ϵģ������ռ�Ĵ�С
/**
typedef struct
{
    ElemType *elem;    // �洢����Ԫ�ص�һά������׵�ַ
    int length;        // ���Ա�ĵ�ǰ����
    int listsize;      // ��ǰ����������������� ElemType Ϊ��λ��
    int incrementsize; // �����ռ������� ElemType Ϊ��λ��
} SqList;       */     // ��̬˳���

bool List_Insert_Sq(SqList &L, int i, ElemType e)
{
    int j=L.length;
    //����==length,��Ϊ���Բ��������һ��λ��
    if(i<0||i>L.length)
        return false;
    //����ռ�
    if(L.length>=L.listsize){
        L.elem=(ElemType*)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(ElemType));
        if(!L.elem) exit(1);
        L.listsize=L.listsize+L.incrementsize;
    }
    //�ƶ�λ��
    for(;j>i;j--){
        L.elem[j]=L.elem[j-1];
    }
    L.elem[i]=e;
    L.length++;
    return true;
}// ListInsert_Sq

int main(){
    SqList mSqlist;
    InitList_Sq(mSqlist,100,10);
    ListInsert_Sq(mSqlist,0,99);
    List_Insert_Sq(mSqlist,0,100);
    ListTraverse_Sq(mSqlist);
    DestroyList_Sq(mSqlist);
}