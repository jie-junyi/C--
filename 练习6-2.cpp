#include <stdio.h>
int min3(int a,int b,int c){
	int min=a;
	if(b<min) min=b;
	if(c<min) min=c;
	
    return min;
} 

int main()
{
	int a,b,c;
	puts("��������������");
	printf("����a��");	scanf("%d",&a); 
	printf("����b��"); 	scanf("%d",&b); 
	printf("����c��"); 	scanf("%d",&c); 
	
	printf("����������С��Ϊ��%d",min3(a,b,c));
	
	return 0;

}
