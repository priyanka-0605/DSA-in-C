#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;        //front
    int r;        //back
    int* arr;     //integer pointer
};
int isEmpty(struct queue *q){
    if(q->r==q->f){   //check whether front and rear are equal
        return 1;
    }else{
        return 0;
    }
}
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }else{
        return 0;
    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("queue is full\n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
  }
  return a;
}
void enqueue(struct queue *q,int val){   //taking intger value
    if(isFull(q)){
        printf("queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;  //insertion of element in the q arr where r is the index

    }
}

int main(){
    struct queue q;
    q.size=100;
    q.f= q.r =-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    //enqueue few elements
    enqueue(&q,12);  
    enqueue(&q,15);
    enqueue(&q,1);
    printf("dequeueing element %d\n",dequeue(&q));
    printf("dequeueing element %d\n",dequeue(&q));
    if(isEmpty(&q)){            //because it takes an address
        printf("queue is empty\n");
    }
    if(isFull(&q)){
        printf("queue is full\n");
    }
   
    return 0;
}