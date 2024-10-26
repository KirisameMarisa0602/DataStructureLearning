#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//声明Node结点结构体，每个结点都是由数据域和指针域构成：
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//1.创建新的结点：
Node* CreateNewNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    if(!node){//如果分配失败，其中分配失败时node == NULL，if(NULL)不执行，if(!NULL)会执行，所以是这个样子的；
        printf("Error:内存分配失败!\n");
        exit(1);
    }else{
        node->data = data;
        node->next = NULL;
        return node;
    }
}

//2.创建空的链表：需要后续往里面添加结点，所以返回一个NULL就可以了；
Node* CreateEmptyNodeList(){
    return NULL;
}

/*
3.头插法：
将新的结点next指向原来的头结点地址，然后将新结点变更为新的头结点;
由于需要修改头指针这个指向链表头结点地址的head本身，而不仅仅是修改头指针所指向的内容，
并且head本身是一个Node*类型的结构体指针，所以需要用到二级指针：
如果：
void insertAtHead(Node* head, int data) {    
    Node* newNode = createNode(data);    
    newNode->next = head;    
    head = newNode;  
}
则：
参数 head 是一个指向 Node 的指针（Node* head）。
这意味着这个函数参数传递给函数时，实际上是在传递头指针的一个副本。
因此，在函数内部对 head 指针所做的任何修改（例如将其指向一个新的节点）
都不会影响到函数外部的原始头指针。

这个修改只影响函数内部的 head 副本，而不会改变函数外部的原始头指针。
因此，当函数返回时，原始的链表头指针仍然指向原来的第一个节点，
而创建的新节点则会被遗忘（因为没有指针指向它，导致内存泄漏）。
*/
/*
详细理解副本：
在编程和计算机科学中，“副本”（copy）通常指的是数据或对象的一个精确复制。
这个复制可以是浅拷贝（shallow copy）或深拷贝（deep copy），
具体取决于复制过程中如何处理对象内部的引用或指针。

浅拷贝（Shallow Copy）：高抽象拷贝低抽象 
浅拷贝创建了一个新对象，但它没有复制原对象中包含的所有引用指向的数据。
相反，它复制了这些引用本身。因此，新对象和原对象共享对相同底层数据的引用。
如果这些数据是可变的（即可以被修改），那么在一个对象中对这些数据的修改将影响到另一个对象，
因为它们实际上指向相同的内存位置。

深拷贝（Deep Copy）：就像上面错误例子的同级拷贝指针拷贝指针
深拷贝不仅创建了新对象，还递归地复制了原对象中包含的所有引用指向的数据。
这样，新对象和原对象完全独立，对其中一个的修改不会影响另一个。
深拷贝通常更复杂且更耗时，因为它需要复制所有相关的数据，而不仅仅是顶层的引用。

当传递一个指针到函数时，实际上是在传递该指针的一个副本（即指针值的复制）。
这意味着函数内部接收到的指针和函数外部原始指针指向相同的内存位置，但它们是两个不同的指针变量。因此，如果您在函数内部修改了这个指针变量（例如，让它指向一个新的内存位置），这个修改不会影响到函数外部的原始指针变量。

为了能够在函数中修改外部的指针变量，需要传递指针的指针（即二级指针），
这样就可以通过解引用这个二级指针来修改外部的指针变量所指向的值。
在链表操作中，这通常用于修改头指针，因为头指针本身可能需要在插入或删除节点时被更新。
*/
void InsertAtHead(Node** head,int data){
    Node* newNode = CreateNewNode(data);
    newNode->next = *head;
    *head = newNode;
}

//4.尾插法:
void InsertAtTail(Node** head,int data){
    Node* newNode = CreateNewNode(data);
    if(*head == NULL){//如果当前链表为空，新的结点直接作为头结点;
        *head = newNode;
        return;
    }else{
        Node* temp = *head;
        while(temp->next != NULL){//找到最后一个结点;
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//5.在指定位置（包括0，虽然0就是头插法）后面插入结点：
void InsertAtPosition(Node** head,int position,int data){
    Node* newNode = CreateNewNode(data);
    if(position == 0){
        newNode->next = *head;
        *head = newNode;
        return;
    }else{
        Node* temp = *head;
        for(int i=0;(i<position-1 && temp != NULL);i++){//没到链表的尾部就一直往后找尾巴,直到position位置;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("超出长度！\n");
            free(newNode);//释放掉这部分空间;
            return;
        }else{
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

//6.删去头结点:(同理，处理的是头结点本身，需要二级指针)
void DelHeadNode(Node** head){
    if(*head ==  NULL){
        printf("链表已空，无法删除\n");
        return;
    }else{
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

//7.删去尾结点:
void DelTailNode(Node** head){
    if(*head == NULL){
        printf("链表已空，无法删除\n");
        return;
    }else if((*head)->next == NULL){//只有一个元素
        free((*head));
        *head = NULL;//记得将表的状态置空;
        //或者直接初始化空表CreatEmptyList();
        return;
    }
    else{
        Node* temp = *head;
        Node* pre = NULL;
        while(temp->next != NULL){//temp是最后一个结点，pre是倒数第二个结点;
            pre = temp;
            temp = temp->next;
        }
        pre->next = NULL;
        free(temp);
    }
}

//8.删去指定位置的结点：(看着你的键盘第二行数字，比划比划)
void DelPositionNode(Node** head,int position){
    if(*head == NULL){
        printf("表空，无法删除\n");
        return;
    }else if((*head)->next == NULL){
        DelHeadNode(head);
        return;
    }else{
        Node* temp = *head;
        for(int i=0;(i<position-1 && temp != NULL);i++){
            temp = temp->next;
        }
        if(temp == NULL || temp->next == NULL){
            printf("超过链表长度\n");
            return;
        }else{
            Node* nextNode = temp->next->next;
            free(temp->next);
            temp->next = nextNode;
        }
    }
}

//9.查找，返回位置(索引加一):
int find(Node* head,int data){
    Node* temp = head;
    int index = 0;
    while(temp != NULL){
        if(temp->data == data){
            return index+1;
        }else{
            temp = temp->next;
            index++;
        }
    }
}

//10.遍历打印：
void Print(Node* head){
    Node* temp = head;
    while(temp->next != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    
    /*
    或者最后缀一个NULL:
    Node* temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    */
}

//test main函数:
int main(){
    Node* List = CreateEmptyNodeList();
    for(int i=0;i<10;i++){
        InsertAtHead(&List,i);
    }
    Print(List);
    //其他的测试函数可自行输入
    return 0;
}