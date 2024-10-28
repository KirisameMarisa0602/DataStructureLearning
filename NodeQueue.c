#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//声明队列中的结点：
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//声明队列结构体:
typedef struct Queue{
    Node* front;
    Node* rear;
    int length;
}Queue;

//1.初始化队列:
Queue* InitQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->length = 0;
    return queue;
}

//2.判断是否为空:
bool IsEmpty(Queue* queue){
    return queue->front == NULL;
    //或者return queue->length == 0;
}

//3.添加元素:
void AddElem(Queue* queue,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(queue->rear == NULL){//如果当前的队列中没有元素;
        queue->front = newNode;
        queue->rear = newNode;
    }else{//当前队列已经有元素;
        queue->rear->next = newNode;//在当前的尾巴后加上新的结点;
        queue->rear = newNode;//将新的结点作为新的尾巴;
    }
    queue->length++;
}

//4.删除元素,并返回删除的元素是什么:
int DeleteElem(Queue* queue){
    if(IsEmpty(queue)){
        printf("队列已空\n");
        exit(EXIT_FAILURE);
    }else{
        int value = queue->front->data;
        Node* temp = queue->front;//中间变量，用于后面的内存释放;
        queue->front = queue->front->next;//换头;
        if(queue->front == NULL){
            queue->rear = NULL;//实现队列的重新初始化;
        }
        free(temp);
        queue->length--;
        return value;
    }
}

//5.查看首元素:
int Front(Queue* queue){
    if(IsEmpty(queue)){
        printf("队列已空\n");
        exit(EXIT_FAILURE);
    }else{
        return queue->front->data;
    }
}

//6.队列长度:
int Length(Queue* queue){
    return queue->length;
}

//test main函数:
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