#include <stdio.h>
int q;						/*ȫ����������qֵ���ں����м������main��ʹ��*/ 
int min_of(int v[],int n)		/*��������Сֵ����*/ 
{
	int i;
	int min=v[0];
	for(i=1;i<n;i++)
		if(min>v[i])
		{
		 min=v[i];
		 q=i;}				/*�ӵ�*/ 
	
	return min;
}
int main()
{

	int i,n;
	int v[80];
	
	printf("����������Ԫ�صĸ���n:");		scanf("%d",&n);
	for(i=0;i<n;i++)
		{ 
		 printf("v[%d]=",i);	scanf("%d",&v[i]);}
		
	printf("��СֵΪ��%d\n��Ԫ��Ϊ��v[%d]",min_of(v,n),q);		/*�Ľ�*/ 
}
