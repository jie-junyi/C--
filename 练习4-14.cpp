 #include <stdio.h>
 int main()
 {
    int i,n;
 	int x;
 	 
 	printf("请输入一个整数：");	scanf("%d",&x);
 	
 	for(i=1,n=0;i<=x;i++)
 	{
 		if(i%10==0) n++;
 		if(i<10*(n+1))  printf("%d",i-(10*n));
	 }
	  
		
 }
