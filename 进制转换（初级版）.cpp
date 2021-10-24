#include <stdio.h> 

int main()
{ int n,k,a=0,b=1;									/*n小时可行，但n过大会出错*/ 
							
	printf("请输入一个整数n:");		scanf("%d",&n);		
	printf("请再输入一个整数k:");	scanf("%d",&k);
	
 while(n>0)
{													/*?????????????????*/
	a=(n%k)*b+a;
	b=10*b;
	n= n/k;
}
	printf("%016d",a);
	
	return 0;
}
