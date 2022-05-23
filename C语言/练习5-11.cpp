#include <stdio.h>
int main()
{
	int a[6][2];
	int i,j,sum=0,sumo=0;
	double aver1,aver2;
	
	printf("请输入六名学生成绩\n");								/*先输入学生分数，错误：刚开始没有switch,数据很乱，界面不美观*/ 
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			switch(j){
				case 0 :printf("请%d号同学输入语文成绩:",i+1);   scanf("%d",&a[i][j]); break;
				case 1 :printf("请%d号同学输入数学成绩:",i+1);  scanf("%d",&a[i][j]); break; 
			}
			
	for(i=0;i<2;i++)											/*一个变量多次使用sum
																aver可以多次使用，没有影响*/ 
		sum+=a[i][0];
		aver1=sum/2.0;
		printf("语文\n总分为：%d\n平均分为:%f\n",sum,aver1);	
	
	for(i=0;i<2;i++)
		sumo+=a[i][1];
		aver2=sumo/2.0;
		printf("数学\n总分为：%d\n平均分为:%f\n",sumo,aver2);
	
	for(i=0;i<2;i++)
		printf("学生%d号的总分：%d\n    平均分%f\n",i+1,a[i][0]+a[i][1],(a[i][0]+a[i][1])/2.0);
	
return 0;	
	
}
