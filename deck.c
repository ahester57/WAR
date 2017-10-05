// Austin Hester
// deck.c
// A deck of cards
#include <stdlib.h>
#include <time.h>
#include "deck.h"
#include "cards.h"

// represents the lack of a card
static card_t nocard = {0, 0};

// shuffles deck 
void
shuffle(card_t* cards)
{
	struct timespec tm;
	clock_gettime(CLOCK_MONOTONIC, &tm);
	srand((unsigned)(tm.tv_sec ^ tm.tv_nsec ^ (tm.tv_nsec >> 31)));
	int i;
	int newspot;
	card_t tempcard;
	for (i = 0; i < NUMCARDS; i++) {
		newspot = rand() % NUMCARDS;
		tempcard = cards[newspot];
		cards[newspot] = cards[i];
		cards[i] = tempcard;	
	}	
	return;
}

// splits deck in half
void
splitdeck(card_t* cards, card_t* p1, card_t* p2)
{
	int i, j;
	j = NUMCARDS - 1;
	for (i = 0; i < NUMCARDS/2; i++) {
		p1[i] = cards[i];
		p2[i] = cards[j];
		j--;
	}
	for (i = NUMCARDS/2; i < NUMCARDS; i++) {
		p1[i] = nocard;
		p2[i] = nocard;
	}
	return;
}

// returns index of first zero
int
findfirstzero(card_t* p)
{
	int i;
	for (i = 0; i < NUMCARDS; i++) {
		if (p[i].rank == 0)
			return i;	
	}
	return -1;
}

// pushes all zeros to back of player's hand 
void
pushzerostoback(int ncards, card_t* p)
{
	int i, j;
	for (i = 0; i < NUMCARDS - ncards + 1; i++) { // for however many zeros
		j = findfirstzero(p);
		if (j != -1)
			shift(j, p);	
	}
	return;
}

// puts head at end, shifts rest up
void
shift(int start, card_t* p)
{
	int i;
	card_t temp = p[start];
	for (i = start; i < NUMCARDS-1; i++) {
		p[i] = p[i+1];
	}
	p[NUMCARDS-1] = temp;
	return;
}
