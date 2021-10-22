#include <stdio.h>
int v[80];
int n;
int min_of(int v[],int n)		/*求数组最小值函数*/ 
{
	int i;
	int min=v[0];
	for(i=1;i<n;i++)
		if(min>v[i]) min=v[i];
	
	return min;
}

void scan_of(void)				    /*输入数组的函数*/ 
{
	
	int i;
	printf("请输入数组元素的个数n:");		scanf("%d",&n);
	for(i=0;i<n;i++)
		{
		printf("v[%d]=",i);	scanf("%d",&v[i]);}
		
	
}
int main()
{
	scan_of();
	printf("最小值为：%d",min_of(v,n));
	return 0;
}
