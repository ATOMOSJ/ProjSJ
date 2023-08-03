#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void tra(node *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}
struct node *rev(node *ptr)
{
    node *temp1;
    node *q = (node *)malloc(sizeof(node));
    q = ptr;
    node *p = (node *)malloc(sizeof(node));
    p = NULL;
    while (q != NULL)
    {
        temp1 = p;
        p = q;
        q = q->next;
        p->next = temp1;
    }

    ptr = p;
}

int main()
{
    node *one;
    node *two;
    node *three;
    node *four;
    one = (node *)malloc(sizeof(node));
    two = (node *)malloc(sizeof(node));
    three = (node *)malloc(sizeof(node));
    four = (node *)malloc(sizeof(node));
    one->data = 1;
    one->next = two;
    two->data = 2;
    two->next = three;
    three->data = 3;
    three->next = four;
    four->data = 4;
    four->next = NULL;
    tra(one);
    printf("\n");
    printf("after reverse\n");
    one = rev(one);
    tra(one);
}