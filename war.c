#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "deck.h"

// Austin Hester
// WAR

int war(card_t* p1, int* ncards1, card_t* p2, int* ncards2, int iter);
int playwar(card_t* p1, card_t* p2);
int predictwinner(card_t* p1, card_t* p2);
int maxx(int a, int b);

static card_t nocard;

int main(int argc, char** argv) {
	nocard.rank = 0;
	nocard.suit = 0;
	card_t cards[NUMCARDS];
	card_t *p1, *p2;
	p1 = (card_t*)malloc(NUMCARDS*sizeof(card_t));
	p2 = (card_t*)malloc(NUMCARDS*sizeof(card_t));
	int i;
	for (i = 0; i < NUMCARDS; i++) {
		cards[i].rank = floor((double)(i + 8) / (double)4);	
		cards[i].suit = i % 4;
	} 
	shuffle(cards);	
	splitdeck(cards, p1, p2);
	for (i = 0; i < NUMCARDS; i++) {
		fprintf(stderr, "%d\t%d\n", p1[i].rank, p2[i].rank);
	} 
	int predwinner = predictwinner(p1, p2);
	fprintf(stderr, "Predicted winner: Player %d\n", predwinner);
	sleep(1);
	FILE* fp;
	int winner = playwar(p1, p2);
	fprintf(stderr, "Predicted winner: Player %d\n", predwinner);
	fprintf(stderr, "Winner: Player %d\n", winner);
	fp = fopen("./winners.log", "a+");
	if (fp != NULL)
		fprintf(fp, "%d\n", winner);
	fclose(fp);
	sleep(2);
	return 0;
}

int playwar(card_t* p1, card_t* p2) {
	int i = 0, ncards1, ncards2;
	ncards1 = NUMCARDS/2;
	ncards2 = ncards1;
	// cards in play_
	card_t c1, c2;
	int battlewinner;
	while (ncards1 < NUMCARDS-1 || ncards2 < NUMCARDS - 1) {
		usleep(100000);
		c1 = p1[0];
		c2 = p2[0];
		fprintf(stderr, "%d\tvs\t%d\n", ncards1, ncards2);
		if (c1.rank == 0 || ncards1 < 1)
			return 2;
		if (c2.rank == 0 || ncards2 < 1)
			return 1;

		showbattle(c1, c2);
		battlewinner = maxx(c1.rank, c2.rank);
		if (battlewinner == c1.rank) {
			// player 1 won
			p1[ncards1] = c2;
			ncards1++;
			p2[0] = nocard;
			ncards2--;	
		} else if (battlewinner == c2.rank) {
			// player 2 won
			p2[ncards2] = c1;
			ncards2++;
			p1[0] = nocard;
			ncards1--;	

		} else {
			// war ensues
			war(p1, &ncards1, p2, &ncards2, 1);
			sleep(2);
		}	
		shift(0, p1);
		shift(0, p2);	
		i++;
		pushzerostoback(ncards1, p1);		
		pushzerostoback(ncards2, p2);		
	}	
	return 0;
}

// returns winner if game ends, else 0
int war(card_t* p1, int* ncards1, card_t* p2, int* ncards2, int iter) {
	fprintf(stderr, "WAR!!!\n");
	sleep(1);
	int battlewinner, i;
	int iofwar = iter * 4;
	if (iofwar > NUMCARDS-1)
		return -1;
	// cards battling_
	card_t c1, c2;
	c1 = p1[iofwar];
	c2 = p2[iofwar];
	if (c1.rank == 0) {
		int t1 = findfirstzero(p1);
		if (p1[t1-1].rank == 0) {
			for (i = 0; i < t1-1; i++) {
				if (p1[i].rank != 0) {
					p2[*ncards2] = p1[i];
					(*ncards2)++;
					p1[i] = nocard;
					*ncards1 = 0;	
				}
			}
			return 2;
		} else {
			c1 = p1[t1-1];
		}
	}
	if (c2.rank == 0) {
		int t2 = findfirstzero(p1);
		if (p2[t2-1].rank == 0) {
			for (i = 0; i < t2-1; i++) {
				if (p2[i].rank != 0) {
					p1[*ncards1] = p2[i];
					(*ncards1)++;
					p2[i] = nocard;
					*ncards2 = 0;
				}
			}
			return 1;
		} else {
			c2 = p2[t2-1];
		}
	}
	battlewinner = maxx(c1.rank, c2.rank);
	if (battlewinner == c1.rank) {
		// p1 won
		for (i = 0; i < iofwar+1; i++) {
			fprintf(stderr, "\t%d vs %d\n", p1[0].rank, p2[i].rank);
			shift(0, p1);
		}
		pushzerostoback(*ncards1, p1);
		for (i = 0; i < iofwar+1; i++) {
			p1[*ncards1] = p2[i];
			(*ncards1)++;
			p2[i] = nocard;
			(*ncards2)--;	
		}
		fprintf(stderr, "Player -1- takes\n");
		return 1;
	} else if (battlewinner == c2.rank) {
		// p2 won
		for (i = 0; i < iofwar+1; i++) {
			fprintf(stderr, "\t%d vs %d\n", p1[i].rank, p2[0].rank);
			shift(0, p2);
		}
		pushzerostoback(*ncards2, p2);
		for (i = 0; i < iofwar+1; i++) {
			p2[*ncards2] = p1[i];
			(*ncards2)++;
			p1[i] = nocard;
			(*ncards1)--;	
		}
		fprintf(stderr, "Player -2- takes\n");
		return 2;
	} else {
		// war again
		return war(p1, ncards1, p2, ncards2, iter+1);
	}
	return 0;
} 

int predictwinner(card_t* p1, card_t* p2) {
	int sum1 = 0, sum2 = 0;
	int i;
	for (i = 0; i < NUMCARDS/2; i++) {
		sum1 += p1[i].rank;
		sum2 += p2[i].rank;
	}
	if (sum1 > sum2)
		return 1;
	else
		return 2;
}

// for war, 2 <= a, b <= 14, return 0 on match
int maxx(int a, int b) {
	if (a < b) return b;
	else if (a > b) return a;
	return 0;
}
