#include <stdio.h>
#define NUMBER 80
int main()
{
	int i,j,n;
	int num,max;
	int fensu[NUMBER];
	int fenbu[11]={0};
	
	printf("������ѧ������:\n");
	
	do{										/*�����ú���д*/ 
		scanf("%d",&num);
		if(num < 1 || num > NUMBER)
			printf("\a������1-80֮�����\n");
		} while(num < 0 || num > NUMBER);
		
	printf("������ѧ���ɼ���\n");
	
	for(i = 0; i< num ; i++){				/*ͬ�������ú���д*/ 
		printf("%2d��:",i+1);
		do{
			scanf("%d",&fensu[i]);
			if(fensu[i] < 0 || fensu[i] > 100)
				printf("\a������0-100֮�����\n");
			} while(fensu[i] < 0 || fensu[i] > 100); 
		fenbu[fensu[i]/10]++;
		}
		
	max=fenbu[0];
	for(i=1;i<11;i++)						/*ͬͬͬ�������ú���д*/ 
	{
		if(fenbu[i]>max)
		max=fenbu[i];
	}
	n=max; 
	
	for(j=0;j<n;j++)
	{
		for(i=0;i<11;i++)
		{
			if(fenbu[i]<max)
				printf("       ");
			else
				printf("   *   ");
		}
		max--;
		putchar('\n');
	}
	
	for(i=0;i<=80;i++)
		printf("-");
	
	putchar('\n');
	
	for(i=0;i<=9;i++)
	{
		printf("%2d-%2d  ",i*10,i*10+9);
	}
	
	printf(" 100");
	
	 return 0;
}
		
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
