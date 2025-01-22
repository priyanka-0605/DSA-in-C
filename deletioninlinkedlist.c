#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void traverseList(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}
// case1:deleting the first element
// create function
struct Node * deletefirst(struct Node *head){
    // now we create a new pointer (ptr) which points head 
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
// case2 :delete element at a given index from a linked list
struct Node * deleteAtIndex(struct Node *head,int index){
    // create pointr p which points head of LL and q which points head->next
    struct Node *p=head;
    struct Node *q=head->next;
    // now we keep moving p and q pointer untill we get the index where the node is suppose to be deleted
    for(int i=0;i<index-1;i++){
        p=p->next;
        q-q->next;
    }//p and q keep moving till they get the index 
    //once they reach the desired index(where element will delete)
    p->next=q->next;
    free(q);
    return head;
}

// case3:delete the last element;
struct Node * deleteAtlast(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    //p and q keep moving till q reach to the null
    p->next=NULL;
    free(q);
    return head;
}
// case4;deleting element at the given value
struct Node * deleteAtValue(struct Node *head,int value){
    struct Node *p=head;
    struct Node *q=head->next;
    // two condition will pass cond1 or cond.2
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q-q->next;
    }
    if(q->data==value){
    p->next=q->next;
    free(q);
    }
    return head;
  
}

int main() {
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node*)malloc(sizeof(struct Node));
    // LINK THE NODES
    head->data=2;
    head->next=second;
    second->data=3;
    second->next=third;
    third->data=4;
    third->next=fourth;
    fourth->data=5;
    fourth->next=NULL;
    printf("linkedlist before deletion:\n");
    traverseList(head);
    head=deletefirst(head); //for deleting first element in linked list
    // if we want to delete another element from the first in linked list
    // head=deletefirst(head);
    head=deleteAtIndex(head,1); //index number 1
    head=deleteAtlast(head); //deleting the element at the last
    printf("linkedlist after deletion:\n:");
    traverseList(head);
   

    return 0;
}
