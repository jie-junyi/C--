#include "stdlib.h" // ���ļ�����malloc()��realloc()��free()�Ⱥ���
using namespace std;
#include <iomanip>
#include <iostream>	   // ���ļ�������׼���������cout��cin
#include "DSqString.h" // ���ļ��а�����̬˳�򴮵���ض��弰����
#include "string.h"
#include "stdio.h"

void get_next(DSqString T, int next[])
{
	int j = 1, k = 0;
	next[0] = -1;
	next[1] = 0;
	while (j < T.length)
	{
		if (T.str[j] == T.str[k])
		{
			next[j + 1] = k + 1;
			j++;
			k++;
		}
		else if (k == 0)
		{
			next[j + 1] = 0;
			j++;
		}
		else
			k = next[k];
	}
} // get_next

bool Index_KMP(DSqString S, DSqString T, int next[], int &pos)
{					  // ����ģʽ��T��next������T������S�е�λ��
	int i = 0, j = 0; // i��j�ֱ�ɨ������S���Ӵ�T
	while (i < S.length && j < T.length)
	{
		if (j == -1 || S.str[i] == T.str[j]) // �����Ƚ���һ���ַ�
		{
			i++;
			j++;
		}
		else
			j = next[j]; // ģʽ�������ƶ�
	}
	if (j == T.length)
	{
		pos = i - T.length;
		return true;
	}
	else
		return false;
} // Index_KMP

int main()
{
	int next[10], pos;
	DSqString S1, S2, S3;
	StrAssign_Sq(S1, "aild");	  // ��S1����ֵ
	StrAssign_Sq(S2, "children"); // ��S2����ֵ
	get_next(S1, next);
	if (Index_KMP(S2, S1, next, pos))
		cout << "ƥ��ɹ���pos=" << pos << endl;
	else
		cout << "ƥ��ʧ�ܣ�" << endl;
	StrAssign_Sq(S3, "ild"); // ��S3����ֵ
	get_next(S3, next);
	if (Index_KMP(S2, S3, next, pos))
		cout << "ƥ��ɹ���pos=" << pos << endl;
	else
		cout << "ƥ��ʧ�ܣ�" << endl;
	return 0;
}
