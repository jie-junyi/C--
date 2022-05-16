/**
 *  ①排队──输入排队病人的病历号，加入到病人排队队列中；
    ②就诊──病人排队队列中最前面的病人就诊，并将其从候诊队列中删除；
    ③查看排队──从队首到队尾列出所有的排队病人的病历号；
    ④下班──退出运行。
 */
#define QUEUE_INIT_SIZE 100 // 顺序循环队列(默认的)的初始分配最大容量
#define QUEUEINCREMENT 10   // (默认的)增补空间量
using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
typedef int ElemType;

typedef struct
{
    ElemType *queue;   // 存储数据元素的一维数组
    int front;         // 队首指针，指向队首元素
    int rear;          // 队尾指针，指向队尾元素的下一个位置
    int queuesize;     // 顺序循环队列当前的最大容量
    int incrementsize; // 增补空间量
} SqQueue;

void InitQueue_Sq(SqQueue &Q, int maxsize = QUEUE_INIT_SIZE,
                  int incresize = QUEUEINCREMENT)
{ // 构造一个空顺序循环队列
    Q.queue = (ElemType *)malloc(maxsize * sizeof(ElemType));
    if (!Q.queue)
        exit(1);
    Q.front = Q.rear = 0;
    Q.queuesize = maxsize;
    Q.incrementsize = incresize;
} // InitQueue_Sq

bool EnQueue_Sq(SqQueue &Q, ElemType e)
{                                              // 插入元素 e 到队尾，成功插入返回 true，否则返回 false
    if ((Q.rear + 1) % Q.queuesize == Q.front) // 队满，给顺序循环队列增补空间
    {
        Q.queue = (ElemType *)realloc(Q.queue,
                                      (Q.queuesize + Q.incrementsize) * sizeof(ElemType));
        if (!Q.queue)
            return false;
        if (Q.front > Q.rear) // 队尾指针在队首指针前面，重新确定队首指针的位置
        {
            for (int i = Q.queuesize - 1; i >= Q.front; i--)
                // 将 Q.front 到 queuesize-1 之间的元素后移 Q.incrementsize 个位置
                Q.queue[i + Q.incrementsize] = Q.queue[i];
            Q.front += Q.incrementsize; // 队首指针后移 Q.incrementsize 个位置
        }
        Q.queuesize += Q.incrementsize; // 队列容量增加 Q.incrementsize
    }
    Q.queue[Q.rear] = e;                 // 元素 e 插入到队尾
    Q.rear = (Q.rear + 1) % Q.queuesize; // 队尾指针顺时针移动一个位置
    return true;
} // EnQueue_Sq

bool DeQueue_Sq(SqQueue &Q, ElemType &e)

{ // 就诊，并用 e 返回其值，成功删除返回 true；否则返回 false
    if (Q.front == Q.rear)
        return false;                      // 队空
    e = Q.queue[Q.front];                  // 取出队首元素
    Q.front = (Q.front + 1) % Q.queuesize; // 队首指针顺时针移动一个位置
    return true;
}

bool GetHead_Sq(SqQueue Q, ElemType &e)
{
    if (Q.front == Q.rear)
        return false; // 队空
    e = Q.queue[Q.front];
    return true;
} // GetHead_Sq
int main(){
    SqQueue Q;
    InitQueue_Sq(Q);

    while(1){
        int x;
        cout<<"1:排队\n"<<"2:就诊\n"<<"3:查看排队\n"<<"4:退出\n";
        cin>>x;
        if(x==4){
            return 0;
        }
        switch (x)
        {
        case 1:
            cout<<"请输入你的病号\n";
            int a;
            cin>>a;
            EnQueue_Sq(Q,a);
            break;
        case 2:
            int b;
            DeQueue_Sq(Q,b);
            cout<<b<<"已就诊"<<endl;
            break;
        case 3:
            int c;
            GetHead_Sq(Q,c);
            cout<<"就诊最近的病人为："<< c<<endl;
            break;
        default:
            break;
        }    
    }

    return 0;
}