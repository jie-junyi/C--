#include <stdio.h>

int sumup(int n)
{
	int sum,i;
	for(i=1,sum=0;i<=n;i++)
		{
			sum+=i;
		}
 	return sum;
}

int main()
{
	int n;
	printf("请输入一个整数n：");		scanf("%d",&n);
	printf("1到整数n的和为：%d",sumup(n));
	
	return 0; 
}
