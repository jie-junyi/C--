using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "SqList.h"

#define LISTINCREMENT 10 //（默认的）增补空间的大小
/**
typedef struct
{
    ElemType *elem;    // 存储数据元素的一维数组的首地址
    int length;        // 线性表的当前长度
    int listsize;      // 当前分配的数组容量（以 ElemType 为单位）
    int incrementsize; // 增补空间量（以 ElemType 为单位）
} SqList;       */     // 动态顺序表

bool List_Insert_Sq(SqList &L, int i, ElemType e)
{
    int j=L.length;
    //可以==length,因为可以插入在最后一个位置
    if(i<0||i>L.length)
        return false;
    //分配空间
    if(L.length>=L.listsize){
        L.elem=(ElemType*)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(ElemType));
        if(!L.elem) exit(1);
        L.listsize=L.listsize+L.incrementsize;
    }
    //移动位置
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