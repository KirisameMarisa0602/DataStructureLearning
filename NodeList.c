#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//����Node���ṹ�壬ÿ����㶼�����������ָ���򹹳ɣ�
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//1.�����µĽ�㣺
Node* CreateNewNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    if(!node){//�������ʧ�ܣ����з���ʧ��ʱnode == NULL��if(NULL)��ִ�У�if(!NULL)��ִ�У�������������ӵģ�
        printf("Error:�ڴ����ʧ��!\n");
        exit(1);
    }else{
        node->data = data;
        node->next = NULL;
        return node;
    }
}

//2.�����յ�������Ҫ������������ӽ�㣬���Է���һ��NULL�Ϳ����ˣ�
Node* CreateEmptyNodeList(){
    return NULL;
}

/*
3.ͷ�巨��
���µĽ��nextָ��ԭ����ͷ����ַ��Ȼ���½����Ϊ�µ�ͷ���;
������Ҫ�޸�ͷָ�����ָ������ͷ����ַ��head���������������޸�ͷָ����ָ������ݣ�
����head������һ��Node*���͵Ľṹ��ָ�룬������Ҫ�õ�����ָ�룺
�����
void insertAtHead(Node* head, int data) {    
    Node* newNode = createNode(data);    
    newNode->next = head;    
    head = newNode;  
}
��
���� head ��һ��ָ�� Node ��ָ�루Node* head����
����ζ����������������ݸ�����ʱ��ʵ�������ڴ���ͷָ���һ��������
��ˣ��ں����ڲ��� head ָ���������κ��޸ģ����罫��ָ��һ���µĽڵ㣩
������Ӱ�쵽�����ⲿ��ԭʼͷָ�롣

����޸�ֻӰ�캯���ڲ��� head ������������ı亯���ⲿ��ԭʼͷָ�롣
��ˣ�����������ʱ��ԭʼ������ͷָ����Ȼָ��ԭ���ĵ�һ���ڵ㣬
���������½ڵ���ᱻ��������Ϊû��ָ��ָ�����������ڴ�й©����
*/
/*
��ϸ��⸱����
�ڱ�̺ͼ������ѧ�У�����������copy��ͨ��ָ�������ݻ�����һ����ȷ���ơ�
������ƿ�����ǳ������shallow copy���������deep copy����
����ȡ���ڸ��ƹ�������δ�������ڲ������û�ָ�롣

ǳ������Shallow Copy�����߳��󿽱��ͳ��� 
ǳ����������һ���¶��󣬵���û�и���ԭ�����а�������������ָ������ݡ�
�෴������������Щ���ñ�����ˣ��¶����ԭ���������ͬ�ײ����ݵ����á�
�����Щ�����ǿɱ�ģ������Ա��޸ģ�����ô��һ�������ж���Щ���ݵ��޸Ľ�Ӱ�쵽��һ������
��Ϊ����ʵ����ָ����ͬ���ڴ�λ�á�

�����Deep Copy������������������ӵ�ͬ������ָ�뿽��ָ��
��������������¶��󣬻��ݹ�ظ�����ԭ�����а�������������ָ������ݡ�
�������¶����ԭ������ȫ������������һ�����޸Ĳ���Ӱ����һ����
���ͨ���������Ҹ���ʱ����Ϊ����Ҫ����������ص����ݣ����������Ƕ�������á�

������һ��ָ�뵽����ʱ��ʵ�������ڴ��ݸ�ָ���һ����������ָ��ֵ�ĸ��ƣ���
����ζ�ź����ڲ����յ���ָ��ͺ����ⲿԭʼָ��ָ����ͬ���ڴ�λ�ã���������������ͬ��ָ���������ˣ�������ں����ڲ��޸������ָ����������磬����ָ��һ���µ��ڴ�λ�ã�������޸Ĳ���Ӱ�쵽�����ⲿ��ԭʼָ�������

Ϊ���ܹ��ں������޸��ⲿ��ָ���������Ҫ����ָ���ָ�루������ָ�룩��
�����Ϳ���ͨ���������������ָ�����޸��ⲿ��ָ�������ָ���ֵ��
����������У���ͨ�������޸�ͷָ�룬��Ϊͷָ�뱾�������Ҫ�ڲ����ɾ���ڵ�ʱ�����¡�
*/
void InsertAtHead(Node** head,int data){
    Node* newNode = CreateNewNode(data);
    newNode->next = *head;
    *head = newNode;
}

//4.β�巨:
void InsertAtTail(Node** head,int data){
    Node* newNode = CreateNewNode(data);
    if(*head == NULL){//�����ǰ����Ϊ�գ��µĽ��ֱ����Ϊͷ���;
        *head = newNode;
        return;
    }else{
        Node* temp = *head;
        while(temp->next != NULL){//�ҵ����һ�����;
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//5.��ָ��λ�ã�����0����Ȼ0����ͷ�巨����������㣺
void InsertAtPosition(Node** head,int position,int data){
    Node* newNode = CreateNewNode(data);
    if(position == 0){
        newNode->next = *head;
        *head = newNode;
        return;
    }else{
        Node* temp = *head;
        for(int i=0;(i<position-1 && temp != NULL);i++){//û�������β����һֱ������β��,ֱ��positionλ��;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("�������ȣ�\n");
            free(newNode);//�ͷŵ��ⲿ�ֿռ�;
            return;
        }else{
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

//6.ɾȥͷ���:(ͬ���������ͷ��㱾����Ҫ����ָ��)
void DelHeadNode(Node** head){
    if(*head ==  NULL){
        printf("�����ѿգ��޷�ɾ��\n");
        return;
    }else{
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

//7.ɾȥβ���:
void DelTailNode(Node** head){
    if(*head == NULL){
        printf("�����ѿգ��޷�ɾ��\n");
        return;
    }else if((*head)->next == NULL){//ֻ��һ��Ԫ��
        free((*head));
        *head = NULL;//�ǵý����״̬�ÿ�;
        //����ֱ�ӳ�ʼ���ձ�CreatEmptyList();
        return;
    }
    else{
        Node* temp = *head;
        Node* pre = NULL;
        while(temp->next != NULL){//temp�����һ����㣬pre�ǵ����ڶ������;
            pre = temp;
            temp = temp->next;
        }
        pre->next = NULL;
        free(temp);
    }
}

//8.ɾȥָ��λ�õĽ�㣺(������ļ��̵ڶ������֣��Ȼ��Ȼ�)
void DelPositionNode(Node** head,int position){
    if(*head == NULL){
        printf("��գ��޷�ɾ��\n");
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
            printf("����������\n");
            return;
        }else{
            Node* nextNode = temp->next->next;
            free(temp->next);
            temp->next = nextNode;
        }
    }
}

//9.���ң�����λ��(������һ):
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

//10.������ӡ��
void Print(Node* head){
    Node* temp = head;
    while(temp->next != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    
    /*
    �������׺һ��NULL:
    Node* temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    */
}

//test main����:
int main(){
    Node* List = CreateEmptyNodeList();
    for(int i=0;i<10;i++){
        InsertAtHead(&List,i);
    }
    Print(List);
    //�����Ĳ��Ժ�������������
    return 0;
}