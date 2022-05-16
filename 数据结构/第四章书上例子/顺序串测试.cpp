#include "stdlib.h" // ���ļ�����malloc()��realloc()��free()�Ⱥ���
using namespace std;
#include <iomanip>
#include <iostream>	   // ���ļ�������׼���������cout��cin
#include "DSqString.h" // ���ļ�������̬˳�򴮵���ض��弰����

int main()
{
	DSqString S1, S2, S3, S4;
	StrAssign_Sq(S1, "child");					   // ��S1����ֵ
	StrAssign_Sq(S2, "children");				   // ��S2����ֵ
	StrAssign_Sq(S3, "chinese chair technology "); // ��S3����ֵ
	StrAssign_Sq(S4, "");
	StrCopy_Sq(S4, S1); // ����S1���Ƶ���S4��
	cout << "��S4�����ƺ��ֵΪ��";
	StrTraveres_Sq(S4); // �����S4��ֵ
	if (StrCompare_Sq(S1, S2) > 0)
		cout << "��S1>��S2" << endl; // ��S1�봮S2�Ƚ�
	else if (StrCompare_Sq(S1, S2) == 0)
		cout << "��S1=��S2" << endl;
	else
		cout << "��S1<��S2" << endl;
	if (StrConcat_Sq(S3, S4)) // ��S4�����ڴ�S3֮��
	{
		cout << "��S3�봮S4���ӳɹ���" << endl;
		cout << "��S3��S4���Ӻ��ֵΪ��";
		StrTraveres_Sq(S3);
	}
	else
		cout << "������ʧ�ܣ�" << endl;
	if (SubString_Sq(S3, S4, 8, 5)) // �Ӵ�S3�ĵ�8���ַ���ʼȡ����Ϊ5���Ӵ�
	{
		cout << "ȡ�Ӵ��ɹ���";
		cout << "��ȡ�õ��Ӵ�S4��ֵΪ��";
		StrTraveres_Sq(S4);
	}
	else
		cout << "ȡ�Ӵ�ʧ�ܣ�" << endl;
	StrAssign_Sq(S1, "ch");	  // ��S1���±���ֵ
	StrAssign_Sq(S2, "abcd"); // ��S2���±���ֵ
	cout << "�û�ǰ��S3��ֵΪ��";
	StrTraveres_Sq(S3);
	StrReplace_Sq(S3, S1, S2); // �Ѵ�S3�е��Ӵ�S1�û�Ϊ��S2
	cout << "�û���S3��ֵΪ��";
	StrTraveres_Sq(S3);
	DestroyString_Sq(S1);
	DestroyString_Sq(S2);
	DestroyString_Sq(S3);
	DestroyString_Sq(S4);
	return 0;
}
