#include <stdio.h>
#define NUMBER 80
int main()
{
	int i,j;
	int num;
	int fensu[NUMBER];
	int fenbu[11]={0};
	
	printf("������ѧ������:\n");
	
	do{
		scanf("%d",&num);
		if(num < 1 || num > NUMBER)
			printf("\a������1-80֮�����\n");
		} while(num < 0 || num > NUMBER);
		
	printf("������ѧ���ɼ���\n");
	
	for(i = 0; i< num ; i++){
		printf("%2d��:",i+1);
		do{
			scanf("%d",&fensu[i]);
			if(fensu[i] < 0 || fensu[i] > 100)
				printf("\a������0-100֮�����\n");
			} while(fensu[i] < 0 || fensu[i] > 100); 
		fenbu[fensu[i]/10]++;
	}
	puts("\n---�ֲ�ͼ---");

	 
	for(i = 0; i < 10 ; i++){
		printf("%3d ��%3d:",10*i,(10*i)+9); 
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
