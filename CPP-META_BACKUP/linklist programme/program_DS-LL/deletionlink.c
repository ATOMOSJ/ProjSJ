#include <Stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *link;
} Node;
void treverse(Node *p)
{

    while (p != NULL)
    {
        printf("elements%d\n", p->data);
        p = p->link;
    }
}
struct Node *delfirst(Node *head)
{
    Node *p = head;
    head = head->link;
    free(p);
    return head;
}
struct Node *atindex(Node *head, int index)
{
    Node *p = head;
    Node *q = head->link;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->link;
        q = q->link;
    }
    p->link = q->link;
    free(q);
    return head;
}
struct Node *delend(Node *head)
{
    Node *p = head;
    Node *q = head->link;
    while (q->link != NULL)
    {
        p = p->link;
        q = q->link;
    }
    p->link = NULL;
    free(q);
    return head;
}
Node *delval(Node *head, int data)
{
    Node *p = head;
    Node *q = head->link;
    while (q->data != data && q->link != NULL)
    {
        p = p->link;
        q = q->link;
    }
    if (q->data == data)
    {
        p->link = q->link;
        free(q);
    }

    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));
    head->data = 7;
    head->link = second;
    second->data = 11;
    second->link = third;
    third->data = 41;
    third->link = fourth;
    fourth->data = 66;
    fourth->link = NULL;
    printf("the node before\n");
    treverse(head);
    // printf("the deletion at first cases\n");
    // head = delfirst(head);
    // treverse(head);
    // printf("deletion at a given index\n");
    // head = atindex(head, 3);
    // treverse(head);
    // printf("deletion at end \n");
    // head = delend(head);
    // treverse(head);
//     printf("deletion of a value\n");
//     head=delval(head,41);
//     treverse(head);
 }