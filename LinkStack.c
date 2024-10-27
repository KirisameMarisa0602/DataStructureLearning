#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct LinkStackNode{
    int data;
    struct LinkStackNode* next;
}Node,*LinkStack;

//1.³õÊ¼»¯£º
LinkStack InitStack(){
    return NULL;
}

//2.ÅÐ¶ÏÕ»×´Ì¬£º(Ö»ÓÐ¿Õ£¬Ã»ÓÐÂú)
bool IsEmpty(LinkStack stack){
    return stack  == NULL;
}

//3.Ñ¹Õ»push£º
bool Push(LinkStack* stacktop,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("·ÖÅäÄÚ´æÊ§°Ü\n");
        return false;
    }else{
        newNode->data = data;
        newNode->next = *stacktop;
        *stacktop = newNode;
        return true;
    }
}

//4.³öÕ»pop:
bool Pop(LinkStack* stacktop,int* elempointer){
    if(IsEmpty(*stacktop)){
        printf("Õ»¿Õ\n");
        return false;
    }else{
        Node* temp = *stacktop;
        *elempointer = temp->data;
        *stacktop = temp->next;
        free(temp);
        return true;
    }
}

//5.»ñÈ¡Õ»¶¥ÔªËØ£º
bool GetTop(LinkStack stack,int* topelem){
    if(IsEmpty(stack)){
        printf("Õ»Îª¿Õ\n");
        return false;
    }else{
        *topelem = stack->data;
        return true;
    }
}

//test mainº¯Êý£º
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