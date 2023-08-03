#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *trev(struct Node *hed)
{
    struct Node *prt = hed;
    do
    {
        printf("%d\t-->", prt->data);
        prt = prt->next;
    } while (prt != hed);
    printf("NULL");
}
void check(struct Node *hed)
{
    struct Node *a;
    int c = 1;
    a = hed;
    if (a == NULL)
    {
        printf("the list is empty");
    }
    else
    {
        while (a->next != hed)
        {
            a = a->next;
            c++;
        }
    }
    printf("total no. of the nodes are:%d", c);
}
struct Node *oindex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    // for(int i=0;i<index-1;i++)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node *dex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
void count(struct Node *head)
{
    int c = 1;
    struct Node *d = head;
    while (d->next != head)
    {
        d = d->next;
        c++;
    }
    printf("the toltal nodes are: %d", c);
}
void search(struct Node *head, int data)
{
    int c = 1;
    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
        c++;
        if (p->data == data)
        {
            printf("found %d at position %d\n", data, c);
        }
        else
        {
            printf("not here");
        }
    }
}
struct Node *delval(struct Node *head, int data)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != data && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == data)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}
int main()
{
    int c;
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 3;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 41;
    third->next = fourth;
    fourth->data = 66;
    fourth->next = head;
    printf("enter the program no. \n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        printf("TRAVERSAL\n");
        trev(head);
        printf("\n");
    case 2:
        printf("CHECK\n");
        check(head);
        printf("\n");
    case 3:
        printf("INSERT\n");
        head = oindex(head, 5, 3);
        printf("\n");
        trev(head);
        printf("\n");
    case 4:

        printf("DELETION\n");
        head = dex(head, 3);
        trev(head);
        printf("\n");
    case 5:
        printf("COUNTING NODES\n");
        count(head);
        printf("\n");
    case 6:
        search(head, 66);
        printf("\n");
    case 7:
        head = delval(head, 11);
        printf("\n");
        trev(head);
    }
}
