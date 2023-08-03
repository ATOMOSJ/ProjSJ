#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
void treverse(node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}
struct node *addfirst(node *head, int data)
{
    struct node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->link = head;
    return ptr;
}
struct node *addlast(node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(node));
    ptr->data = data;
    node *p = head;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = ptr;
    ptr->link = NULL;
    return head;
}
void count(node*head){
    node*p=head;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->link;
    }
    printf("the total no. of nodes ar %d",count);
} 
int main()
{
    node *head, *one, *two;
    head = (node *)malloc(sizeof(node));
    one = (node *)malloc(sizeof(node));
    two = (node *)malloc(sizeof(node));
    head->data = 0;
    head->link = one;
    one->data = 1;
    one->link = two;
    two->data = 2;
    two->link = NULL;
    printf("the treverse of this is\n");
    treverse(head);
    printf("a node at beginning\n");
    head = addfirst(head, 8);
    treverse(head);
    printf("a node at last\n");
    head = addlast(head, 3);
    treverse(head);
    printf("the total count\n");
    count(head);

}
