#include <stdio.h>
int main()
{
	float x,y,z;
	
	printf("����������������\n");
	puts("����x:\n");  scanf("%d",&x);
	puts("����y:\n");  scanf("%d",&y);
	
	z=(x/(y*1.0))*100;
	
	printf("x��y��%4.2f%%",z);
	return(0);
}
