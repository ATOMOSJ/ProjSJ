// /////////////////////////////////////////////////////////////////Q1 *NORMAL QUEUE (FIFO) *////////////////////////////////////////////////////
// #include <stdio.h>
// #include <stdlib.h>

// struct queue
// {
//     int size;
//     int f;
//     int r;
//     int *arr;
// };
// /*checking the condition using function*/
// int isfull(struct queue *q)
// {
//     if (q->r == q->size - 1)
//     {
//         return 1;
//     }
//     return 0;
// }
// int isempty(struct queue *q)
// {
//     if (q->r == q->f)
//     {
//         return 1;
//     }
//     return 0;
// }
// int peek(struct queue *q)
// {
//     if(isempty(q)){
//         printf("its empty\n");
//     }else{

//     return q->arr[q->f];
//     }
// }

// /*ENQUEUE - INSERTING ELEMENTS FROM REAR (r) and incrementing r*/
// void enqueue(struct queue *q, int val)
// {
//     if (isfull(q))
//     {
//         printf("queue is full");
//     }
//     else
//     {
//         q->r++;
//         q->arr[q->r] = val;
//     }
// }
// /*DEQUEUE - DELETING THE ELEMENTS FROM THE FRONT (f)*/
// int dequeue(struct queue *q)
// {
//     int a = -1;
//     if (isempty(q))
//     {
//         printf("queue is empty");
//     }
//     else
//     {
//         q->f++;
//         a = q->arr[q->f];
//     }
//     return a;
// }

// int main()
// {
//     struct queue q;
//     q.size = 20;
//     q.f = q.r = -1;
//     q.arr = (int *)malloc(q.size * sizeof(int));
//     enqueue(&q, 23);
//     enqueue(&q, 17);
//     enqueue(&q, 13);
//     enqueue(&q, 15);
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("\n");
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("the peeked element is %d\n", peek(&q));

//     if (!isempty(&q) && !isfull(&q))
//     {
//         printf("this is neither full nor empty");
//     }
//     if (isempty(&q))
//     {
//         printf("this is empty");
//     }
//     printf("\n");

//     if (isfull(&q))
//     {
//         printf("this is full");
//     }
//     return 0;
// }
// /*
// --->drabacks of queue using array<---
// -> space cant be used efficiently.
// */
// FRONT==RARE(EMPTY)
// RARE==SIZE-1(FULL)
//////////////////////////////////////////////////////////////////END/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////Q3 *CIRCULAR QUEUE*/////////////////////////////////////////////////////
/*CIRCULAR INCREMENT IS
i++
I=(I+1)%size
-> it helps in using the space effectively.
 enqueue
| if(q->r+1)%q-size==q->f)(FULL)
|else
|---circular increment
dequeue
val=-1;
if(q->r===q->f);
*/
#include <stdio.h>
#include <stdlib.h>
struct cirqueue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isempty(struct cirqueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
int isfull(struct cirqueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct cirqueue *q, int val)
{
    if (isfull(q))
    {
        printf("the list is full");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("the enqueued element is %d\n", val);
    }
}
int dequeue(struct cirqueue *q)
{
    int val = -1;
    if (isempty(q))
    {
        printf("the list is empty");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        val = q->arr[q->f];
        printf("the dequeued element is %d\n", val);
    }
    return val;
}
int main()
{
    struct cirqueue q;
    q.size = 66;
    q.f = q.r = 0;
    // initiate with 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    // enque some elementss
    enqueue(&q, 23);
    enqueue(&q, 13);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 190);
    enqueue(&q, 90);

    if (!isempty(&q) && !isfull(&q))
    {
        printf("this is neither full nor empty");
    }
    if (isempty(&q))
    {
        printf("this is empty");
    }
    printf("\n");

    if (isfull(&q))
    {
        printf("this is full");
    }
    return 0;
}
///////////////////////////////////////////////////////////Q2 * LINKED LIST QUEUE MENU DRIVEN////////////////////////////////////////////
// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node * next;

// };
// struct node* front =NULL;
// struct node*rear =NULL;
// void enqueue(int val)
// {
//     struct node* ptr;
//     ptr=(struct node*)malloc(sizeof(struct node));
//     ptr->data=val;
//     ptr->next=NULL;
//     if((front==NULL)&&(rear==NULL)){
//         front = rear =ptr;
//     } else {
//         rear -> next = ptr;
//         rear = ptr;
//     }
// }
