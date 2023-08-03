#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
} node;

int main()
{

	node *p, *q, *r, *s, *o;
	p = (node *)malloc(sizeof(node));
	q = (node *)malloc(sizeof(node));
	r = (node *)malloc(sizeof(node));
	o = (node *)malloc(sizeof(node));
	scanf("%d", o->data);
	p->data = 10;
	q->data = 20;
	r->data = 30;

	p->link = q;
	q->link = r;
	r->link = NULL;

	s = p;

	while (s != NULL)
	{
		printf("%d=", s->data);
		s = s->link;
	}
	s->data=o;
	printf("NULL");
	return 0;
}
