#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int *data;
    size_t size;
    size_t capacity;
}Vec;
Vec* creat(size_t size){
    
    if(size==0){
        return NULL;
    }
    Vec *v=(Vec*)(malloc(sizeof(Vec)));
    if(!v){
        return NULL;
    }
    int *p=(int*)calloc(size,sizeof(int));
    if(!p){
        free(v);
        v=NULL;
        return NULL;
    }
    v->data=p;
    v->capacity=size;
    v->size=size;
    return v;
}
int resize(Vec *v,size_t size){
    if(!v){
        return -1;
    }
    int *new_data=NULL;
    if(size<v->size){//截断必须截，用户目的可能节省空间不能违背目的
         new_data=(int*)realloc(v->data,sizeof(int)*size);
         if(!new_data){
            return -1;
         }
         v->data=new_data;
         v->size=size;
         v->capacity=size;
         return 1;
    } 
    if(size>=v->size&&size<=v->capacity){//扩大空间但是空间本来就够，给予权限即可
        v->size=size;
    }
    if(size>v->capacity){//大小不够了
        int new_capaciy=size>v->capacity*2?size:v->capacity*2;
        new_data=(int*)realloc(v->data,sizeof(int)*new_capaciy);
        if(!new_data){
            return -1;
        }
        v->data=new_data;
        v->size=size;
        v->capacity=new_capaciy;
        return 1;
    }
    return 1;
}
void clear(Vec *v){
    if(!v){
        return ;
    }
    free(v->data);
    v->data=NULL;
    v->capacity=0;
    v->size=0;
}
void destory(Vec *v){
    clear(v);
    free(v);
    v=NULL;
}
size_t size(const Vec*v){
    return v->size;
}
int *back(const Vec*v){
    if(!v||!v->size){
      return NULL;
    }
    return v->data+v->size-1;
}
int *at(const Vec* v,size_t i){
    if(!v||i>=v->size){
        return NULL;
    }
    return v->data+i;
}
int push_back(Vec*v,int x){
    if(!v){
        return -1;
    }
    int new_size=v->size+1;
    if(new_size>v->capacity){
        if(!resize(v,new_size)){
          return -1;
        }
    }
    v->data[new_size-1]=x;
    v->size=new_size;
}
int pop_back(Vec*v){
    if(!v||!v->size){
        return -1;
    }
    v->size=v->size-1;
}
Vec* copy_v(Vec*v){
    if(!v){
        return NULL;
    }
      Vec *cp_v=(Vec*)malloc(sizeof(Vec));
      if(!cp_v){
        return NULL;
      }
      cp_v=v;
      cp_v->data=(int*)calloc(cp_v->capacity,sizeof(int));
      memcpy(cp_v->data,v->data,v->capacity*sizeof(int));
      return cp_v;
}
void pri(int *p){
    if(!p){
        printf("下标越界\n");
        return ;
    }
    printf("%d\n",*p);
}
int main(){
    printf("判断creat\n");
    Vec *v=creat(2);
    if(!v){
        return -1;
    }
    printf("当前vec长度为:%d\n",(int)size(v));
    pri(at(v,0));
    push_back(v,5);
    push_back(v,10);
    printf("判断push\n");
    printf("当前vec长度为:%d\n",(int)size(v));
    pri(back(v));
    pop_back(v);
    printf("判断pop\n");
    pri(back(v));
    printf("判断rezize\n");
    pri(at(v,10));
    resize(v,12);
    pri(at(v,10));
    printf("当前vec长度为:%d\n",(int)size(v));
    printf("判断clear\n");
    clear(v);
    pri(at(v,10));
    printf("当前vec长度为:%d\n",(int)size(v));
    destory(v);
    return 0;
}