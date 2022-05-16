using namespace std;
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include<string.h>
typedef int ElemType;
#include"SqStack.h"

int main(){
    SqStack myStack;
    int a,x,y;
    char b;
     

    x=1;
    InitStack_Sq(myStack);

    while(x){
        cin>>a;
        if(a!=0)
            Push_Sq(myStack,a);
        else x=0;
    }
    while(myStack.top!=-1){
        Pop_Sq(myStack,y);
        cout<<y<<' ';
    }
}