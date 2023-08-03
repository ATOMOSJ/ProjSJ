//////////////////////⁡⁣⁣⁢STACKS USING ARRAY⁡////////////////////
// ⁡⁢⁡⁢⁣⁢//*𝗦𝗧𝗥𝗨𝗖𝗧 𝗦𝗧𝗔𝗖𝗞
// {
// 𝗶𝗻𝘁 𝘀𝗶𝘇𝗲;
// 𝗶𝗻𝘁 𝘁𝗼𝗽;
// 𝗶𝗻𝘁 *𝗮𝗿𝗿;
// }𝘀;
// 𝘀.𝘀𝗶𝘇𝗲=𝟴𝟬;
// 𝘀.𝘁𝗼𝗽=-𝟭;
// 𝘀.𝗮𝗿𝗿=(𝗶𝗻𝘁*)𝗺𝗮𝗹𝗹𝗼𝗰(𝘀.𝘀𝗶𝘇𝗲*𝘀𝗶𝘇𝗲𝗼𝗳(𝗶𝗻𝘁));
// 𝗢𝗣𝗘𝗥𝗔𝗧𝗜𝗢𝗡 𝗜𝗡𝗩𝗢𝗟𝗩𝗘𝗗:
// 𝗣𝗢𝗣,𝗣𝗨𝗦𝗛,𝗣𝗘𝗘𝗞;
// 𝗢(𝟭) 𝗳𝗼𝗿 𝗺𝗼𝘀𝘁 𝗼𝗳 𝘁𝗵𝗲 𝗼𝗽𝗲𝗿𝗮𝘁𝗶𝗼𝗻...
// 𝗣𝗢𝗣
// 𝗿𝗲𝘁𝘂𝗿𝗻 𝘀.𝗮𝗿𝗿[𝘀.𝘁𝗼𝗽--];
// */
// /* -->𝗣𝗨𝗦𝗛
// 𝘀𝘁𝗿𝘂𝗰𝘁 𝘀𝘁𝗮𝗰𝗸 *𝘀𝗽;
// 𝘀𝗽->𝘀𝗶𝘇𝗲=𝟴𝟬;
// 𝘀->𝘁𝗼𝗽=-𝟭;
// 𝘀𝗽->𝗮𝗿𝗿=(𝗶𝗻𝘁*)𝗺𝗮𝗹𝗹𝗼𝗰(𝘀𝗽->𝘀𝗶𝘇𝗲*𝘀𝗶𝘇𝗲𝗼𝗳(𝗶𝗻𝘁));
// 𝗶𝗳(𝗶𝘀𝗳𝘂𝗹𝗹(𝘀𝗽)){
// 𝗽𝗿𝗶𝗻𝘁𝗳("𝗼𝘃𝗲𝗿𝗳𝗹𝗼𝘄");
// }𝗲𝗹𝘀𝗲{
//     𝘀𝗽->𝘁𝗼𝗽++;
//     𝘀𝗽->𝗮𝗿𝗿[𝘀𝗽->𝘁𝗼𝗽]=𝘃𝗮𝗹;
// }
//     -->𝗣𝗢𝗣(𝗮 𝘃𝗮𝗹𝘂𝗲 𝗶𝘀 𝗿𝗲𝘁𝘂𝗿𝗻𝗲𝗱 𝗶𝗻 𝗰𝗮𝘀𝗲 𝗼𝗳 𝗽𝗼𝗽)
// 𝗶𝗳(𝗶𝘀𝗲𝗺𝗽𝘁𝘆){
//     𝗽𝗿𝗶𝗻𝘁𝗳("𝘂𝗻𝗱𝗲𝗿𝗳𝗹𝗼𝘄");
//     𝗿𝗲𝘁𝘂𝗿𝗻 -𝟭;
// }𝗲𝗹𝘀𝗲{
//  𝗶𝗻𝘁 𝘃𝗮𝗹=𝘀𝗽->𝗮𝗿𝗿[𝘀𝗽->𝘁𝗼𝗽]; (𝘀𝘁𝗼𝗿𝗲𝘀 𝘁𝗵𝗲 𝘁𝗼𝗽 𝗺𝗼𝘀𝘁 𝘃𝗮𝗹𝘂𝗲)
//  𝘀𝗽->𝘁𝗼𝗽=𝘀𝗽->𝘁𝗼𝗽-𝟭;
//  𝗿𝗲𝘁𝘂𝗿𝗻 𝘃𝗮𝗹;
// }
// }
// */⁡
// programe//
// #include <stdio.h>
// #include <stdlib.h>
// struct stack
// {
//     int size;
//     int top;
//     int *arr;
// };
// int isempty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int isfull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// void push(struct stack *ptr, int val)
// {
//     if (isfull(ptr))
//     {
//         printf("overflow\n");
//     }
//     else
//     {
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }
// }
// int pop(struct stack *ptr)
// {
//     if (isempty(ptr))
//     {
//         printf("underflow");
//     }
//     else
//     {
//         int val = ptr->arr[ptr->top];
//         ptr->top = ptr->top - 1;
//         printf("the element popped is %d\n",val);
//         return val;
//     }
// }
// //stack bottom and top operation
// int stacktop(struct stack*sp ){
//     return sp->arr[sp->top];
// }
// int stackbottom(struct stack *sp){
//     return sp->arr[0];
// }

