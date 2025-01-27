#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr; // Correctly define the pointer
};

Condition to check whether the stack is empty or not 
int isEmpty(struct stack* ptr) {
    return ptr->top == -1; // Return 1 if true, 0 if false
} 
//or we write with condition
int isEmpty(struct stack* ptr) {
    if(ptr->top == -1){
        return 1;
    } 
    else{
        return 0;
    }
}


// // Condition to check whether the stack is full or not 
int isFull(struct stack* ptr) {
    return ptr->top == ptr->size - 1; // Return 1 if true, 0 if false
}
//  another way with condition
int isFull(struct stack* ptr) {
        if(ptr->top == ptr->size - 1){
            return 1;
        } else{
            return 0;
        }
}

int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack)); // Allocate memory for the stack
    s->size = 80;
    s->top = -1; // -1 means the stack is empty
    s->arr = (int *)malloc(s->size * sizeof(int)); // Allocate memory for the stack array
    // pushing an element manually
    s->arr[0]=4;
    s->top++;
    

    // Check if stack is empty
    if (isEmpty(s)) {
        printf("The stack is empty\n");
    } else {
        printf("The stack is not empty\n");
    }
    return 0;
}