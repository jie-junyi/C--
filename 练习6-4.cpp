#include <stdio.h>

int sqr(int a)
{
	return a*a;
} 

int sqr2(int a)
{
	return sqr(sqr(a));
}

int main()
{
	int a;
	
	printf("������һ������:");	scanf("%d",&a);
	printf("�����Ĵ���Ϊ��%d",sqr2(a));
	
	return 0; 
}
