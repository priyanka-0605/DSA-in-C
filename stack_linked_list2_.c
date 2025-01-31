#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;

};
// make top a global variable for pop operation
struct Node* top = NULL;
// traversal of linked list
void TraverseList(struct Node* ptr){
    while(ptr!=NULL)
    {
        printf("element :%d\n",ptr->data);
        ptr=ptr->next;
    }

}
// isEmpty fucnction 
int isEmpty(struct Node* top){
    if(top==NULL){
        return 1;
    }else{
        return 0;
    }

}
int isFull(struct Node* top){
    // first create a pointer n
   struct Node*p=(struct Node*)malloc(sizeof(struct Node));
   if(p==NULL){
    return 1;
   }
   else{
    return 0;
   }
}
// create a function push
struct Node* push(struct Node* top,int x ){
    // isFull takes a pointer top
    if(isFull(top)){
        printf("stack overflow\n");
    }
    else{
        // create new node n
        struct Node* n=(struct Node*)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }

}
// implimenting pop operation however pop returns an integer value
// FOR local variablee we change the name top into tp
int pop(struct Node* tp){
    if(isEmpty(tp)){
       printf("stack underflow\n"); 
    }
    else{
        struct Node* n=tp;
        tp=(tp)->next;
        int x = n->data;
        free(n);
        return x;

    }

}
int main(){
    // create  a pointr top which is a pointer to a node which points to a null stack
    struct Node* top=NULL;
    top=push(top,78);
    top=push(top,7);
    top=push(top,38);
    // we have to store the address of top in a pointer to a node (&top)
    int element = pop(top);
    printf("popped element id %d\n",element);
    TraverseList(top);
    return 0;
}