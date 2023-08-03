#include<stdio.h>
#include<stdlib.h>

 struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
void printList(struct Node* node)
{
    while (node->next != NULL) {
        printf("%d, ",node->data);
        node = node->next;
    }
    printf("%d ",node->data);
}
void push(struct Node** head, int new)
{
    struct Node* newnode =
            (struct Node*) malloc(sizeof(struct Node));
    newnode->data = new;
    newnode->prev = NULL;
    newnode->next = (*head);
    if ((*head) != NULL)
        (*head)->prev = newnode;
     *head = newnode;
}
void rotate(struct Node** head, int N)
{
    if (N == 0)
        return;
    struct Node* cur = *head;
    int count = 1;
    while (count < N && cur != NULL) {
        cur = cur->next;
        count++;
    }
    if (cur == NULL)
        return;
    struct Node* Nth = cur;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = *head;
    (*head)->prev = cur;
    *head = Nth->next;
    (*head)->prev = NULL;
    Nth->next = NULL;
}
int main(void)
{
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    int N = 2;
    printf( "input \n");
    printList(head);
    rotate(&head, N);
    printf( "\nRotated\n");
    printList(head);
    return 0;
}
