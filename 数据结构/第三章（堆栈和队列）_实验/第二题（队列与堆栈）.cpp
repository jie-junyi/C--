/**
 * Q是一个非空队列，S是一个空栈。
 * 编写算法实现：将队列Q中的所有元素逆置。
 * 
 */
using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>

#include "SqStack.h"
#include "SqQueue.h"
typedef int ElemType;

bool NiXu(SqQueue &Q,SqStack &S){

    while(Q.front!=Q.rear){
        int x;
        DeQueue_Sq(Q,x);
        Push_Sq(S,x);
    }
    while(S.top!=-1){
        int x;
        Pop_Sq(S,x);
        EnQueue_Sq(Q,x);
    }
    return true;
}

int main(){
    SqQueue Q;
    SqStack S;

    InitQueue_Sq(Q,30,10);
    InitStack_Sq(S,30,10);

    EnQueue_Sq(Q,10);
    EnQueue_Sq(Q,20);
    EnQueue_Sq(Q,30);
    EnQueue_Sq(Q,44);
    EnQueue_Sq(Q,55);
    int x;
    GetHead_Sq(Q,x);
    cout<<x<<endl;
    
    NiXu(Q,S);
    GetHead_Sq(Q,x);
    cout<<x<<endl;
    return 0;
}






