#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

int main()
{

    node *u, *k, *p;
    int n, i;

    printf("\nnumber nodes--->:");
    scanf("%d", &n);
    u = (node *)malloc(sizeof(node));
    printf("\n---->DATA<-----");
    scanf("%d", &u->data);

    k = u;

    for (i = 2; i <= n; i++)
    {
        p = (node *)malloc(sizeof(node));
        printf("\n Enter the data of node %d:", i);
        scanf("%d", &p->data);
        k->link = p;
        k = p;
    }

    k->link = NULL;

    k = u;

    while (k != NULL)
    {
        printf("%d->", k->data);
        k = k->link;
    }

    printf("NULL");

    return 0;
}