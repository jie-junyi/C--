#include<stdio.h>

int v1[80],v2[80];			/*��������������ִ�в�����������ֵ������Ҫȫ������*/ 
void rev_intary(int v[],int n)			/*�������к���*/ 
{
	int i,tmp;
	for(i=0;i<n/2;i++)
	{
		tmp=v[i];
		v[i]=v[n-i-1];
		v[n-i-1]=tmp;
	}
 } 

void intary_rcpy(int v1[],const int v2[],int n)			/*���ƺ���*/ 
{
	int i;
	for(i=0;i<n;i++)
	{
		v1[i]=v2[i];
	}
}

int main()
{
	int n,i;
	printf("����������v2Ԫ�ظ���n��");		scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("v2[%d]:",i);		scanf("%d",&v2[i]);
		
	 }
	 rev_intary(v2, n);
	 intary_rcpy(v1,v2,n);
	 
	 putchar('\n');
	 for(i=0;i<n;i++) 
	 printf("v1[%d]=%d\n",i,v1[i]);
	 
	 return 0;
}
