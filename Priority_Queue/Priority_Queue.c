#include"Priority_Queue.h"
const char*Error_str[]={"","Succeed",
    "point is null","argument is error",
    "memory allocation failure","current container,is empty"};
void Error_Debug(int error_code){
    assert(Error_str[error_code]);
}
Priority_Queue* Creat(){
     Priority_Queue *q=(Priority_Queue*)malloc(sizeof(Priority_Queue));//为优先队列分配空间
     if(!q){
        Error_Debug(ERROR_MEM);
     }//分配失败
     int *new_data=(int*)malloc(sizeof(int));//分配一个也就是保证下标从0开始
     if(!new_data){
        free(q);
        q=NULL;
        Error_Debug(ERROR_MEM);//内存错误
     }
     q->data=new_data;//分配成功指向
     q->capacity=1;//0空出来下标从1开始
     q->size=0;//此时元素个数为0
     return q;
}
void Push(Priority_Queue*q,int x){//从小往上检查父亲
    EMPTY(q);//指针为空
    Resize(q,q->size+1);//元素个数要+1
    int current=q->size+1;//从新的末尾节点插入那就是size+1
    q->data[current]=x;
    while(current>1){
       int father=current/2;
       if(q->data[father]<=q->data[current]) break;
       swap(q->data[father],q->data[current],int);
    }
    q->size=q->size+1;//元素个数+1
    
}
void Pop(Priority_Queue*q){//从上往下检查孩子
    EMPTY(q);//指针为空
    if(q->size==0){
        Error_Debug(ERROR_EMPTY);
    }
    int current=1;//当前节点
    int next=1;//下一个节点
    swap(q->data[current],q->data[q->size],int);//第一个节点和最后一个节点交换
    q->size=q->size-1;
   while(current*2<=q->size){
    int child=current*2;
    if(child+1<=q->size&&q->data[child+1]<q->data[current]){
       swap(q->data[child+1],q->data[current],int);
    }
    if(q->data[child]>=q->data[current]){
        break;
    }
    swap(q->data[child],q->data[current],int);
    current=child;
   }
    
}
int Top(const Priority_Queue*q){
   
    EMPTY(q);
    if(q->size==0){
        Error_Debug(ERROR_EMPTY);
    }
    printf("当前top: %d\n",q->data[1]);
    return q->data[1];
}
void Clear(Priority_Queue*q){
    EMPTY(q);
    Resize(q,0);
    q->size=0;
}
size_t Size(const Priority_Queue*q){
    EMPTY(q);
    return q->size;
}
int Empty(const Priority_Queue*q){
    EMPTY(q);
    return q->size==0;
}
void Resize(Priority_Queue*q,size_t size){
    size=size+1;//元素个数要求要在原本基础上+1保证0位空出
    EMPTY(q);//指针位空
    int *new_data=NULL;
    if(size>q->capacity){//如果不够用肯定要扩充
        size_t new_capacity=size>q->capacity*2?size:q->capacity*2;
        new_data=(int*)realloc(q->data,sizeof(int)*new_capacity);
        if(!new_data)
        Error_Debug(ERROR_MEM);
        q->data=new_data;
        q->capacity=new_capacity;
        return ;
    }
    if(q->capacity==0||size<q->capacity/4){//如果是缩小，小于1.5倍我们就要缩小空间了你不可能10个元素结果占1000空间吧
        size=size>q->capacity/2?size:q->capacity/2;
        new_data=(int*)realloc(q->data,sizeof(int)*size);
        if(!new_data){
            Error_Debug(ERROR_MEM);
            return;
        }
        q->data=new_data;
        q->capacity=size;//容量改成尺寸
        return ;
    }
    
}
void Destory(Priority_Queue**q){
    EMPTY(*q);
    free((*q)->data);
    free(*q);
    *q=NULL;
}