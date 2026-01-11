#include"Priority_Queue.h"
#include<assert.h>
void test_create(){
    printf("Test create-------\n");
    Priority_Queue *q=Creat();
    assert(q!=NULL);
    Destory(&q);
    assert(q==NULL);
}
void test_push_pop(){
    printf("Test push_pop-------\n");
    Priority_Queue *q=Creat();
    assert(q!=NULL);
    int x=5;
    Push(q,x);
    assert(Top(q)==5);
    printf("Top\n");
    assert(Size(q)==1);
    x=10;
    Push(q,10);
    Push(q,8);
    Push(q,15);
    assert(Top(q)==5);
    Pop(q);
    assert(Top(q)==8);
    assert(Size(q)==3);
    Pop(q);
    assert(Top(q)==10);
    assert(Size(q)==2);
    Clear(q);
    assert(q->size==0);
    assert(Empty(q));
    Destory(&q);
    assert(q==NULL);
}


int main(){
    test_create();
    test_push_pop();
}