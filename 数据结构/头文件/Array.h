#define MAX_ARRAY_DIM 8 // 假设数组维数的最大值为 8
#include "stdarg.h"
typedef struct
{
    ElemType *base; // 数组元素基址，由 InitArray()分配
    int dim;        // 数组维数
    int *b;         // 数组维界基址，由 InitArray()分配
    int *c;         // 数组映象函数常量基址，由 InitArray()分配
} Array;

bool InitArray(Array &A, int dim, ...)
{                                       // 若维数 dim 和各维长度合法，则构造相应的数组 A，并返回 true
    int elemtotal = 1, i;               // elemtotal 是数组元素总数，初值为 1(累乘器)
    va_list ap;                         // 变长参数表类型，是存放变长参数表信息的数组
    if (dim < 1 || dim > MAX_ARRAY_DIM) // 数组维数超出范围
        return false;
    A.dim = dim;                            // 数组维数
    A.b = (int *)malloc(dim * sizeof(int)); // 动态分配数组维界基址
    if (!A.b)
        exit(1);       // 存储分配失败
    va_start(ap, dim); // 变长参数“...”从形参 dim 之后开始
    for (i = 0; i < dim; ++i)
    {
        A.b[i] = va_arg(ap, int); // 逐一将变长参数赋给 A.b[i]
        if (A.b[i] < 0)
            return false;    // 长度不合法
        elemtotal *= A.b[i]; // 若各维长度合法，则存入数组 A.b 中，并求出 A 的元素总数
    }
    va_end(ap); // 结束提取变长参数
    A.base = (ElemType *)malloc(elemtotal * sizeof(ElemType));
    if (!A.base)
        exit(1);                            // 存储分配失败
    A.c = (int *)malloc(dim * sizeof(int)); // 动态分配数组偏移量基址
    if (!A.c)
        exit(1);      // 存储分配失败
    A.c[dim - 1] = 1; // 最后一维的偏移量为 1
                      // L=1,指针的增减以元素的大小为单位
    for (i = dim - 2; i >= 0; --i)
        A.c[i] = A.b[i + 1] * A.c[i + 1]; // 每一维的偏移量
    return true;
} // InitArray

bool Locate(Array A, va_list ap, int &off)
{ // 若 ap 指示的各下标值合法，则求出该元素在 A 中的相对地址 off
    int i, ind;
    off = 0;
    for (i = 0; i < A.dim; i++)
    {
        ind = va_arg(ap, int);        // 逐一读取各维的下标值
        if (ind < 0 || ind >= A.b[i]) // 各维的下标值不合法
            return false;
        off += A.c[i] * ind; // 相对地址=各维的下标值*本维的偏移量之和
    }
    return true;
} // Locate

bool Value(ElemType &e, Array A, ...)
{               // “...”依次为各维的下标值，若各下标合法，则 e 被赋值为 A 的相应的元素值
    va_list ap; // 变长参数表类型，在 stdarg.h 中
    int off;
    va_start(ap, A);         // 变长参数“...”从形参 A 之后开始
    if (!Locate(A, ap, off)) // 求得变长参数所指单元的相对地址 off
        return false;
    e = *(A.base + off); // 将变长参数所指单元的值赋给 e
    return true;
} // Value

bool Assign(Array A, ElemType e, ...)
{               // “...”依次为各维的下标值，若各下标合法，则将 e 的值赋给 A 的指定的元素
    va_list ap; // 变长参数表类型，在 stdarg.h 中
    int off;
    va_start(ap, e);         // 变长参数“...”从形参 e 之后开始
    if (!Locate(A, ap, off)) // 求得变长参数所指单元的相对地址 off
        return false;
    *(A.base + off) = e; // 将 e 的值赋给变长参数所指单元
    return true;
} // Assign

void DestroyArray(Array &A)
{                     // 撤销数组 A
    if (A.base)       // A.base 指向存储单元
        free(A.base); // 释放 A.base 所指向的存储单元
    if (A.b)
        free(A.b);
    if (A.c)
        free(A.c);
    A.base = A.b = A.c = NULL; // 使它们不再指向任何存储单元
    A.dim = 0;
} // DestroyArray