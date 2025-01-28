#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
};
 
int isEmpty(struct stack* ptr){
    return ptr->top == -1;
}
         
int isFull(struct stack* ptr){
    return ptr->top == ptr->size - 1;
}
 //create a function to push the element
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
//for pop operation
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack* sp,int i){ //i is a position
    int arrayInd = sp->top -i + 1;
    if(arrayInd<0){
        printf("not a valid position\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
        }
}
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int stackBottom(struct stack* sp){
    return sp->arr[0];
}
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    printf("before pushing %d\n",isFull(sp));
    printf("before pushing %d\n",isEmpty(sp));
    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);
    push(sp,6);//this one is extra element since the size of an array is 5
    printf("The top most value of this stack is %d\n", stackTop(sp));
    printf("The bottom most value of this stack is %d\n", stackBottom(sp));
     
    printf("after pushing %d\n",isFull(sp));
    printf("after pushing %d\n",isEmpty(sp));
    printf("Popped %d from the stack\n",pop(sp));//-->>last in first out
    printf("Popped %d from the stack\n",pop(sp));  //LIFO
    printf("Popped %d from the stack\n",pop(sp)); //LIFO
    printf("Popped %d from the stack\n",pop(sp));  //LIFO
    // for(int j=1 ; j<=sp->top+1 ;j++)
    // {
    // printf("the value at index %d is %d\n",j,peek(sp,j));
 
    // }
    
    return 0;
}
        

 
