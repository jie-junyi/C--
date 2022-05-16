using namespace std;
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "DSqString.h"

void ShuRu(char ch1[])
{
	char ch;
	cout << "请输入一个字符串(输入#字符结束输入)" << endl;
	cin >> ch;
	for (int i = 0; i<150&&ch != '#'; )
	{	
		ch1[i]=ch;
		//控制输入字符的合法性
		if ((ch1[i] >= '0' && ch1[i] <= '9')||(ch1[i] >= 'A' && ch1[i] <= 'Z'))
		{
			cin >> ch;
			i++;
		}
		else
		{
			cout << "输入字符错误！" << endl;
			cin >> ch;
		}
	}
}
void TongJi(DSqString Ds,int times[])
{
	int num;
	for(int i=0;i<Ds.length;i++)
	{
		if (Ds.str[i] >= '0' && Ds.str[i] <= '9')
		{
			num = Ds.str[i] - '0'; // times[0]~times[9]用于记录'0'~‘9’的频度
			times[num]++;
		}
		else if (Ds.str[i] >= 'A' && Ds.str[i] <= 'Z')
		{
			num = Ds.str[i] - 'A' + 10; // times[10]~times[35]用于记录A到Z的频度
			times[num]++;
		}
	}
}
void ShuChu(int t[])
{
	for(int i=0;i<=9;i++)
	{
		cout<<char(i+char('0'))<<": "<<t[i]<<endl;
	}
	for(int i=10;i<=35;i++)
	{
		cout<<char(i-10+char('A'))<<": "<<t[i]<<endl;
	}
}
int main()
{
	int times[36]={0};
	//数组，规定100，是有大小，而char *ch，仅仅只是声明，没有分配空间
	char ch[100];
	int num;
	DSqString Dsq;

	ShuRu(ch);
	StrAssign_Sq(Dsq,ch);
	TongJi(Dsq,times);
	ShuChu(times);

	system("pause");
}