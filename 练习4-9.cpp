#include <stdio.h>
int main()
{
	int i=1,a;
	printf("请输入正整数：");	scanf("%d",&a);
	while(i<=a)
	{
		if((a-i+1)%2) putchar('+');
		else putchar('-');
		i++;
	 }
	 
	 return 0; 
}

