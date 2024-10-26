#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE 100//�涨˳�������������


//1.����˳���,�ɴ洢�����������˳����������ֹ��ɣ�
typedef struct SqList{
    int datas[MAXSIZE];
    int length;
}SqList;


//2.��ʼ��˳���ֻ��Ҫ��˳����ȳ�ʼ��Ϊ�㣺
void initList(SqList* L){
    L->length = 0;
}


//3.����Ԫ�أ�
bool InsertElem(SqList* L,int position,int addedelem){//bool��Ϊ�˼�麯���ܷ���������;
    if(L->length == MAXSIZE){
        return false;//˳����Ѿ����ˣ����������µ�Ԫ��;
    }else if(position<1||position>L->length+1){
        return false;//�����λ�÷Ƿ�������position=L->length+1��ʾ�ڱ�β������Ԫ��;
    }
    /*
    ����Ϊ���������������λ�ô���Ԫ�ظ��£�����λ��֮���Ԫ��ȫ�����λ�ƣ�
    ע�⣬���λ�ƵĲ�����Ҫ�ӱ�β��ʼ������ǰ��
    �Ӳ���λ�������л���ָ������󣬵��²���λ��֮�������Ԫ�ر��ԭ����λ�ô���Ԫ�أ�
    */
    else{
        int index=position-1;//ע�����������Ͳ���λ�õĹ�ϵ��
        for(int i=L->length-1;i>=index;i--){
            L->datas[i+1] = L->datas[i];
        }
        L->datas[index] = addedelem;//���봦��Ԫ�ظ��£�
        L->length++;//��ĳ��ȼ�1��
        return true;
    }

}


//4.ɾ��Ԫ��:
/*
��Ҫ�������Ϊʲô��һ��int*���͵�delelempointer:
C���Ժ����ķ���ֵͨ����һ���̶����������ͣ�����int��float���Զ���Ľṹ��struct�ȡ�
����������У������������ص���˳����б�ɾ����Ԫ�أ���������datatype����ͨ�����ں����ⲿ�����һ�����ͱ��������ܴ���int��float��char���û��Զ����struct�ȣ�ȷ����
��datatype��һ���ϴ�Ľṹ���������ӵ��������ͣ�ͨ����������ֱֵ�Ӵ��ݿ��ܻ�����Ч�ʵ��µ����⣬��Ϊ������Ҫ�����������ݽṹ��
�����ǽ�e���Ϊָ��datatype��ָ��ʱ�������ڲ�����ֱ�Ӳ�����ָ����ָ����ڴ��ַ������ɾ����Ԫ��ֵ�洢�����
�������ĺô��Ǳ��������ݵĸ��ƣ������Ч�ʡ��ر��ǵ�datatype��һ�����ͽṹ��ʱ������Ч��������Ϊ���ԡ�
*/
bool DeleteElme(SqList* L,int position,int* delelempointer){
    if(L->length == 0){
        return false;//���Ѿ����ˣ�û��ɾ�ˣ�
    }else if(position<1||position>L->length){
        return false;//ɾ����λ�ò��Ϸ�;
    }
    /*
    ����Ϊ�����������ɾȥ��Ԫ��֮���Ԫ������ǰ�ƣ�
    ע�⣬�����Ҫ��ɾ������ǰ�����ƶ������������������Ԫ��ʱ�ĸ�������
    */
    else{
        int index = position-1;
        for(int i=index;i<L->length-1;i++){
            L->datas[i] = L->datas[i+1];
        }
        *delelempointer = L->datas[index];
        L->length--;
        return true;
    }
}


//5.����Ԫ�أ�����λ��;
int CheckPosition(SqList* L,int value){
    int index;
    for(int i=0;i<L->length;i++){
        if(L->datas[i] == value){
            index = i;
            return index+1;//ͬ����Ҫע��������λ�õ�+1��ϵ;
        }
    }
    return -1;//��ʾû���ҵ���
}


//6.���������Ժ���������֪�⣺
bool IsEmpty(SqList* L){
    if(L->length == 0){
        return true;
    }
    else{
        return false;
    }
}
bool IsFull(SqList* L){
    if(L->length == MAXSIZE){
        return true;
    }
    else{
        return false;
    }
}
void CleanList(SqList* L){
    L->length = 0;
}
void PrintList(SqList* L){
    if(L->length == 0){
        printf("Empty Now\n");
    }else{
        printf("List Length:%d\n",L->length);
        printf("List:");
        for(int i=0;i<L->length;i++){
            if(i == L->length-1){
                printf("%d\n",L->datas[i]);
            }else{
                printf("%d->",L->datas[i]);
            }
        }
    }
}


//main�������ڲ��ԣ��������б�д���˴���������
int main(){
    SqList L;
    int addedelem = 10;
    int checkelem1 = 7;//���ڵļ��Ԫ�أ�
    int checkelem2 = 19;//�����ڵļ��Ԫ��;
    int delposi = 5;//ɾ����λ��;
    int addposi = 8;//���ӵ�λ��;

    //1.��ʼ��:
    initList(&L);
    PrintList(&L);

    //2.����Ԫ��:
    for(int i=0;i<10;i++){
        InsertElem(&L,i+1,i);
    }
    PrintList(&L);

    //3.���Ԫ���Ƿ���ڣ�
    int position1 = CheckPosition(&L,checkelem1);
    int position2 = CheckPosition(&L,checkelem2);
    printf("%d\n",position1);
    printf("%d\n",position2);

    //4.ɾ��Ԫ��......
    
    return 0;
}