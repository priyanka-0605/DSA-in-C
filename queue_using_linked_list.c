#include <stdio.h>
#include <stdlib.h>
struct Node *f = NULL;  //global variable
struct Node *r = NULL; //global variable
struct Node
{ // for linked list
    int data;
    struct Node *next;
};
void TraverseList(struct Node *ptr){
    printf("printing the elements of linked list\n");
    while(ptr!=NULL){
        printf("elements are :%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n=(struct Node *)malloc(sizeof(struct Node ));
    if(n==NULL){       //direct condition of isFull
        printf("queue is full\n");
    }else{
        n->data=val;   //insert the value in new node n 
        n->next=NULL;
        if(f==NULL){
            f=r=n;  //When we add one element in front and rear
        }
        else{
            r->next=n;
            r=n;
        }

    }
}
int dequeue()
{
    int val=-1;
    struct Node *ptr;  //create a pointer
    if(f==NULL){       //direct condition of isFull
        printf("queue is empty\n");
    }else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    TraverseList(f);
    printf("dequeueing element %d\n",dequeue()); 
    enqueue(34);
    enqueue(24);
    enqueue(14);
    printf("dequeueing element %d\n",dequeue()); 
        
    TraverseList(f);


    return 0;
}