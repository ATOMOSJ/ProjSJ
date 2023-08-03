#include <stdio.h>
typedef struct book
{
    char bookn[40];
    char authorn[90];
    int price;
    int page;
} book;
int main()
{
    book b1;
    printf("enter the name of book and author\n");
    gets(b1.bookn);
    gets(b1.authorn);
    printf("\n");
    printf("enter the price and no. of pages\n");
    scanf("%d", &(b1.price));
    scanf("%d",&(b1.page));
    printf("the details you entered are:\n");
    printf("book name \t");
    puts(b1.bookn);
    printf("\n");
    printf("author name\t");
    puts(b1.authorn);
    printf("\n");
    printf("price= %d\npage= %d", b1.price, b1.page);
    return 0;
}




// #include<stdio.h>

// struct book
// {
//     char book_name[20];
//     int bookid;
//     float book_price;
//     char author[15];
// };

// int main()
// {
//     struct book b[3];
//     int i;
//     //clrscr();
//     for(i=0; i<3; i++)
//     {
//         printf("Enter details of book #%d\n", i+1);
//         printf("Enter book id: ");
//         scanf("%d", &b[i].bookid);
//         printf("Enter book name: ");
//         scanf("%s", b[i].book_name);
//         printf("Enter book author: ");
//         scanf("%s", b[i].author);
//         printf("Enter book price: ");
//         scanf("%f", &b[i].book_price);
//     }

//     for(i=0; i<3; i++)
//     {
//         printf("\nBook %d.............\n\n", i+1);
//         printf("Book Id: %d\n", b[i].bookid);
//         printf("Book Name: %s\n", b[i].book_name);
//         printf("Book Author: %s\n", b[i].author);
//         printf("Book price: %f", b[i].book_price);
//     }
//     return 0;
// }