typedef struct LNode
{
	char str; // һ�������һ���ַ�
	struct LNode *next;
} SNode, *SLinkString;

//��ʼ��
void StrAssign_L(SLinkString &S, char *chars)
{ // ���ַ���chars��ֵ����ʽ��S
	SLinkString p, q;
	S = (SLinkString)malloc(sizeof(LNode)); // ������Sͷ���
	if (!(*chars))
		S->next = NULL; // ��S�ÿ�
	else
	{
		p = S; // pʼ��ָ��β���
		while (*chars)
		{
			q = (SLinkString)malloc(sizeof(LNode)); // �����½��
			q->str = *chars;						// ��Ԫ��ֵ
			p->next = q;							// ������β���֮��
			p = q;									// pָ���µı�β
			chars++;
		}
		q->next = NULL;
	}
}

//����
void StrCopy_L(SLinkString &S, SLinkString T)
{ // ����ʽ��T���Ƶ���һ����ʽ��S�У������ظ��ƺ����ʽ��S
	SLinkString p, q, r;
	while (S->next) // �ͷŴ�Sԭ�пռ䣬����ͷ���
	{
		p = S;
		S = S->next;
		free(p);
	}
	r = T->next; // rָ��T�ĵ�һ�����
	p = S;		 // pָ��Sβ���
	while (r)	 // ���ƴ�T�����н��
	{
		q = (SLinkString)malloc(sizeof(LNode)); // qָ���´����Ľ��
		q->str = r->str;
		p->next = q;
		p = q;
		r = r->next; // rָ��T����һ�����
	}
	p->next = NULL;
}

//�󳤶�
int StrLength_L(SLinkString S)
{
	int n = 0;
	SLinkString p = S->next;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}

//�Ƚϴ�С
int StrCompare_L(SLinkString S, SLinkString T)
{										  // �Ƚ���ʽ��S����ʽ��T�Ĵ�С
	SLinkString p = S->next, q = T->next; // p��q�ֱ�ָ��S�ʹ�T�ĵ�һ�����
	while (p && q)						  // ��Ӧ�ַ����бȽ�
	{
		if (p->str > q->str)
			return 1;
		else if (p->str < q->str)
			return -1;
		p = p->next; // pָ����һ�����
		q = q->next; // pָ����һ�����
	}
	if (p)
		return 1;
	else if (q)
		return -1;
	return 0;
}

//����
void StrConcat_L(SLinkString &S, SLinkString T)
{											 // ����ʽ��T��������ʽ��S֮�󣬲��������Ӻ����ʽ��S
	SLinkString p = S->next, q, r = T->next; // p��r�ֱ�ָ��S�ʹ�T�ĵ�1�����
	while (p)								 // qָ��S��β���
	{
		q = p;
		p = p->next;
	}
	while (r) // ���ƴ�T�����н��
	{
		p = (SLinkString)malloc(sizeof(LNode)); // pָ���½��
		p->str = r->str;
		q->next = p;
		q = p;
		r = r->next;
	}
	q->next = NULL;
}

