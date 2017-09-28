#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define NUMCARDS 52

// Austin Hester
// WAR

//int playwar();
void shuffle(int* cards);
void splitdeck(int* cards, int* p1, int* p2);
int playwar(int* p1, int* p2);
int findfirstzero(int* p);
void pushzerostoback(int ncards, int* p);
void shift(int start, int* p);
int maxx(int a, int b);

int main(int argc, char** argv) {
	int cards[NUMCARDS];
	int *p1, *p2;
	p1 = (int*)calloc(NUMCARDS, sizeof(int));
	p2 = (int*)calloc(NUMCARDS, sizeof(int));
	int i;
	for (i = 0; i < NUMCARDS; i++) {
		cards[i] = floor((double)(i + 8) / (double)4);	
	} 
	shuffle(cards);	
	splitdeck(cards, p1, p2);
	for (i = 0; i < NUMCARDS; i++) {
		fprintf(stderr, "%d\t%d\n", p1[i], p2[i]);
	} 
	int winner = playwar(p1, p2);
	fprintf(stderr, "winner player %d\n", winner);
	for (i = 0; i < NUMCARDS; i++) {
		fprintf(stderr, "%d\t%d\n", p1[i], p2[i]);
	} 
	return 0;
}

void shuffle(int* cards) {
	struct timespec tm;
	clock_gettime(CLOCK_MONOTONIC, &tm);
	srand((unsigned)(tm.tv_sec ^ tm.tv_nsec ^ (tm.tv_nsec >> 31)));
	int i;
	int newspot;
	int tempcard;
	for (i = 0; i < NUMCARDS; i++) {
		newspot = rand() % NUMCARDS;
		tempcard = cards[newspot];
		cards[newspot] = cards[i];
		cards[i] = tempcard;	
	}	
	return;
}

void splitdeck(int* cards, int* p1, int* p2) {
	int i, j;
	j = NUMCARDS - 1;
	for (i = 0; i < NUMCARDS/2; i++) {
		p1[i] = cards[i];
		p2[i] = cards[j];
		j--;
	}
	return;
}

int playwar(int* p1, int* p2) {
	int i = 0, ncards1, ncards2;
	ncards1 = NUMCARDS/2;
	ncards2 = ncards1;
	int c1, c2;
	int tp1 = 0, tp2 = 0;
	int battlewinner;
	while (ncards1 < NUMCARDS-1 || ncards2 < NUMCARDS - 1) {
		c1 = p1[0];
		c2 = p2[0];

		if (c1 == 0 || ncards2 < 5)
			return 1;
		if (c2 == 0 || ncards1 < 5)
			return 2;

		battlewinner = maxx(c1, c2);
		if (battlewinner == c1) {
			// player 1 won
			p1[ncards1] = c2;
			ncards1++;
			p2[0] = 0;
			ncards2--;	
		} else if (battlewinner == c2) {
			// player 2 won
			p2[ncards2] = c1;
			ncards2++;
			p1[0] = 0;
			ncards1--;	

		} else {
			// war ensues

		}	
		fprintf(stderr, "whoa nelly shifting\n");
		shift(0, p1);
		shift(0, p2);	
		tp1++;
		tp2++;

		pushzerostoback(ncards1, p1);		
		pushzerostoback(ncards2, p2);		
	}	
	return 0;
}

int findfirstzero(int* p) {
	int i;
	for (i = 0; i < NUMCARDS; i++) {
		if (p[i] == 0)
			return i;	
	}
	return -1;
}

void pushzerostoback(int ncards, int* p) {
	int i, j;
	for (i = 0; i < NUMCARDS - ncards + 1; i++) { // for however many zeros
		j = findfirstzero(p);
		shift(j, p);	
	}
	return;
}

void shift(int start, int* p) {
	int i, temp;
	temp = p[start];
	for (i = start; i < NUMCARDS-1; i++) {
		p[i] = p[i+1];
	}
	p[NUMCARDS-1] = temp;
	return;
}

// for war, 2 <= a, b <= 14, return 0 on match
int maxx(int a, int b) {
	int max;
	if (a < b) return b;
	else if (a > b) return a;
	return 0;
}
