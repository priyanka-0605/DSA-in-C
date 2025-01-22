#include <stdio.h>
#include <stdlib.h>

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
// -----CASE1 :INSERT AT BEGINNING---
// creating a node function
struct Node* insertAtFirst(struct Node *head ,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    // in above line we create the new node named as ptr which allocate in the memory of heap
    // giving ptr a data
    ptr->data=data;
//   operation on ptr
    ptr->next=head;
    
    // now ptr is the new head of the list
    return ptr;
}
// -----CASE2 :INSERT IN BETWEEN(HERE WE NEED INDEX )---
struct Node* insertAtIndex(struct Node *head,int data,int index){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    // create a p which strt from head to that index where new node get to be insert
     // create a pointer which point head node
    struct Node *p=head;
    // initiallizing i with 0
    int i=0;
    // below condition means run from head to one place before the index so tht the new node would insert there
    while( i!=index-1){
        p=p->next;
        i++;
    }
    // set the data
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
// -----CASE3 :INSERT AT END(HERE WE NEED INDEX )---
// creating a node function
struct Node* insertAtEnd(struct Node *head,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    // create a pointer which point head node
    struct Node *p=head;
    while(p->next!=NULL){
        //below line: p keeps moving till it not reach to the null point
        p=p->next;
}
        p->next=ptr;
        ptr->next=NULL;
        return head;
        // head don't change during the process
        
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
    printf("linked list before insertion\n");
    //  head is a pointer struct Node *ptr 
    LinkedListTraversal(head);
    // calling the function insertat first
    // this below function return new head 
   
    // head=insertAtFirst(head,50);
    // head=insertAtIndex(head,56,1);
    head=insertAtEnd(head,56);
     printf("\nlinked list after insertion\n");
    LinkedListTraversal(head);
    
    
    
    return 0;
}
