#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<unistd.h>
#define EMPTY(q) do{\
    if(!(q)){\
        Error_Debug(ERROR_NULL);\
    }\
}while(0)

#define swap(x,y,T) do{\
T temp=(x);\
(x)=(y);\
(y)=temp;\
}while(0)

typedef enum{
    ERROR_OK=1,
    ERROR_NULL,
    ERROR_ARG,
    ERROR_MEM,
    ERROR_EMPTY
}Error_Code;
extern const char*Error_str[];
typedef struct 
{
    int *data;
    size_t size;
    size_t capacity;

}Priority_Queue;
void Error_Debug(int error_code);
void Push(Priority_Queue*q,int x);
void Pop(Priority_Queue*q);
int Top(const Priority_Queue*q);
void Clear(Priority_Queue*q);
size_t Size(const Priority_Queue*q);
int Empty(const Priority_Queue*q);
void Resize(Priority_Queue*q,size_t size);
Priority_Queue* Creat();
void Destory(Priority_Queue**q);






#endif