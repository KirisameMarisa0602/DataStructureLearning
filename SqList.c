#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE 100//规定顺序表的最大容量；


//1.声明顺序表,由存储的数据数组和顺序表长度两部分构成；
typedef struct SqList{
    int datas[MAXSIZE];
    int length;
}SqList;


//2.初始化顺序表，只需要把顺序表长度初始化为零：
void initList(SqList* L){
    L->length = 0;
}


//3.插入元素：
bool InsertElem(SqList* L,int position,int addedelem){//bool是为了检查函数能否正常运行;
    if(L->length == MAXSIZE){
        return false;//顺序表已经满了，不能增添新的元素;
    }else if(position<1||position>L->length+1){
        return false;//插入的位置非法，其中position=L->length+1表示在表尾处增加元素;
    }
    /*
    以下为正常情况：将插入位置处的元素更新，插入位置之后的元素全部向后位移；
    注意，向后位移的操作需要从表尾开始依次向前，
    从插入位置向后进行会出现覆盖现象，导致插入位置之后的所有元素变成原插入位置处的元素；
    */
    else{
        int index=position-1;//注意数组索引和插入位置的关系；
        for(int i=L->length-1;i>=index;i--){
            L->datas[i+1] = L->datas[i];
        }
        L->datas[index] = addedelem;//插入处的元素更新；
        L->length++;//表的长度加1；
        return true;
    }

}


//4.删除元素:
/*
需要着重理解为什么是一个int*类型的delelempointer:
C语言函数的返回值通常是一个固定的数据类型，例如int、float或自定义的结构体struct等。
在这个场景中，我们期望返回的是顺序表中被删除的元素，其类型由datatype（这通常是在函数外部定义的一个类型别名，可能代表int、float、char或用户自定义的struct等）确定。
若datatype是一个较大的结构体或包含复杂的数据类型，通过函数返回值直接传递可能会面临效率低下的问题，因为可能需要复制整个数据结构。
当我们将e设计为指向datatype的指针时，函数内部可以直接操作该指针所指向的内存地址，将被删除的元素值存储在那里。
这样做的好处是避免了数据的复制，提高了效率。特别是当datatype是一个大型结构体时，这种效率提升尤为明显。
*/
bool DeleteElme(SqList* L,int position,int* delelempointer){
    if(L->length == 0){
        return false;//表已经空了，没得删了；
    }else if(position<1||position>L->length){
        return false;//删除的位置不合法;
    }
    /*
    以下为正常情况：将删去的元素之后的元素依次前移；
    注意，这次需要从删除处从前往后移动，否则会出现类似添加元素时的覆盖现象；
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


//5.查找元素，返回位置;
int CheckPosition(SqList* L,int value){
    int index;
    for(int i=0;i<L->length;i++){
        if(L->datas[i] == value){
            index = i;
            return index+1;//同样需要注意索引和位置的+1关系;
        }
    }
    return -1;//表示没有找到；
}


//6.其他功能性函数，见名知意：
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


//main函数用于测试，可以自行编写，此处仅举例：
int main(){
    SqList L;
    int addedelem = 10;
    int checkelem1 = 7;//存在的检查元素；
    int checkelem2 = 19;//不存在的检查元素;
    int delposi = 5;//删除的位置;
    int addposi = 8;//增加的位置;

    //1.初始化:
    initList(&L);
    PrintList(&L);

    //2.增加元素:
    for(int i=0;i<10;i++){
        InsertElem(&L,i+1,i);
    }
    PrintList(&L);

    //3.检查元素是否存在：
    int position1 = CheckPosition(&L,checkelem1);
    int position2 = CheckPosition(&L,checkelem2);
    printf("%d\n",position1);
    printf("%d\n",position2);

    //4.删除元素......
    
    return 0;
}