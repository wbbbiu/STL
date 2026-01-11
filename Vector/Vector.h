#ifndef VECTOR
#define VECTOR
typedef enum{
    VEC_OK=0,
    VEC_ERROR_NULL,
    VEC_ERROR_EMPTY ,
    VEC_ERROR_FULL , 
    VEC_ERROR_ARG ,
     VEC_ERROR_MEM 

}VecError;
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
extern const char *Error[];
typedef struct 
{
    int  *data;
    size_t size;
    size_t capacity;
    size_t elem_size;
}Vector;
Vector* Creat(size_t size,size_t elem_size);
int Resize(Vector* v,size_t new_capacity);
int Clear(Vector*v);
int Push_back(Vector *v,const void *x);
int Pop_back(Vector*v);
void* Back(const Vector *v);
void* at(const Vector *v,size_t i);
Vector* copy(const Vector*v);
void Destroy(Vector **v);
void Pri_Error(int t);
int Size(const Vector*v);
#endif