using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string.h>
typedef char ElemType;
#include"SqStack.h"

void kuo_hao(char a[], int n)
{
	SqStack myStack;
	int i;
	char c;

	InitStack_Sq(myStack);

	for (i = 0; i < n; i++)
	{
		if ((a[i] == '(') || (a[i] == '[') || (a[i] == '{'))
			Push_Sq(myStack, a[i]);

		else if (a[i] == ')' && !StackEmpty_Sq(myStack) && GetTop_Sq(myStack, c) && c == '(')
			Pop_Sq(myStack, c);
		else if (a[i] == ')' && !StackEmpty_Sq(myStack) && GetTop_Sq(myStack, c) && c != '(')
		{
			printf("左右括号配对次序不正确!\n");
			return;
		}
		else if (a[i] == ']' && !StackEmpty_Sq(myStack) && GetTop_Sq(myStack, c) && c == '[')
			Pop_Sq(myStack, c);
		else if (a[i] == ']' && !StackEmpty_Sq(myStack) && GetTop_Sq(myStack, c) && c != '[')
		{
			printf("左右括号配对次序不正确!\n");
			return;
		}
		else if (a[i] == '}' && !StackEmpty_Sq(myStack) && GetTop_Sq(myStack, c) && c == '{')
			Pop_Sq(myStack, c);
		else if (a[i] == '}' && !StackEmpty_Sq(myStack) && GetTop_Sq(myStack, c) && c != '{')
		{
			printf("左右括号配对次序不正确!\n");
			return;
		}
		else if (((a[i] == ')') || (a[i] == ']') || (a[i] == '}')) && StackEmpty_Sq(myStack))
		{
			printf("右括号多于左括号!\n");
			return;
		}
	}

	if (!StackEmpty_Sq(myStack))
		printf("左括号多于右括号!\n");
	else
		printf("左右括号匹配正确!\n");
}
int main()
{
	char b[10];
	char c='1';
	int i=0;
	while(c!='0'){
		cin>>c;
		b[i]=c;
		i++;
	}

	kuo_hao(b,i);
	
	return 0;
}

