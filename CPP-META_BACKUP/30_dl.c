#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
}*head,*last;
struct node* create(int n){
    int i,data;
    struct node*new,*last;
    struct node*head=(struct node*)malloc(sizeof(struct node));
    if(n>=1){
        printf("enter node 1");
        scanf("%d",&data);
        head->data=data;
        head->prev=NULL;
        head->next=NULL;
        last=head;
        for(i<2;i<=n;i++)
        {
            new=(struct node*)malloc(sizeof(struct node));
            if(new!=NULL){
                printf("enter the data\n");
                scanf("%d",&data);
                new->data=data;
                new->prev=last;
                new->next=NULL;
                last->next=new;
                last=new;
            }else{
                printf("memory not here");
                exit;
            }
        }
        printf("CREATED\n");


    }else{
        printf("unable to allocate");
    }
    return head;
}
struct node* display(struct node* head)
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;
            temp = temp->next;
        }
    }
}
int main(){
    struct node* hed;
int n;
printf("enter the no. of nodes\n");
scanf("%d",&n);
for(int i=0;i<n;i++){

hed=create(n);
}
display(hed);
}
