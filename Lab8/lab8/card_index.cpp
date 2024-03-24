#include "book.h"
#include "card_index.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>


//
//


//
void showBooks(CARD_INDEX* pCard) {
    int i = 0;
    for (int i = 0; i < pCard->count; i++) {
        std::cout << "book number:" << i << std::endl;
        printBook(*pCard->pB[i]);
    /*    printf("%s by %s, printed in %hu. Category: %s. Price: %hu$.\n",
            pCard->pB[i]->title, pCard->pB[i]->author, pCard->pB[i]->year, pCard->pB[i]->category == FICTION ? "fiction" : "nonfiction", pCard->pB[i]->price);*/
    }
    
}



//
//
//int n = 10;
void action(CARD_INDEX* pCard) {

   
    
   
        int action;
        int count = pCard->count;
        int capacity = pCard->capacity;
       
        do {
        std::cout << "\nPlease,choise your action: input,remove,show and put on number of action (0), (1), (2) and (7) for exit" << std::endl;
        std::cin >> action;
        
        switch (action) {
           
        case 0:

            addBook(pCard);

            break;
        case 1:

            bookRemove(pCard);
            break;
        
        case 2:

            showBooks(pCard);
            break;
        }

      
        // std::cout << "=============" << std::endl;
         //showBooks(*pCard->pB, count);
        }       
        while (action != 7);

        clean(pCard);
}

void addBook(CARD_INDEX*pCard) {


    if (pCard->count == pCard->capacity) { //емкость исчерпана, перераспределяем память 

        pCard->capacity += 2;
        ///       //1) увеличиваем емкость картотеки

        BOOK** new_pB = new BOOK * [pCard->capacity];
        for (int i = 0; i < pCard->count; i++)
        {
            new_pB[i] = pCard->pB[i]; // копируем во временный объект
        }


        delete[] pCard->pB;
        pCard->pB = new_pB;
    }




        BOOK* dyn = new BOOK;//  инициализируется мусором
        edit_book(dyn);
        pCard->pB[pCard->count] = dyn;
        pCard->count++;

  
  }
 
void bookRemove(CARD_INDEX* pCard)
{
    std::cout << "Please,choise book's number for remove" << std::endl;
    showBooks(pCard);
    int x;
    std::cin >> x;
    delete pCard->pB[x];
    pCard->pB[x] = 0;
    pCard->count = pCard->count - 1;

   // BOOK** new_pB = new BOOK * [pCard->capacity];
    for (int i = x; i < pCard->count; i++)
    {
        pCard->pB[i] = pCard->pB[i + 1]; // копируем во временный объект
    }
       
      
}
   
void clean(CARD_INDEX* pCard) {
    for (int i = 0; i < pCard->count; i++)
    {
        delete[]  pCard->pB[i] ;
        
    }
    delete[] pCard->pB;
    pCard->pB = 0;
    pCard->count = 0;
    pCard->capacity = 0;

 }
    
