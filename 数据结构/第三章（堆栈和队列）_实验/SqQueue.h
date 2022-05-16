#define QUEUE_INIT_SIZE 100 // ˳��ѭ������(Ĭ�ϵ�)�ĳ�ʼ�����������
#define QUEUEINCREMENT 10   // (Ĭ�ϵ�)�����ռ���
using namespace std;
#include <stdlib.h>
#include <iomanip>
#include <iostream>
typedef struct
{
    ElemType *queue;   // �洢����Ԫ�ص�һά����
    int front;         // ����ָ�룬ָ�����Ԫ��
    int rear;          // ��βָ�룬ָ���βԪ�ص���һ��λ��
    int queuesize;     // ˳��ѭ�����е�ǰ���������
    int incrementsize; // �����ռ���
} SqQueue;

void InitQueue_Sq(SqQueue &Q, int maxsize = QUEUE_INIT_SIZE,
                  int incresize = QUEUEINCREMENT)
{ // ����һ����˳��ѭ������
    Q.queue = (ElemType *)malloc(maxsize * sizeof(ElemType));
    if (!Q.queue)
        exit(1);
    Q.front = Q.rear = 0;
    Q.queuesize = maxsize;
    Q.incrementsize = incresize;
} // InitQueue_Sq

bool EnQueue_Sq(SqQueue &Q, ElemType e)
{                                              // ����Ԫ�� e ����β���ɹ����뷵�� true�����򷵻� false
    if ((Q.rear + 1) % Q.queuesize == Q.front) // ��������˳��ѭ�����������ռ�
    {
        Q.queue = (ElemType *)realloc(Q.queue,
                                      (Q.queuesize + Q.incrementsize) * sizeof(ElemType));
        if (!Q.queue)
            return false;
        if (Q.front > Q.rear) // ��βָ���ڶ���ָ��ǰ�棬����ȷ������ָ���λ��
        {
            for (int i = Q.queuesize - 1; i >= Q.front; i--)
                // �� Q.front �� queuesize-1 ֮���Ԫ�غ��� Q.incrementsize ��λ��
                Q.queue[i + Q.incrementsize] = Q.queue[i];
            Q.front += Q.incrementsize; // ����ָ����� Q.incrementsize ��λ��
        }
        Q.queuesize += Q.incrementsize; // ������������ Q.incrementsize
    }
    Q.queue[Q.rear] = e;                 // Ԫ�� e ���뵽��β
    Q.rear = (Q.rear + 1) % Q.queuesize; // ��βָ��˳ʱ���ƶ�һ��λ��
    return true;
} // EnQueue_Sq

bool DeQueue_Sq(SqQueue &Q, ElemType &e)
{ // ɾ����βԪ�أ����� e ������ֵ���ɹ�ɾ������ true�����򷵻� false
    if (Q.front == Q.rear)
        return false;                      // �ӿ�
    e = Q.queue[Q.front];                  // ȡ������Ԫ��
    Q.front = (Q.front + 1) % Q.queuesize; // ����ָ��˳ʱ���ƶ�һ��λ��
    return true;
} // DeQueue_Sq
bool GetHead_Sq(SqQueue Q, ElemType &e)
{
    if (Q.front == Q.rear)
        return false; // �ӿ�
    e = Q.queue[Q.front];
    return true;
} // GetHead_Sq

bool QueueEmpty_Sq(SqQueue Q)
{ // �ӿշ��� true���������� false
    return Q.rear == Q.front;
} // QueueEmpty_Sq

void DestroyQueue_Sq(SqQueue &Q)
{
    free(Q.queue);
    Q.queue = NULL;
    Q.queuesize = 0;
    Q.front = Q.rear = 0;
} // DestroyQueue_Sq