#include<stdio.h> 
#include<stdlib.h> 
 
struct node  
{ 
  int info; 
  struct node *link; 
  }; 
   
   
  struct node * remove_duplicates(struct node *start) 
  { 
      struct node *p,*temp; 
      p=start; 
       
    while(p!=NULL) 
       { 
           // In internal while loop we are explicitely checking for p->link should not be equl to NULL because we are getting info part of p->link so it shouldn't be NULL. 
           while(p->link!=NULL &&p->info==p->link->info) 
           { 
              temp=p->link; 
              p->link=temp->link; 
              free(temp); 
               
     // we will have to use internal while loop because there can be more than two elements in the list have same value. 
   // i.e list can be of elements like 10 20 20 20 20 30 that's why we put condition in while loop. 
              
           } 
           p=p->link; 
       } 
        
       return start; 
 
  } 
int main() 
{ 
  struct node *ptr,*temp; 
   
  ptr=(struct node *)malloc(sizeof(struct node)); 
  ptr->info=10; 
   
   // we will add one more node in our linked_list. 
  temp=(struct node *)malloc(sizeof(struct node)); 
  temp->info=10; 
  ptr->link=temp; 
   
  // adding another node.. 
  temp=(struct node *)malloc(sizeof(struct node)); 
  temp->info=20; 
  ptr->link->link=temp; 
   
   
  temp=(struct node *)malloc(sizeof(struct node)); 
  temp->info=30; 
  ptr->link->link->link=temp; 
   
   
  temp=(struct node *)malloc(sizeof(struct node)); 
  temp->info=50; 
  ptr->link->link->link->link=temp; 
   
   
  temp=(struct node *)malloc(sizeof(struct node)); 
  temp->info=50; 
  ptr->link->link->link->link->link=temp; 
   
    temp->link=NULL; 
     
    temp=ptr; 
     
    while(temp) 
    { 
       printf("\t %d",temp->info); 
       temp=temp->link; 
    } 
  printf("\n Linked list after removing the duplicates\n"); 
  temp=remove_duplicates(ptr); 
    while(temp) 
    { 
       printf("\t %d",temp->info); 
       temp=temp->link; 
    } 
   
   
  }