#include <stdio.h> 

int main()
{ int n,k,a=0,b=1;									/*nСʱ���У���n��������*/ 
							
	printf("������һ������n:");		scanf("%d",&n);		
	printf("��������һ������k:");	scanf("%d",&k);
	
 while(n>0)
{													/*?????????????????*/
	a=(n%k)*b+a;
	b=10*b;
	n= n/k;
}
	printf("%016d",a);
	
	return 0;
}
