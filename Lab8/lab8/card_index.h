#pragma once
enum menu {
    input, edit, rem, show, ex,
};

struct CARD_INDEX {
	BOOK** pB;
	size_t capacity;
	size_t count;
};
void action(CARD_INDEX* pCard);
void showBooks(CARD_INDEX* pCard);
////void insert(BOOK* books, int n);

void addBook(CARD_INDEX* pCard);// BOOK** pB, int& count, int& capacity);
void bookRemove(CARD_INDEX* pCard);
void clean(CARD_INDEX* pCard);