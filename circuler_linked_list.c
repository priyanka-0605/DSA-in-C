#include <stdio.h>
#include <stdlib.h>

// simple program of creating a circular linked list
// define the node sturcture 
struct Node{
    int data;
    struct Node *next;
};
void traverseList(struct Node *head){
    // create the pointer which points to the head
    struct Node *ptr=head;
    do{
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
   
}
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
    // here the third  node will link to the head  
    third->data=27;
    third->next=head;
    traverseList(head);
    
    
    return 0;
}
