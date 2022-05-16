#define NODENUM 8
#define NULL '\0'
#define LEN sizeof(nodetype)
#include "stdio.h"
#include "stdlib.h"
typedef struct node
 {
  char Data[NODENUM];
  struct node *Next;
  }nodetype;

 typedef struct
 {
   int Length;
   nodetype *Next;
   }headtype;

int SubStrL2(headtype *s, headtype **t, int i, int k)
{
  nodetype *p,*v;
  int j,n,m,w,l,u;
  n=s->Length;
  p=s->Next;
  if(i>=0&&i<n&&k>=0&&k<=n-i)
  {
     m=i/NODENUM+1;
     printf("i=%d\n",m);
     for(j=1;j<m;j++)p=p->Next;
     *t=(headtype *)malloc(sizeof(headtype));
     (*t)->Length=k;
     (*t)->Next=(nodetype *)malloc(sizeof(nodetype));
     v=(*t)->Next;
     w=1;
     u=m;
     l=i;

     for(j=0;j<k;j++)
     {
      if(j>=NODENUM *w)
      {
       w++;
       v->Next=(nodetype *)malloc(sizeof(nodetype));
       v=v->Next;
      }
      if(l>=NODENUM *u)
      {
       u++;
       p=p->Next;
      }
      v->Data[j%NODENUM]=p->Data[l%NODENUM];
      l++;
      }
      return 1;
    }
     else
      return 0;
    }

     void creat(headtype **head)
     {nodetype *p,*q;
      int i,j=0,k=1;
      char c;
      *head=(headtype*)malloc(sizeof(headtype));
      (*head)->Next=(nodetype*)malloc(LEN);
      p=q=(*head)->Next;
      for(i=0;i<NODENUM;i++)
      {c=getchar();
       p->Data[i]=c;j++;}
       while(k<3)
       {k++;
        p=(nodetype*)malloc(LEN);
        for(i=0;i<NODENUM;i++)
	{c=getchar();
         if(c=='#'){p->Data[i]='\0';break;}
         else  {p->Data[i]=c;j++;}
         }

         q->Next=p;
         q=p;
        }
        q->Next=NULL;
        (*head)->Length=j;

     /*   p=(*head)->Next;
        while(p!=NULL)
        {for(i=0;i<NODENUM&&p->Data[i]!='\0';i++)
         printf("%c",p->Data[i]);
	 p=p->Next;
        }*/
        }

    int main()
     {
      int i;
      headtype *s1,*t1;
      nodetype *p;
      creat(&s1);
      printf("string s1 length is:%d\n",s1->Length);
      printf("string s1 is:");
      p=s1->Next;
        while(p!=NULL)
        {for(i=0;i<NODENUM&&p->Data[i]!='\0';i++)
         printf("%c",p->Data[i]);
         p=p->Next;}
         printf("\n");
	if(SubStrL2(s1,&t1,5,5))printf("success\n");
             else printf("fail\n");
        printf("substr t1 length is:%d\n",t1->Length);
        printf("substr t1 is:");
         p=t1->Next;
        while(p!=NULL)
        {
         for(i=0;i<NODENUM&&p->Data[i]!='\0';i++)
         putchar(p->Data[i]);
         p=p->Next;}
         printf("\n");
         return 1;
       }
