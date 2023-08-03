#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;

} node;
node* addn(node *head, int d)
{
    node *ptr = malloc(sizeof(node));
    ptr->data = d;
    ptr->link = NULL;
    ptr->link = head;
    head = ptr;
    return head;
}
int main()
{
    node *head = malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;
    node *ptr = malloc(sizeof(node));
    ptr->data = 67;
    ptr->link = NULL;
    head->link = ptr;
    int data = 6;
    head = addn(head, data);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");

    return 0;
}
