typedef struct LNode
{
	char str; // 一个结点存放一个字符
	struct LNode *next;
} SNode, *SLinkString;

//初始化
void StrAssign_L(SLinkString &S, char *chars)
{ // 将字符串chars赋值给链式串S
	SLinkString p, q;
	S = (SLinkString)malloc(sizeof(LNode)); // 建立串S头结点
	if (!(*chars))
		S->next = NULL; // 串S置空
	else
	{
		p = S; // p始终指向尾结点
		while (*chars)
		{
			q = (SLinkString)malloc(sizeof(LNode)); // 创建新结点
			q->str = *chars;						// 赋元素值
			p->next = q;							// 插入在尾结点之后
			p = q;									// p指向新的表尾
			chars++;
		}
		q->next = NULL;
	}
}

//复制
void StrCopy_L(SLinkString &S, SLinkString T)
{ // 将链式串T复制到另一个链式串S中，并返回复制后的链式串S
	SLinkString p, q, r;
	while (S->next) // 释放串S原有空间，保留头结点
	{
		p = S;
		S = S->next;
		free(p);
	}
	r = T->next; // r指向串T的第一个结点
	p = S;		 // p指向串S尾结点
	while (r)	 // 复制串T的所有结点
	{
		q = (SLinkString)malloc(sizeof(LNode)); // q指向新创建的结点
		q->str = r->str;
		p->next = q;
		p = q;
		r = r->next; // r指向串T的下一个结点
	}
	p->next = NULL;
}

//求长度
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

//比较大小
int StrCompare_L(SLinkString S, SLinkString T)
{										  // 比较链式串S和链式串T的大小
	SLinkString p = S->next, q = T->next; // p、q分别指向串S和串T的第一个结点
	while (p && q)						  // 对应字符进行比较
	{
		if (p->str > q->str)
			return 1;
		else if (p->str < q->str)
			return -1;
		p = p->next; // p指向下一个结点
		q = q->next; // p指向下一个结点
	}
	if (p)
		return 1;
	else if (q)
		return -1;
	return 0;
}

//连接
void StrConcat_L(SLinkString &S, SLinkString T)
{											 // 将链式串T连接在链式串S之后，并返回连接后的链式串S
	SLinkString p = S->next, q, r = T->next; // p、r分别指向串S和串T的第1个结点
	while (p)								 // q指向串S的尾结点
	{
		q = p;
		p = p->next;
	}
	while (r) // 复制串T中所有结点
	{
		p = (SLinkString)malloc(sizeof(LNode)); // p指向新结点
		p->str = r->str;
		q->next = p;
		q = p;
		r = r->next;
	}
	q->next = NULL;
}

//取子串
bool SubString_L(SLinkString S, SLinkString &Sub, int pos, int len)
{ // 在链式串S中从第pos个位置开始，取长度为len的子串Sub，并返回Sub的值
	SLinkString p, q, r;
	int i;
	if (len < 0 || len > StrLength_L(S) - pos + 1)
		return false; // len的值不合理
	p = S->next;
	i = 1;					   // p指向串S的第1个结点
	while (p->next && i < pos) // 寻找第pos个结点,并让p指向此结点
	{
		p = p->next;
		i++;
	}
	if (i != pos)
		return false; // pos的位置不合理
	while (Sub->next) // 释放串Sub原有空间，保留头结点
	{
		q = Sub;
		Sub = Sub->next;
		free(q);
	}
	r = Sub;				   // r指向子串Sub头结点
	for (i = 1; i <= len; i++) // 建立子串Sub
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

//模式匹配
bool Index_L(SLinkString S, SLinkString T, int i, int &pos)
{ // 在主串S中从位置i查找是否存在子串T，若存在，则由pos返回其位置
	SLinkString Sub;
	char *a;
	StrAssign_L(Sub, a); // 置空串
	for (; i < StrLength_L(S) - StrLength_L(T) + 1; i++)
	{
		SubString_L(S, Sub, i, StrLength_L(T)); // 从下标i开始取长度为StrLength_L(T)的子串
		if (!StrCompare_L(Sub, T))				// 比较子串Sub和T
		{
			pos = i;
			return true;
		}
	}
	return false;
}

//插入
bool StrInsert_L(SLinkString &S, int pos, SLinkString T)
{ // 在链式串S的第pos个字符之前插入子串T，并返回插入后的链式串S
	SLinkString p, q, r, h;
	int i = 0;
	p = S;						   // p指向串S的头结点
	while (p->next && i < pos - 1) // 寻找第pos-1个结点,并让p指向此结点
	{
		p = p->next;
		i++;
	}
	q = p->next; // q指向第pos个结点
	if (i != pos - 1)
		return false; // pos的位置不合理
	r = T->next;	  // r指向串T的第一个结点
	while (r)		  // 复制串T中所有结点
	{
		h = (LNode *)malloc(sizeof(LNode)); // h指向新结点
		h->str = r->str;
		p->next = h;
		h->next = q; // 结点r插入到结点p和结点q之间
		p = h;
		r = r->next; // p、r分别指向串S和串T的下一个结点
	}
	return true;
}

//删除
bool StrDelete_L(SLinkString &S, int pos, int len)
{							 // 从链式串S的第pos个字符字符开始删除长度为len的子串，并返回删除后的链式串S
	SLinkString p = S, q, r; // p指向串S头结点
	int i = 0;
	if (len < 0 || len > StrLength_L(S) - pos + 1)
		return false;								// len的值不合理
	while (p->next && p->next->next && i < pos - 1) //寻找第pos-1个结点,并让p指向此结点
	{
		p = p->next;
		i++;
	}
	if (i != pos - 1)
		return false;		   // pos的位置不合理
	q = p->next;			   // q指向第pos个结点
	for (i = 1; i <= len; i++) // 从串S中q所指结点开始删除len个结点
	{
		r = q;
		p->next = q->next;
		q = q->next;
		free(r);
	}
	return true;
}

//替换
void StrReplace_L(SLinkString &S, SLinkString T, SLinkString V)
{ // 用串V置换主串S中出现的所有与T相等的不重叠子串，并返回置换后的串S
	int i = 1, pos;
	while (Index_L(S, T, i, pos)) // 判断T是否S的子串
	{
		StrDelete_L(S, pos, StrLength_L(T)); // 删除子串T
		StrInsert_L(S, pos, V);				 // 插入子串V
		i = pos + StrLength_L(V);			 // 从置换后的位置开始
	}
}
//遍历
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

//销毁
void DestroyString_L(SLinkString &S)
{
	SLinkString p, p1;
	p = S;
	while (p)
	{
		p1 = p;
		p = p->next;
		free(p1); // 释放p1所指向的空间
	}
	S = NULL; // S置空
}
