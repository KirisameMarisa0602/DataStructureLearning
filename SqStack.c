#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 100//����ջ�����������

//����ջ�ṹ�壺
typedef struct SqStack{
    int datas[MAXSIZE];
    int topindex;
}SqStack;

//1.��ʼ��ջ����ջ��index����Ϊ-1��
void InitStack(SqStack* stack){
    stack->topindex = -1;
}

//2.ջ״̬�жϣ�
bool IsEmpty(SqStack* stack){
    return stack->topindex == -1;
}
bool IsFull(SqStack* stack){
    return stack->topindex == MAXSIZE-1;
}

//3.ѹջpush:
bool Push(SqStack* stack,int data){
    if(IsFull(stack)){
        printf("ջ��\n");
        return false;
    }else{
        stack->datas[++(stack->topindex)] = data;
        return true;
    }
}

//4.��ջpop��
bool Pop(SqStack* stack,int* poppedelem){
    if(IsEmpty(stack)){
        printf("ջ��\n");
        return false;
    }else{
        *poppedelem = stack->datas[(stack->topindex)--];
        return true;
    }
}

//5.��ȡջ��Ԫ��:
bool GetTop(SqStack* stack,int* topelempointer){
    if(IsEmpty(stack)){
        printf("ջ��\n");
        return false;
    }else{
        *topelempointer = stack->datas[stack->topindex];
        return true;
    }
}

//test main����:
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