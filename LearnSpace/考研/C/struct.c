# include <stdio.h>

struct books
{
    /* data */
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
}book= {"C语言","RUNOOB","编程语言",12333};


int main(){
    printf(" title: %s\n auther: %s\n subject: %s\n book_id: %d\n",
    book.title,book.author,book.subject,book.book_id
    );
    return 0;
}