//     int main()
//     {
//         struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
//         sp->size = 200;
//         sp->top = -1;
//         sp->arr = (int *)malloc(sp->size * sizeof(int));
//         printf("stack created\n");
//         push(sp, 56);
//         push(sp, 89);
//         push(sp, 89);
//         push(sp, 89);
//         push(sp, 34);
//         pop(sp);
//         pop(sp);
//         pop(sp);

//         if (isfull(sp))
//         {
//             printf("FULL\n");
//         }
//         if (isempty(sp))
//         {
//             printf("EMPTY\n");
//         }
//         if (!isfull(sp) && !isempty(sp))
//         {
//             printf("not both of them\n");
//         }
//         printf("the top value is %d\n",stacktop(sp));
//         printf("the bottom value is %d\n",stackbottom(sp));

//         return 0;
//     }
////////////////////////////////⁡⁣⁣⁢STACK USING LINKED LIST⁡ ////////////////////////////////
// ⁡⁢⁢⁣​‌‍‌‍‍//⁡ ⁡⁢⁢⁣// // 𝗘𝗠𝗣𝗧𝗬 -> 𝗧𝗢𝗣==𝗡𝗨𝗟𝗟
// // // // 𝗙𝗨𝗟𝗟 -> 𝗵𝗲𝗮𝗽 𝗺𝗲𝗺𝗼𝗿𝘆 𝗶𝘀 𝗲𝗵𝗮𝘂𝘀𝘁𝗲𝗱 <=> 𝗣𝘁𝗿==𝗡𝗨𝗟𝗟;
// Push()
/*apply dynamically */
/*if n==null means the allocation failed*/
/* 𝗛𝗢𝗪 𝗧𝗢 𝗔𝗣𝗣𝗟𝗬⁡​*/
// ⁡⁣⁢/*
// *pop(){
//    check is empty condn
//    struct node *n =top;
//    top=top->next; //treversing
//    int x=n->data;  //storing
//    free(n);
//    return x;
// }
// */⁡
// ⁡
// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *top = NULL;

// void linkedListTraversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

// int isEmpty(struct Node *top)
// {
//     if (top == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isFull(struct Node *top)
// {
//     struct Node *p = (struct Node *)malloc(sizeof(struct Node));
//     if (p == NULL)
//     {
//         // if dynamically it not created then it is full
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// struct Node *push(struct Node *top, int x)
// {
//     if (isFull(top))
//     {
//         printf("Stack Overflow\n");
//     }
//     else
//     {
//         struct Node *n = (struct Node *)malloc(sizeof(struct Node));
//         n->data = x;
//         n->next = top;
//         top = n;
//         return top;
//     }
// }

// int pop(struct Node *tp)
// {
//     if (isEmpty(tp))
//     {
//         printf("Stack Underflow\n");
//     }
//     else
//     {
//         struct Node *n = tp;
//         top = (tp)->next;
//         int x = n->data;
//         free(n);
//         return x;
//     }
// }
// // peek to access a pericular value
// int peek(int pos)
// {
//     struct Node *ptr = top;
//     for (int i = 0; i < pos - 1 && ptr != NULL; i++)
//     {
//         ptr = ptr->next;
//     }
//     if (ptr != NULL)
//     {
//         return ptr->data;
//     }
//     else
//     {
//         return -1;
//     }
// }

// int main()
// {
//     top = push(top, 78);
//     top = push(top, 7);
//     top = push(top, 8);

//     // linkedListTraversal(top);
    
//     printf("val at 1 is %d\n",peek(1));
//     int element = pop(top);
//     printf("Popped element is %d\n", element);
//     linkedListTraversal(top);
//     return 0;
// }
/////////////////////////////////////////////infix to postfix///////////////////////////
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
 
// struct stack
// {
//     int size;
//     int top;
//     char *arr;
// };
 
// int stackTop(struct stack* sp){
//     return sp->arr[sp->top];
// }
 
// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
 
// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
 
