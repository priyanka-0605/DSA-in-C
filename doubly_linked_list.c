#include <stdio.h>
#include <stdlib.h>
//structure of the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
// traverse in doubly linked list
void traverseList(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 8;
    head->next = second;
    head->prev = NULL;
    second->data = 8;
    second->prev = head;
    second->next = third;
    third->data = 28;
    third->prev = second;
    third->next = NULL;

    traverseList(head);//calling the function
    return 0;
}
