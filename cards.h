#ifndef CARDS_H_
#define CARDS_H_

typedef struct {
	int rank;
	int suit;
} card_t;

char** getcard(card_t cnum);
void showbattle(card_t c, card_t d);

#endif