// void push(struct stack* ptr, char val){
//     if(isFull(ptr)){
//         printf("Stack Overflow! Cannot push %d to the stack\n", val);
//     }
//     else{
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }
// }
 
// char pop(struct stack* ptr){
//     if(isEmpty(ptr)){
//         printf("Stack Underflow! Cannot pop from the stack\n");
//         return -1;
//     }
//     else{
//         char val = ptr->arr[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }
// int precedence(char ch){
//     if(ch == '*' || ch=='/')
//         return 3;
//     else if(ch == '+' || ch=='-')
//         return 2; 
//     else
//         return 0;
// }
 
// int isOperator(char ch){
//     if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
//         return 1;
//     else
//         return 0;
// }
// char* infixToPostfix(char* infix){
//     struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
//     sp->size = 10; 
//     sp->top = -1;
//     sp->arr = (char *) malloc(sp->size * sizeof(char));
//     char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
//     int i=0; // Track infix traversal
//     int j = 0; // Track postfix addition 
//     while (infix[i]!='\0')
//     {
//         if(!isOperator(infix[i])){
//             postfix[j] = infix[i];
//             j++;
//             i++;
//         }
//         else{
//             if(precedence(infix[i])> precedence(stackTop(sp))){
//                 push(sp, infix[i]);
//                 i++;
//             }
//             else{
//                 postfix[j] = pop(sp);
//                 j++;
//             }
//         }
//     }
//     while (!isEmpty(sp))    
//     {
//         postfix[j] = pop(sp);
//         j++;
//     }
//     postfix[j] = '\0';
//     return postfix;
// }
// int main()
// {
//     char * infix = "x-y/z-k*d";
//     printf("postfix is %s", infixToPostfix(infix));
//     return 0;
// }
///////////////////////////////////////////////////////infix to prefix//////////////////////////////////
#include<string.h> 
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
# define MAX 100

// A structure to represent a stack 
struct Stack { 
    int top; 
    int maxSize;
    // we are storing string in integer array, this will not give error
    // as values will be stored in ASCII and returned in ASCII thus, returned as string again
    int* array; 
}; 

struct Stack* create(int max) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->maxSize = max; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->maxSize * sizeof(int));
    return stack; 
} 

// Checking with this function is stack is full or not
// Will return true is stack is full else false 
//Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
    if(stack->top == stack->maxSize - 1){
        printf("Will not be able to push maxSize reached\n");
    }
    // Since array starts from 0, and maxSize starts from 1
    return stack->top == stack->maxSize - 1; 
} 

// By definition the Stack is empty when top is equal to -1 
// Will return true if top is -1
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
}

// Push function here, inserts value in stack and increments stack top by 1
void push(struct Stack* stack, char item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
}

// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 

// Function to return the top from stack without removing it 
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 

// A utility function to check if the given character is operand 
int checkIfOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

// Fucntion to compare precedence
// If we return larger value means higher precedence 
int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

// The driver function for infix to postfix conversion 
int getPostfix(char* expression) 
{ 
    int i, j; 

    // Stack size should be equal to expression size for safety  
    struct Stack* stack = create(strlen(expression)); 
    if(!stack) // just checking is stack was created or not  
        return -1 ; 

    for (i = 0, j = -1; expression[i]; ++i) 
    { 
        // Here we are checking is the character we scanned is operand or not
        // and this adding to to output. 
        if (checkIfOperand(expression[i])) 
            expression[++j] = expression[i]; 

        // Here, if we scan character ‘(‘, we need push it to the stack. 
        else if (expression[i] == '(') 
            push(stack, expression[i]); 

        // Here, if we scan character is an ‘)’, we need to pop and print from the stack  
        // do this until an ‘(‘ is encountered in the stack. 
        else if (expression[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                expression[++j] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return -1; // invalid expression              
            else
                pop(stack); 
        } 
        else // if an opertor
        { 
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack))) 
                expression[++j] = pop(stack); 
            push(stack, expression[i]); 
        } 

    } 

    // Once all inital expression characters are traversed
    // adding all left elements from stack to exp
    while (!isEmpty(stack)) 
        expression[++j] = pop(stack); 

    expression[++j] = '\0'; 
    
}

void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}
void InfixtoPrefix(char *exp){

    int size = strlen(exp);

    // reverse string
    reverse(exp);
    //change brackets
    brackets(exp);
    //get postfix
    getPostfix(exp);
    // reverse string again
    reverse(exp);
}

int main()
{    
    printf("The infix is: ");

    char expression[] = "((a/b)+c)-(d+(e*f))"; 
    printf("%s\n",expression);
    InfixtoPrefix(expression); 

    printf("The prefix is: ");
    printf("%s\n",expression);

    return 0; 
}
