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
	printf("������һ������n��");		scanf("%d",&n);
	printf("1������n�ĺ�Ϊ��%d",sumup(n));
	
	return 0; 
}
