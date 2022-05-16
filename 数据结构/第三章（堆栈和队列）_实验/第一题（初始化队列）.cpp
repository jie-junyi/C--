/**
 * ѭ������д��
 * ʹ�ü�����������Ҫ��βָ��
 * ��ʼ��
 * ���ӡ�����
 * ȡ��ͷԪ�غ��ж϶����Ƿ�ǿ�
 *   �ɹ�������
 */
using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <cstdlib> // Header file �����
typedef int ElemType;
#define MaxQueueSize 100
typedef struct
{
    ElemType queue[MaxQueueSize]; //����ѭ������
    int front;                    // ��ͷָ��
    int count;                    // ������
} QueueType;

void InitQueue_Sq(QueueType &Q)
{ // ����һ����˳��ѭ������
    Q.front = 0;
    Q.count = 0;
}
bool EnQueue_Sq(QueueType &Q, ElemType e)
{ //�ж϶���
    if (Q.count == Q.front && Q.count != 0)
        return false;

    Q.queue[Q.count] = e;
    Q.count = (Q.count + 1) % 100;
    return true;
} // EnQueue_Sq

bool DeQueue_Sq(QueueType &Q, ElemType &e)
{
    //�ж϶ӿ�
    if (Q.count == Q.front && Q.count == 0)
        return false;

    e = Q.queue[Q.front];
    Q.front = (Q.front + 1) % 100;
    return true;
}
bool GetHead_Sq(QueueType Q, ElemType &e)
{
     if (Q.count == Q.front && Q.count == 0)
        return false;
    e = Q.queue[Q.front];
    return true;
} // GetHead_Sq

bool QueueEmpty_Sq(QueueType &Q)
{ // �ӿշ��� true���������� false
    return  (Q.count == Q.front && Q.count == 0);
} // QueueEmpty_Sq

int main(){
    QueueType Q;
    InitQueue_Sq(Q);
    srand(3);
    for(int i=0;i<6;i++){
        cout<<rand()<<" ";
    }
    srand(3);
    for(int i=0;i<1;i++){
        EnQueue_Sq(Q,rand());
    }
    int x=0;
    GetHead_Sq(Q,x);
    cout<<x<<endl;
}