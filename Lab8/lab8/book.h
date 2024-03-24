#pragma once
enum BookCategory {
    NON_FICTION, FICTION,
};

struct BOOK {
    unsigned short year;
    unsigned short  price;
    BookCategory category;
    char author[30];
    char title[30];
};

void printBook(const BOOK& book);

//void printBook(const BOOK* book);
void edit_book(BOOK* book);

//Распечатать содержимое картотеки (1)
    //Ввести новую книгу (2)
    //Удалить существующую(ие) (3)
    //...
    //Выход из программы (...)
