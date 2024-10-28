#include<stdio.h>  
#include<stdlib.h>  
#include<stdbool.h>  
#define MAXSIZE 20  
  
typedef struct CircularQueue {  
    int datas[MAXSIZE];  
    int front;  
    int rear;  
    int length;  
} CircularQueue;  
  
// 初始化循环队列  
void InitCircularQueue(CircularQueue* queue) {  
    queue->front = 0;  
    queue->rear = -1;  
    queue->length = 0;  
}  
  
// 判断状态  
bool IsEmpty(CircularQueue* queue) {  
    return queue->length == 0;  
}  
bool IsFull(CircularQueue* queue) {  
    return queue->length == MAXSIZE;  
}  
  
// 添加元素  
bool AddElem(CircularQueue* queue, int value) {  
    if (IsFull(queue)) {  
        printf("队列已满\n");  
        return false;  
    } else {  
        queue->rear = (queue->rear + 1) % MAXSIZE;  
        queue->datas[queue->rear] = value;  
        queue->length++;  
        return true;  
    }  
}  
  
// 删除元素  
bool DeleteElem(CircularQueue* queue, int* valuepointer) {  
    if (IsEmpty(queue)) {  
        printf("队列已空\n");  
        return false;  
    } else {  
        *valuepointer = queue->datas[queue->front];  
        queue->front = (queue->front + 1) % MAXSIZE;  
        if (queue->front == queue->rear+1) {//队列已空  
             queue->length = 0;
             return true;
        }else{
            queue->length--;  
            return true; 
        }
         
    }  
}  
  
// 获取大小和打印队列  
int Length(CircularQueue* queue) {  
    return queue->length;  
}  
void Print(CircularQueue* queue) {  
    if (IsEmpty(queue)) {  
        printf("队列已空\n");  
        return;  
    } else {  
        int i = queue->front;  
        for (int count = 0; count < queue->length; count++) {  
            printf("%d ", queue->datas[i]);  
            i = (i + 1) % MAXSIZE;  
        }  
        printf("\n");  
    }  
}  
  
// test main函数  
int main() {  
    CircularQueue queue;  
    InitCircularQueue(&queue);  
  
    for (int i = 1; i <= 18; i++) { // 添加元素到队列已满  
        AddElem(&queue, i);  
    }  
    
    int delelem;
    
    while(!IsEmpty(&queue)){
        int delelem;
        DeleteElem(&queue,&delelem);
        printf("delelem is %d\n",delelem);
    }
    
    for(int j=4;j<=12;j++){
        AddElem(&queue,j);
    }

    Print(&queue);  
    return 0;  
}