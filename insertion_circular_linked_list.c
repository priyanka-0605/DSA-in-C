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
    do{                                       //Do While loop is used 
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct Node *insertAtFirst(struct Node *head,int data){
    // dynamically request memory to create a node in heap 
    // ptr is the pointer which will insert
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    // create a p pointer which points at the head->next
    struct Node *p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    // at this point p points to the last node of the circuler linked list
    // now we need to built connection
    // step01: p->next joint ptr
    p->next=ptr;
    //step02:now connect ptr->next=head;
    ptr->next=head;
    //now the new head is ptr 
    return head;
    
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
    printf("Circular Linked List before insertion\n");
    traverseList(head);
    head=insertAtFirst(head,23);  //here we return the value of struct Node*
    head=insertAtFirst(head,33);   //we can insert as many elements as we want
    head=insertAtFirst(head,43);
    printf("Circular Linked List after insertion\n");
    traverseList(head);
    
    return 0;
}
