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
void ser(node *p, int data)
{
    int i = 0;
    node*q=(node*)malloc(sizeof(node));
    q=p;
    if (q == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {

        while (q != NULL)
        {
            if (q->data == data)
            {
                printf("item found at location %d ", i + 1);
            }
            else
            {
                printf("not found");
            }
        }
    }
}

int main()
{
    int n, ele;
    struct node *x, *y, *p;
    printf("Number of nodes: ");
    scanf("%d", &n);

    x = (struct node *)malloc(sizeof(struct node));
    printf("Enter Node 1 data: ");
    scanf("%d", &x->data);

    y = x;

    for (int i = 2; i <= n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        printf("Enter Node %d data: ", i);
        scanf("%d", &p->data);
        y->next = p;
        y = p;
    }

    y->next = NULL;
    y = x;
    printf("enter the element you want to search\n");
    scanf("%d", ele);
    ser(y, ele);
}