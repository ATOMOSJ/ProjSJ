#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

int main(){
	
	struct node   *x,*y,*p;
	int n,i;

  printf("\n Enter the number of nodes:");
  scanf("%d",&n);
  x=(struct node *)malloc(sizeof(struct node));
  printf("\n Enter the data of node 1");
  scanf("%d",&x->data);
  
  y=x;
  
  for(i=2;i<=n;i++)
  {
  	p=(struct node *)malloc(sizeof(struct node));
  	printf("\n Enter the data of node %d:",i);
  	scanf("%d",&p->data);
  	y->link=p;
  	y=p;
  }
   y->link=NULL;
  y=x;
  
 

  
  while(y!=NULL){
  	printf("%d--->",y->data);
  	y=y->link;
  }
  
  printf("NULL");
  
	return 0;
}
