#include "stdlib.h" // ���ļ�����malloc()��realloc()��free()�Ⱥ���
using namespace std;
#include <iomanip>
#include <iostream>		 // ���ļ�������׼���������cout��cin
#include "SLinkString.h" // ���ļ��а�����ʽ������ض��弰����

int main()
{
	SLinkString S1, S2, S3, S4;
	StrAssign_L(S1, "child");					  // ��S1����ֵ
	StrAssign_L(S2, "children");				  // ��S2����ֵ
	StrAssign_L(S3, "chinese chair technology "); // ��S3����ֵ
	StrAssign_L(S4, "");						  // ��S4�ÿ�
	StrCopy_L(S4, S1);							  // ����S1���Ƶ���S4��
	cout << "��S4�����ƺ��ֵΪ��";
	StrTraveres_L(S4); // �����S4��ֵ
	if (StrCompare_L(S1, S2) > 0)
		cout << "��S1>��S2" << endl; // ��S1�봮S2�Ƚ�
	else if (StrCompare_L(S1, S2) == 0)
		cout << "��S1=��S2" << endl;
	else
		cout << "��S1<��S2" << endl;
	StrConcat_L(S3, S4); // ��S4�����ڴ�S3֮��
	cout << "��S3��S4���Ӻ��ֵΪ��";
	StrTraveres_L(S3);
	if (SubString_L(S3, S4, 9, 5)) // �Ӵ�S3�ĵ�9���ַ���ʼȡ����Ϊ5���Ӵ�
	{
		cout << "ȡ�Ӵ��ɹ���";
		cout << "��ȡ�õ��Ӵ�S4��ֵΪ��";
		StrTraveres_L(S4);
	}
	else
		cout << "ȡ�Ӵ�ʧ�ܣ�" << endl;
	StrAssign_L(S1, "ch");	 // ��S1���±���ֵ
	StrAssign_L(S2, "abcd"); // ��S2���±���ֵ
	cout << "�û�ǰ��S3��ֵΪ��";
	StrTraveres_L(S3);
	StrReplace_L(S3, S1, S2); // �Ѵ�S3�е��Ӵ�S1�û�Ϊ��S2
	cout << "�û���S3��ֵΪ��";
	StrTraveres_L(S3);
	DestroyString_L(S1);
	DestroyString_L(S2);
	DestroyString_L(S3);
	DestroyString_L(S4);
	return 0;
}
