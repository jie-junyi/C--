#include <stdio.h>
int v[80];
int n;
int min_of(int v[],int n)		/*��������Сֵ����*/ 
{
	int i;
	int min=v[0];
	for(i=1;i<n;i++)
		if(min>v[i]) min=v[i];
	
	return min;
}

void scan_of(void)				    /*��������ĺ���*/ 
{
	
	int i;
	printf("����������Ԫ�صĸ���n:");		scanf("%d",&n);
	for(i=0;i<n;i++)
		{
		printf("v[%d]=",i);	scanf("%d",&v[i]);}
		
	
}
int main()
{
	scan_of();
	printf("��СֵΪ��%d",min_of(v,n));
	return 0;
}
