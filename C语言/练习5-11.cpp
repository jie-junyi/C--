#include <stdio.h>
int main()
{
	int a[6][2];
	int i,j,sum=0,sumo=0;
	double aver1,aver2;
	
	printf("����������ѧ���ɼ�\n");								/*������ѧ�����������󣺸տ�ʼû��switch,���ݺ��ң����治����*/ 
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			switch(j){
				case 0 :printf("��%d��ͬѧ�������ĳɼ�:",i+1);   scanf("%d",&a[i][j]); break;
				case 1 :printf("��%d��ͬѧ������ѧ�ɼ�:",i+1);  scanf("%d",&a[i][j]); break; 
			}
			
	for(i=0;i<2;i++)											/*һ���������ʹ��sum
																aver���Զ��ʹ�ã�û��Ӱ��*/ 
		sum+=a[i][0];
		aver1=sum/2.0;
		printf("����\n�ܷ�Ϊ��%d\nƽ����Ϊ:%f\n",sum,aver1);	
	
	for(i=0;i<2;i++)
		sumo+=a[i][1];
		aver2=sumo/2.0;
		printf("��ѧ\n�ܷ�Ϊ��%d\nƽ����Ϊ:%f\n",sumo,aver2);
	
	for(i=0;i<2;i++)
		printf("ѧ��%d�ŵ��ܷ֣�%d\n    ƽ����%f\n",i+1,a[i][0]+a[i][1],(a[i][0]+a[i][1])/2.0);
	
return 0;	
	
}
