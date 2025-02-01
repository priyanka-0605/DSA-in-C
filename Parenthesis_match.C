#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return '\0';  // Return null character instead of -1
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(char *exp)
{
    // Allocate memory for stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack)); //  Allocate memory for sp
    if (sp == NULL) // Check if malloc failed
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    if (sp->arr == NULL) // Check if malloc failed
    {
        printf("Memory allocation for array failed\n");
        free(sp);
        return 0;
    }

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                free(sp->arr); // Free allocated memory
                free(sp);
                return 0;
            }
            pop(sp);
        }
    }

    int result = isEmpty(sp);

    free(sp->arr); // Free allocated memory
    free(sp);

    return result;
}

int main()
{
    char *exp = "((8)(*--$$9))";

    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching\n");
    }
    else
    {
        printf("The parenthesis is not matching\n");
    }

    return 0;
}