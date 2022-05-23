#include <stdio.h>
int q;						/*全局声明，令q值可在函数中计算而在main中使用*/ 
int min_of(int v[],int n)		/*求数组最小值函数*/ 
{
	int i;
	int min=v[0];
	for(i=1;i<n;i++)
		if(min>v[i])
		{
		 min=v[i];
		 q=i;}				/*加的*/ 
	
	return min;
}
int main()
{

	int i,n;
	int v[80];
	
	printf("请输入数组元素的个数n:");		scanf("%d",&n);
	for(i=0;i<n;i++)
		{ 
		 printf("v[%d]=",i);	scanf("%d",&v[i]);}
		
	printf("最小值为：%d\n该元素为：v[%d]",min_of(v,n),q);		/*改进*/ 
}
