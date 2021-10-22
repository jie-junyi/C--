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
	
	printf("请输入一个整数:");	scanf("%d",&a);
	printf("它的四次幂为：%d",sqr2(a));
	
	return 0; 
}
