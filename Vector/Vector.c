#include"Vector.h"
const char* Error[7] ={"","SUCCEED","VEC_NULL","VEC_EMPTY","VEC_FULL","ARG_ERROR","MEM_GET_FAL"};
Vector* Creat(size_t size,size_t elem_size){//传入创建大小

     if(size==0){
        Pri_Error(VEC_ERROR_ARG);
        return NULL;
     }
     Vector *v=(Vector*)malloc(sizeof(Vector));
     if(!v){
        Pri_Error(VEC_ERROR_MEM);
        return NULL;
     }
     v->elem_size=elem_size;
     void *p=calloc(size,sizeof(v->elem_size));
     if(!p){
        Pri_Error(VEC_ERROR_MEM);
        free(v);
        v=NULL;
        return NULL;
     }
     v->data=p;
     v->size=size;
     v->capacity=size;
     return v;
}
int Resize(Vector* v,size_t new_capacity){
   if(!new_capacity){
      free(v->data);
      v->data=NULL;
      v->capacity=0;
      v->size=0;
      return VEC_OK;
   }
    if(!v){
        return VEC_ERROR_NULL;
    }
    void *new_data=NULL;
       if(new_capacity<v->size){//新空间比原来的小用户是想缩短内存不能忽视
           new_data=(void*)realloc(v->data,sizeof(v->elem_size)*new_capacity);
           if(!new_data){
            return VEC_ERROR_MEM;
           }
           v->data=new_data;
           v->size=new_capacity;
           v->capacity=new_capacity;
           return VEC_OK;
       }
       if(new_capacity>=v->size&&new_capacity<=v->capacity){
         v->size=new_capacity;
         return VEC_OK;
       }
       if(new_capacity>v->capacity){
         size_t real_size=new_capacity;
         new_capacity=new_capacity>v->capacity*2?new_capacity:v->capacity*2;
          new_data=realloc(v->data,sizeof(v->elem_size)*new_capacity);
          if(!new_data){
            return VEC_ERROR_MEM;
          }
          v->data=new_data;
          v->capacity=new_capacity;
          v->size=real_size;
          return VEC_OK;
       }
}
int Clear(Vector*v){
      if(!v){
         return VEC_ERROR_NULL;
      }
      v->size=0;
      v->capacity=0;
      free(v->data);
      v->data=NULL;
      return VEC_OK;
}
int Push_back(Vector *v,const void *x){
     if(!v){
      return VEC_ERROR_NULL;
     }
     size_t new_capacity=v->size+1;
     if(new_capacity>v->capacity){
      if(Resize(v,new_capacity)!=VEC_OK){
         return VEC_ERROR_MEM;
      }
     }
     memcpy(v->data+new_capacity-1,x,sizeof(v->elem_size));
     v->size=new_capacity;
     return VEC_OK;

}
int Pop_back(Vector*v){
   if(!v){
      return VEC_ERROR_NULL;
     }
     if(!v->size||!v->capacity){
      return VEC_ERROR_EMPTY;
     }
     
     v->size=v->size-1;
     return VEC_OK;
}
void* Back(const Vector *v){
      if(!v||!v->size){
         return NULL;
      }
      return v->data+v->size-1;
}
void* at(const Vector *v,size_t i){
     if(!v||!v->size){
      return NULL;
     }
     if(i>=v->size){
      return NULL;
     }
     return v->data+i;
}
Vector* copy(const Vector*v){
      Vector* cp_v=(Vector*)malloc(sizeof(Vector));
      if(!v){
         Pri_Error(VEC_ERROR_NULL);
         return NULL;
      }
      
      cp_v->capacity=v->capacity;
      cp_v->size=v->size;
      cp_v->data=malloc(sizeof(v->elem_size)*cp_v->capacity);
      if(!cp_v->data){
         Pri_Error(VEC_ERROR_MEM);
         return NULL;
      }
      memcpy(cp_v->data,v->data,v->capacity*sizeof(v->elem_size));
      return cp_v;

}
void Destroy(Vector**v){
    if(!v||!*v){
      return ;
    }
    Clear(*v);
    free(*v);
    *v=NULL;
    return ;

}
void Pri_Error(int e){
   if(e<1||e>6){
      printf("预知以外的错误\n");
      return;
   }
   printf("%s\n",Error[e]);
}
int Size(const Vector*v){
   if(!v){
      return VEC_ERROR_NULL;
   }
   return v->size;
}