//ȡ�Ӵ�
bool SubString_L(SLinkString S, SLinkString &Sub, int pos, int len)
{ // ����ʽ��S�дӵ�pos��λ�ÿ�ʼ��ȡ����Ϊlen���Ӵ�Sub��������Sub��ֵ
	SLinkString p, q, r;
	int i;
	if (len < 0 || len > StrLength_L(S) - pos + 1)
		return false; // len��ֵ������
	p = S->next;
	i = 1;					   // pָ��S�ĵ�1�����
	while (p->next && i < pos) // Ѱ�ҵ�pos�����,����pָ��˽��
	{
		p = p->next;
		i++;
	}
	if (i != pos)
		return false; // pos��λ�ò�����
	while (Sub->next) // �ͷŴ�Subԭ�пռ䣬����ͷ���
	{
		q = Sub;
		Sub = Sub->next;
		free(q);
	}
	r = Sub;				   // rָ���Ӵ�Subͷ���
	for (i = 1; i <= len; i++) // �����Ӵ�Sub
	{
		q = (SLinkString)malloc(sizeof(LNode));
		q->str = p->str;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return true;
}

//ģʽƥ��
bool Index_L(SLinkString S, SLinkString T, int i, int &pos)
{ // ������S�д�λ��i�����Ƿ�����Ӵ�T�������ڣ�����pos������λ��
	SLinkString Sub;
	char *a;
	StrAssign_L(Sub, a); // �ÿմ�
	for (; i < StrLength_L(S) - StrLength_L(T) + 1; i++)
	{
		SubString_L(S, Sub, i, StrLength_L(T)); // ���±�i��ʼȡ����ΪStrLength_L(T)���Ӵ�
		if (!StrCompare_L(Sub, T))				// �Ƚ��Ӵ�Sub��T
		{
			pos = i;
			return true;
		}
	}
	return false;
}

//����
bool StrInsert_L(SLinkString &S, int pos, SLinkString T)
{ // ����ʽ��S�ĵ�pos���ַ�֮ǰ�����Ӵ�T�������ز�������ʽ��S
	SLinkString p, q, r, h;
	int i = 0;
	p = S;						   // pָ��S��ͷ���
	while (p->next && i < pos - 1) // Ѱ�ҵ�pos-1�����,����pָ��˽��
	{
		p = p->next;
		i++;
	}
	q = p->next; // qָ���pos�����
	if (i != pos - 1)
		return false; // pos��λ�ò�����
	r = T->next;	  // rָ��T�ĵ�һ�����
	while (r)		  // ���ƴ�T�����н��
	{
		h = (LNode *)malloc(sizeof(LNode)); // hָ���½��
		h->str = r->str;
		p->next = h;
		h->next = q; // ���r���뵽���p�ͽ��q֮��
		p = h;
		r = r->next; // p��r�ֱ�ָ��S�ʹ�T����һ�����
	}
	return true;
}

//ɾ��
bool StrDelete_L(SLinkString &S, int pos, int len)
{							 // ����ʽ��S�ĵ�pos���ַ��ַ���ʼɾ������Ϊlen���Ӵ���������ɾ�������ʽ��S
	SLinkString p = S, q, r; // pָ��Sͷ���
	int i = 0;
	if (len < 0 || len > StrLength_L(S) - pos + 1)
		return false;								// len��ֵ������
	while (p->next && p->next->next && i < pos - 1) //Ѱ�ҵ�pos-1�����,����pָ��˽��
	{
		p = p->next;
		i++;
	}
	if (i != pos - 1)
		return false;		   // pos��λ�ò�����
	q = p->next;			   // qָ���pos�����
	for (i = 1; i <= len; i++) // �Ӵ�S��q��ָ��㿪ʼɾ��len�����
	{
		r = q;
		p->next = q->next;
		q = q->next;
		free(r);
	}
	return true;
}

//�滻
void StrReplace_L(SLinkString &S, SLinkString T, SLinkString V)
{ // �ô�V�û�����S�г��ֵ�������T��ȵĲ��ص��Ӵ����������û���Ĵ�S
	int i = 1, pos;
	while (Index_L(S, T, i, pos)) // �ж�T�Ƿ�S���Ӵ�
	{
		StrDelete_L(S, pos, StrLength_L(T)); // ɾ���Ӵ�T
		StrInsert_L(S, pos, V);				 // �����Ӵ�V
		i = pos + StrLength_L(V);			 // ���û����λ�ÿ�ʼ
	}
}
//����
void StrTraveres_L(SLinkString S)
{
	SLinkString p = S->next;
	while (p)
	{
		cout << p->str;
		p = p->next;
	}
	cout << endl;
}

//����
void DestroyString_L(SLinkString &S)
{
	SLinkString p, p1;
	p = S;
	while (p)
	{
		p1 = p;
		p = p->next;
		free(p1); // �ͷ�p1��ָ��Ŀռ�
	}
	S = NULL; // S�ÿ�
}
