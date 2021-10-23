#include <stdio.h>
#define NUMBER 80
int main()
{
	int i,j;
	int num;
	int fensu[NUMBER];
	int fenbu[11]={0};
	
	printf("请输入学生人数:\n");
	
	do{
		scanf("%d",&num);
		if(num < 1 || num > NUMBER)
			printf("\a请输入1-80之间的数\n");
		} while(num < 0 || num > NUMBER);
		
	printf("请输入学生成绩。\n");
	
	for(i = 0; i< num ; i++){
		printf("%2d号:",i+1);
		do{
			scanf("%d",&fensu[i]);
			if(fensu[i] < 0 || fensu[i] > 100)
				printf("\a请输入0-100之间的数\n");
			} while(fensu[i] < 0 || fensu[i] > 100); 
		fenbu[fensu[i]/10]++;
	}
	puts("\n---分布图---");

	 
	for(i = 0; i < 10 ; i++){
		printf("%3d —%3d:",10*i,(10*i)+9); 
		for(j= 0; j < fenbu[i] ; j++)
			putchar('*');
		putchar('\n');
	}
	
	printf("      100:");
		for(j= 0; j < fenbu[i] ; j++)
			putchar('*');
		putchar('\n');
return 0;
}
