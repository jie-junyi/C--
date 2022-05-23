#include <stdio.h>
int main()
{
	int no;
	
	printf("请输入一个整数:"); scanf("%d",&no);
	switch(no%2){
		case 0 :puts("该数是偶数");		break;
		default:puts("该数是奇数");		break; 
	}
	 
} 
