#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct LinkStackNode{
    int data;
    struct LinkStackNode* next;
}Node,*LinkStack;

//1.��ʼ����
LinkStack InitStack(){
    return NULL;
}

//2.�ж�ջ״̬��(ֻ�пգ�û����)
bool IsEmpty(LinkStack stack){
    return stack  == NULL;
}

//3.ѹջpush��
bool Push(LinkStack* stacktop,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("�����ڴ�ʧ��\n");
        return false;
    }else{
        newNode->data = data;
        newNode->next = *stacktop;
        *stacktop = newNode;
        return true;
    }
}

//4.��ջpop:
bool Pop(LinkStack* stacktop,int* elempointer){
    if(IsEmpty(*stacktop)){
        printf("ջ��\n");
        return false;
    }else{
        Node* temp = *stacktop;
        *elempointer = temp->data;
        *stacktop = temp->next;
        free(temp);
        return true;
    }
}

//5.��ȡջ��Ԫ�أ�
bool GetTop(LinkStack stack,int* topelem){
    if(IsEmpty(stack)){
        printf("ջΪ��\n");
        return false;
    }else{
        *topelem = stack->data;
        return true;
    }
}

//test main������
int main(){
    LinkStack stack = InitStack();
    for(int i=0;i<10;i++){
        Push(&stack,i);
    }

    int top;
    GetTop(stack,&top);
    printf("top element is:%d\n",top);
    return 0;
}