#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//���������еĽ�㣺
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//�������нṹ��:
typedef struct Queue{
    Node* front;
    Node* rear;
    int length;
}Queue;

//1.��ʼ������:
Queue* InitQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->length = 0;
    return queue;
}

//2.�ж��Ƿ�Ϊ��:
bool IsEmpty(Queue* queue){
    return queue->front == NULL;
    //����return queue->length == 0;
}

//3.���Ԫ��:
void AddElem(Queue* queue,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(queue->rear == NULL){//�����ǰ�Ķ�����û��Ԫ��;
        queue->front = newNode;
        queue->rear = newNode;
    }else{//��ǰ�����Ѿ���Ԫ��;
        queue->rear->next = newNode;//�ڵ�ǰ��β�ͺ�����µĽ��;
        queue->rear = newNode;//���µĽ����Ϊ�µ�β��;
    }
    queue->length++;
}

//4.ɾ��Ԫ��,������ɾ����Ԫ����ʲô:
int DeleteElem(Queue* queue){
    if(IsEmpty(queue)){
        printf("�����ѿ�\n");
        exit(EXIT_FAILURE);
    }else{
        int value = queue->front->data;
        Node* temp = queue->front;//�м���������ں�����ڴ��ͷ�;
        queue->front = queue->front->next;//��ͷ;
        if(queue->front == NULL){
            queue->rear = NULL;//ʵ�ֶ��е����³�ʼ��;
        }
        free(temp);
        queue->length--;
        return value;
    }
}

//5.�鿴��Ԫ��:
int Front(Queue* queue){
    if(IsEmpty(queue)){
        printf("�����ѿ�\n");
        exit(EXIT_FAILURE);
    }else{
        return queue->front->data;
    }
}

//6.���г���:
int Length(Queue* queue){
    return queue->length;
}

//test main����:
int main(){
    Queue* queue = InitQueue();
    AddElem(queue,10);
    AddElem(queue,17);
    AddElem(queue,90);
    printf("Front elem is %d\n",Front(queue));
    printf("Queue length is %d\n",Length(queue));
    printf("deleted elem is %d\n",DeleteElem(queue));
    printf("now length is %d\n",Length(queue));
    return 0;

}