/**
 * 循环队列写法
 * 使用计数器，不需要队尾指针
 * 初始化
 * 进队、出队
 * 取队头元素和判断队列是否非空
 *   成功！！！
 */
using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <cstdlib> // Header file 随机数
typedef int ElemType;
#define MaxQueueSize 100
typedef struct
{
    ElemType queue[MaxQueueSize]; //队列循环数组
    int front;                    // 队头指针
    int count;                    // 计数器
} QueueType;

void InitQueue_Sq(QueueType &Q)
{ // 构造一个空顺序循环队列
    Q.front = 0;
    Q.count = 0;
}
bool EnQueue_Sq(QueueType &Q, ElemType e)
{ //判断队满
    if (Q.count == Q.front && Q.count != 0)
        return false;

    Q.queue[Q.count] = e;
    Q.count = (Q.count + 1) % 100;
    return true;
} // EnQueue_Sq

bool DeQueue_Sq(QueueType &Q, ElemType &e)
{
    //判断队空
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
{ // 队空返回 true，队满返回 false
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