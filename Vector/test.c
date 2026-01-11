#include"Vector.h"

#include<assert.h>
void test_create(){
    printf("Test create-------\n");
    Vector *v=Creat(0,sizeof(int));
    assert(v==NULL);
    v=Creat(2,sizeof(int));
    assert(v!=NULL);
    assert(Size(v)==2);
    assert(v->capacity==2);
    assert(v->data[0]==0&&v->data[1]==0);
    Destroy(&v);
    assert(v==NULL);
}
void test_push_pop(){
    printf("Test push_pop-------\n");
    Vector *v=Creat(2,sizeof(int));
    assert(v!=NULL);
    int x=5;
    Push_back(v,&x);
    assert(*((int*)Back(v))==5);
    assert(Size(v)==3);
    x=10;
    Push_back(v,&x);
    assert(*((int*)Back(v))==10);
    assert(v->data[2]==5&&v->data[3]==10);
    assert(Size(v)==4);
    Pop_back(v);
    assert(*((int*)Back(v))==5);
    assert(Size(v)==3);
    Pop_back(v);
    assert(*((int*)Back(v))==0);
    assert(Size(v)==2);
    Destroy(&v);
    assert(v==NULL);
}
void test_resize_clear(){
    printf("Test resize_clear-------\n");
    Vector* v=Creat(2,sizeof(int));
    assert(Size(v)==2);
    Resize(v,10);
    assert(Size(v)==10);
    v->data[8]=10;
    assert(v->data[8]==10);
    Clear(v);
    assert(v->data==NULL);
    assert(v->size==0&&v->capacity==0);
    Destroy(&v);

}
void test_char_create(){
    printf("Test char create-------\n");
    Vector *v=Creat(0,sizeof(char));
    assert(v==NULL);
    v=Creat(2,sizeof(char));
    assert(v!=NULL);
    assert(Size(v)==2);
    assert(v->capacity==2);
    Destroy(&v);
    assert(v==NULL);
}
void test_char_push_pop(){
    printf("Test char push_pop-------\n");
    Vector *v=Creat(2,sizeof(char));
    assert(v!=NULL);
    char x='a';
    Push_back(v,&x);
    assert(*((char*)Back(v))=='a');
    assert(Size(v)==3);
    x='c';
    Push_back(v,&x);
    assert(*((char*)Back(v))=='c');
    assert((char)v->data[2]=='a'&&(char)v->data[3]=='c');
    assert(Size(v)==4);
    Pop_back(v);
    assert(*((char*)Back(v))=='a');
    assert(Size(v)==3);
    Pop_back(v);
    assert(Size(v)==2);
    Destroy(&v);
    assert(v==NULL);
}
void test_char_resize_clear(){
    printf("Test char resize_clear-------\n");
    Vector* v=Creat(2,sizeof(char));
    assert(Size(v)==2);
    Resize(v,10);
    assert(Size(v)==10);
    v->data[8]='d';
    assert(v->data[8]=='d');
    Clear(v);
    assert(v->data==NULL);
    assert(v->size==0&&v->capacity==0);
    Destroy(&v);

}
int main(){
    test_create();
    test_push_pop();
    test_resize_clear();
    test_char_create();
    test_char_push_pop();
    test_char_resize_clear();
}