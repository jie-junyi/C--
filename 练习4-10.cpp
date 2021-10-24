#include <stdio.h>
int main()
{
	int a;
	printf("请输入正整数：");		scanf("%d",&a); 
	while(a-->0)
	{
		putchar('*');
		putchar('\n');
	}
	
	return 0;
 } 
