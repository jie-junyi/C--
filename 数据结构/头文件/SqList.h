# define LIST_INIT_SIZE  100
# define LISTINCREMENT  10
using namespace std;
#include<stdlib.h>
#include <iomanip>
#include <iostream>
typedef int ElemType;
typedef struct {
ElemType  *elem;
    int length;
    int listsize;
    int incrementsize;
} SqList;



void InitList_Sq( SqList &L, int maxsize=LIST_INIT_SIZE, int incresize=LISTINCREMENT )
{
     L.elem=(ElemType *)malloc(maxsize*sizeof(ElemType));

     if(!L.elem)  exit(1);
      L.length=0;
      L.listsize=maxsize;
      L.incrementsize=incresize;
}// InitList_Sq


int ListLength_Sq(SqList L)
 {
      return L.length;
}// ListLength_Sq

bool ListEmpty_Sq(SqList L)
{
  if(L.length==0)
  return true;
  else return false;
}


int LocateElem_Sq( SqList L, ElemType e)
{
   for(int i=0;i<L.length;i++)
    if(L.elem[i]==e)  return i;
   return -1;
 }//LocateElem_Sq


bool ListInsert_Sq(SqList &L, int i, ElemType e)
{
int j;
      if(i<0||i>L.length)  return false;
      if(L.length>=L.listsize)  {
    L.elem=(ElemType *)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(ElemType));
         if(!L.elem) exit(1);
         L.listsize+=L.incrementsize;
        }
         for(j=L.length;j>i;j--)
L.elem[j]=L.elem[j-1];
         L.elem[i]=e;
         L.length++;
        return true;
}// ListInsert_Sq


bool ListInsert_Sq_1(SqList &L, ElemType e)
{

      int i,j;
      if(L.length>=L.listsize)  {
    L.elem=(ElemType *)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(ElemType));
         if(!L.elem) exit(1);
         L.listsize+=L.incrementsize;
        }
      for(i=0;i<L.length&&e>L.elem[i];i++);
	  for(j=L.length;j>i;j--)
L.elem[j]=L.elem[j-1];
         L.elem[i]=e;
         L.length++;
        return true;
}// ListInsert_Sq


bool ListDelete_Sq(SqList &L,int i, ElemType &e)
{
      int  j;
if(i<0||i>L.length) return false;
if(L.length<=0)  return false;
     e=L.elem[i];
      for(j=i+1;j<=L.length-1;j++)
        L.elem [j-1]=L.elem [j];
      L.length--;
      return true;
}// ListDelete_Sq


bool GetElem_Sq(SqList L,int i, ElemType &e)
{
     if(i<0||i>L.length) return false;
      if(L.length<=0)  return false;
      e=L.elem[i];
      return true;
}// GetElem_Sq


void ListTraverse_Sq(SqList L)
{
 int i;
 for(i=0;i<L.length;i++)
  cout<<setw(6)<<L.elem[i];
  cout<<endl;
}// ListTraverse_Sq


void DestroyList_Sq(SqList &L)
{
      free(L.elem);
	  L.elem=NULL;
      L.listsize=0;
      L.length=0;
}// DestroyList_Sq
