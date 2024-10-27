#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 100//定义栈的最大容量；

//声明栈结构体：
typedef struct SqStack{
    int datas[MAXSIZE];
    int topindex;
}SqStack;

//1.初始化栈，将栈顶index定义为-1：
void InitStack(SqStack* stack){
    stack->topindex = -1;
}

//2.栈状态判断：
bool IsEmpty(SqStack* stack){
    return stack->topindex == -1;
}
bool IsFull(SqStack* stack){
    return stack->topindex == MAXSIZE-1;
}

//3.压栈push:
bool Push(SqStack* stack,int data){
    if(IsFull(stack)){
        printf("栈满\n");
        return false;
    }else{
        stack->datas[++(stack->topindex)] = data;
        return true;
    }
}

//4.出栈pop：
bool Pop(SqStack* stack,int* poppedelem){
    if(IsEmpty(stack)){
        printf("栈空\n");
        return false;
    }else{
        *poppedelem = stack->datas[(stack->topindex)--];
        return true;
    }
}

//5.获取栈顶元素:
bool GetTop(SqStack* stack,int* topelempointer){
    if(IsEmpty(stack)){
        printf("栈空\n");
        return false;
    }else{
        *topelempointer = stack->datas[stack->topindex];
        return true;
    }
}

//test main函数:
int main(){
    SqStack stack;
    InitStack(&stack);
    for(int i=0;i<10;i++){
        Push(&stack,i);
    }

    int topelem;
    GetTop(&stack,&topelem);
    printf("Top element is %d\n",topelem);
    int elem;
    while(!IsEmpty(&stack)){
        if(!Pop(&stack,&elem));
        printf("Popped elem is %d\n",elem);
    }
    return 0;
}