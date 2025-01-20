#include <stdio.h>
#include <stdlib.h>

// simple program of creating a linked list
// define the node sturcture 
struct Node{
    int data;
    struct Node *next;
};
int main(){
    // making a head node
    // first declare the nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;
    // allocate memory for nodes in the linked list in a heap
    head =(struct Node *)malloc(sizeof(struct Node));
    second =(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    
    // link the nodes
    // link first and second nodes 
    head->data=7;
    head->next=second;
    // link second and third nodes 
    second->data=37;
    second->next=third;
    // terminate the third node 
    third->data=27;
    third->next=NULL;
    
    
    return 0;
}

// linked list traversal
// define the node sturcture 
struct Node{
    int data;
    struct Node *next;
};
// define a function
void LinkedListTraversal(struct Node* ptr){
    while(ptr != NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    // making a head node
    // first declare the nodes
    struct Node * head;
    struct Node * second;
    struct Node * third;
    // allocate memory for nodes in the linked list in a heap
    head =(struct Node *)malloc(sizeof(struct Node));
    second =(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    
    // link the nodes
    // link first and second nodes 
    head->data=7;
    head->next=second;
    // link second and third nodes 
    second->data=37;
    second->next=third;
    // terminate the third node 
    third->data=27;
    third->next=NULL;
    LinkedListTraversal(head);
    //  head is a pointer struct Node *ptr 
    
    return 0;
}


