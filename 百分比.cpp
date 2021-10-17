#include <stdio.h>
int main()
{
	float x,y,z;
	
	printf("请输入两个整数：\n");
	puts("整数x:\n");  scanf("%d",&x);
	puts("整数y:\n");  scanf("%d",&y);
	
	z=(x/(y*1.0))*100;
	
	printf("x是y的%4.2f%%",z);
	return(0);
}
