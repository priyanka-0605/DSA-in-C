#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
    int size;
    int f;
    int r;
    int* arr;
 };
int isEmpty(struct circularQueue *q){
    if(q->f==q->r){
        return 1;
    }return 0;
}
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size==q->f){          //q->f again reach to the first point -1  circular increment of rear and it equal to/reach to the front 
        return 1;
    }
    return 0;
}
void enqueue(struct circularQueue *q,int val){
    if(isFull(q)){
        printf("circular queue if full\n");
        
    }
    else{
        printf("enqueued element: %d\n",val);
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;

    } 
}
int dequeue(struct circularQueue *q){
    int a =-1;
    if(isEmpty(q)){
        printf("circular queue is empty\n");
    }else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}
int main(){
    struct circularQueue q;
    q.size=5;
    q.f=q.r=0;     //front should be 0 in circular queue
    q.arr=(int*)malloc(q.size*sizeof(int)); //dynamically create a memory for array
    enqueue(&q,12);
    enqueue(&q,34);
    enqueue(&q,24);
    enqueue(&q,14);
    printf("dequeueing elements%d\n",dequeue(&q));
    printf("dequeueing elements%d\n",dequeue(&q));
    printf("dequeueing elements%d\n",dequeue(&q));
    // enqueue(&q,12);
    // enqueue(&q,12);
    if(isEmpty(&q)){
        printf("CIRULAR QUEUE is empty\n");
    }
    if(isFull(&q)){
        printf("circular queue is full\n");
    }
    return 0;
}