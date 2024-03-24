#include "book.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
//

void printBook(const BOOK& book) {
    printf("%s by %s, printed in %hu. Category: %s. Price: %hu$.\n",
        book.title, book.author, book.year, book.category == FICTION ? "fiction" : "nonfiction", book.price);
}

//void printBook(const BOOK* book) {
//    printf("%s by %s, printed in %hu. Category: %s. Price: %hu$.\n",
//        book->title, book->author, book->year, book->category == FICTION ? "fiction" : "nonfiction", book->price);
//}


//
//
void edit_book(BOOK* book) {
     
      char tmpCategory[12];

 
        printf("Please, input  Author\n");
        scanf("%29s", book->author);
       
        printf("Please, input  Title\n");
        scanf("%29s", book->title);

     
        do {
            printf("Please, input  Year\n");
            scanf("%hu", &book->year);
        } while (book->year <= 1458 || book->year > 2024);

        do {
            printf("Please, input  Price\n");
            scanf("%hu", &book->price);
        } while (book->price <= 0);
       
            printf("Please, input  Category\n ");
            scanf("%s", tmpCategory);
           
            if (strcmp(tmpCategory, "fiction") == 0) {
                book->category = FICTION;
            }
            else {
                book->category = NON_FICTION;
            }
     


  
    //if (strcmp(tmpCategory, "non-fiction") != 0 && strcmp(tmpCategory, "fiction") != 0) {
    //    printf("We only allow such book types as non-fiction and fiction (case sensitive)\n");
    //    return;
    //}



 
}






