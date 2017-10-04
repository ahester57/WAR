#ifndef DECK_H_
#define DECK_H_

#include "cards.h"
#define NUMCARDS 52

void shuffle(card_t* cards);
void splitdeck(card_t* cards, card_t* p1, card_t* p2);
int findfirstzero(card_t* p);
void pushzerostoback(int ncards, card_t* p);
void shift(int start, card_t* p);

#endif
