#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node*link;
}node;
void traverse(node*ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
}
node*insertend(node*head,int data){
    node*ptr=(node*)malloc(sizeof(node));
    ptr->data=data;
    node*p=head;
    while(p->link!=NULL){
        p=p->link;
    }
    p->link=ptr;
    ptr->link=NULL;
    return head;
    
}
int main(){
node* head,*first,*second,*third,*fourth;
head=(node*)malloc(sizeof(node));
first=(node*)malloc(sizeof(node));
second=(node*)malloc(sizeof(node));
third=(node*)malloc(sizeof(node));
fourth=(node*)malloc(sizeof(node));
head->data=7;
head->link=first;
first->data=8;
first->link=second;
second->data=9;
second->link=third;
third->data=10;
third->link=fourth;
fourth->data=11;
fourth->link=NULL;
printf("before the insert\n");
traverse(head);
printf("after insert at end\n");
head=insertend(head,12);
traverse(head);
return 0;
}