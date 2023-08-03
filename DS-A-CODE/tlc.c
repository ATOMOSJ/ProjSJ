#include <stdio.h>
#include <stdlib.h>
  
/* A structure of linked list node */
struct node {
  int data;
  struct node *next;
} *head;
 
void initialize(){
    head = NULL;
}
 
/* 
Given a Inserts a node in front of a singly linked list. 
*/
void insert(int num) {
    /* Create a new Linked List node */
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    /* Next pointer of new node will point to head node of linked list  */
    newNode->next = head;
    /* make new node as new head of linked list */
    head = newNode;
    printf("Inserted Element : %d\n", num);
}
 
int  getLength(struct node *head){
    /* Input Validation */
    if (head == NULL) { 
       printf("Error : Invalid node pointer !!!\n");         
    }else{
    int length =0;
    while(head != NULL){
        head = head->next;
        length++;
    }
    return length;

    }
      
}
 
struct node* getNthLastNode(struct node* head, int n){
    struct node *front, *back;
    int i;
    front = back = head;
    /* N should be less than length of Linked List */
    if(n > getLength(head)){
        printf("Error : n is greater than length of Linked List\n");
        return NULL;
    }
    /* Move front pointer n-1 nodes. This will create 
    a difference of n-1 nodes between front and back */
    for(i = 0; i < n-1; i++){
        front = front->next;
    }
    /* Now, move both pointers together till front reaches 
    last node of linked list. when front reaches last node 
    back pointer will be pointing to Nth last node*/
    while(front->next != NULL){
        front = front->next;
        back = back->next;
    }
     
    return back;
}
/*
Prints a linked list from head node till tail node 
*/
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    int N;
    struct node *NthNode;
    initialize();
    /* Creating a linked List*/
    insert(3);  
    insert(8); 
    insert(12); 
    insert(0);
    insert(35);
    insert(6);
     
    printf("\nLinked List\n");
    printLinkedList(head);
    printf("\nEnter value of N\n");
    scanf("%d", &N);
    NthNode = getNthLastNode(head, N);
    printf("Nth Last node is %d", NthNode->data);
    return 0;
}