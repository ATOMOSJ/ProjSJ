#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*nextptr;

}*node;
void listcreation();
void displaylist();
int main(){
    int n;
    node=NULL;
    printf("Create a circular linked list\n");
    printf("Enter number of node");
    scanf("%d",&n);
    listcreation(n);
    displaylist();
    return 0;
}
void listcreation(int n){
    int i,num;
    struct node*preptr,*newnode;
    if(n>=1){
        node=(struct node*)malloc(sizeof( struct node));
        printf("input data  ");
        scanf("%d",&num);
        node->data=num;
        node->nextptr=NULL;
        preptr=node;
        for(i=2;i<=n;i++){
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter data for node %d  ",i);
            scanf("%d",&num);
            newnode->data=num;
            newnode->nextptr=NULL;
            preptr->nextptr=newnode;
            preptr=newnode;

        }
        preptr->nextptr=node;
    }

}
void displaylist(){
    struct node*tmp;
    int n=1;
    if(node==NULL){
        printf("No data found in list");
    }
    else{
        tmp=node;
        do{
            printf("Data %d=%d\n",n,tmp->data);
            tmp=tmp->nextptr;
            n++;
        }while(tmp!=node);
    }
}