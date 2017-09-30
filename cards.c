#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <time.h>
#include "cards.h"

void showbattle(int c, int d) {
	char** cc = getcard(c);
	char** dd = getcard(d);
	char** both = (char**)malloc(10*sizeof(char*));
	int i;
	for (i = 0; i < 9; i++) {
		both[i] = (char*)malloc(56*sizeof(char));
		sprintf(both[i], "%s\t%s\n", cc[i], dd[i]);
	}
	for (i = 0; i < 9; i++) {
		fprintf(stderr, both[i]);
	}
	free(cc);
	free(dd);
	free(both);
}

char** getcard(int cnum) {
	char **card;
	card = (char**)malloc(10*sizeof(char*));
	int i;
	for (i = 0; i < 9; i++) {
		card[i] = (char*)malloc(56*sizeof(char));	
	}
	char* s;
	char num;
	struct timespec tm;
	clock_gettime(CLOCK_MONOTONIC, &tm);
	srand((unsigned)(tm.tv_sec ^ tm.tv_nsec ^ (tm.tv_nsec >> 31)));
	int suite = rand() % 4;
	switch (suite) {
		case 0:
			s = "\u2660";	
			break;
		case 1:
			s = "\u2663";
			break;
		case 2:
			s = "\u2665";
			break;
		case 3:
			s = "\u2666";	
			break;
		default:
			s = "?";
	
	}
	switch (cnum) {
		num = 's';	
		case 2:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u25022      \u2502");
			sprintf(card[2],"\u2502       \u2502");
			sprintf(card[3],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[4],"\u2502       \u2502");
			sprintf(card[5],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[6],"\u2502       \u2502");
			sprintf(card[7],"\u2502      2\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 3:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u25023      \u2502");
			sprintf(card[2],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[3],"\u2502       \u2502");
			sprintf(card[4],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[5],"\u2502       \u2502");
			sprintf(card[6],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[7],"\u2502      3\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 4:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u25024      \u2502");
			sprintf(card[2],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[3],"\u2502       \u2502");
			sprintf(card[4],"\u2502       \u2502");
			sprintf(card[5],"\u2502       \u2502");
			sprintf(card[6],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[7],"\u2502      4\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 5:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u25025      \u2502");
			sprintf(card[2],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[3],"\u2502       \u2502");
			sprintf(card[4],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[5],"\u2502       \u2502");
			sprintf(card[6],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[7],"\u2502      5\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 6:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u25026      \u2502");
			sprintf(card[2],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[3],"\u2502       \u2502");
			sprintf(card[4],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[5],"\u2502       \u2502");
			sprintf(card[6],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[7],"\u2502      6\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 7:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u25027      \u2502");
			sprintf(card[2],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[3],"\u2502       \u2502");
			sprintf(card[4],"%s%s%s%s%s%s%s","\u2502 ",s," ",s," ",s," \u2502");
			sprintf(card[5],"\u2502       \u2502");
			sprintf(card[6],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[7],"\u2502      7\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 8:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u25028      \u2502");
			sprintf(card[2],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[3],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[4],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[5],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[6],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[7],"\u2502      8\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 9:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u25029      \u2502");
			sprintf(card[2],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[3],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[4],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[5],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[6],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[7],"\u2502      9\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 10:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u250210     \u2502");
			sprintf(card[2],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[3],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[4],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[5],"%s%s%s%s%s%s%s","\u2502 ",s," ",s," ",s," \u2502");
			sprintf(card[6],"%s%s%s%s%s","\u2502 ",s,"   ",s," \u2502");
			sprintf(card[7],"\u2502     10\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 11:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u2502J      \u2502");
			sprintf(card[2],"\u2502       \u2502");
			sprintf(card[3],"\u2502       \u2502");
			sprintf(card[4],"\u2502 JACK  \u2502");
			sprintf(card[5],"\u2502       \u2502");
			sprintf(card[6],"\u2502       \u2502");
			sprintf(card[7],"\u2502      J\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 12:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u2502Q      \u2502");
			sprintf(card[2],"\u2502       \u2502");
			sprintf(card[3],"\u2502       \u2502");
			sprintf(card[4],"\u2502 QUEEN \u2502");
			sprintf(card[5],"\u2502       \u2502");
			sprintf(card[6],"\u2502       \u2502");
			sprintf(card[7],"\u2502      Q\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 13:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u2502K      \u2502");
			sprintf(card[2],"\u2502       \u2502");
			sprintf(card[3],"\u2502       \u2502");
			sprintf(card[4],"\u2502 KING  \u2502");
			sprintf(card[5],"\u2502       \u2502");
			sprintf(card[6],"\u2502       \u2502");
			sprintf(card[7],"\u2502      K\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		case 14:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u2502A      \u2502");
			sprintf(card[2],"\u2502       \u2502");
			sprintf(card[3],"\u2502       \u2502");
			sprintf(card[4],"%s%s%s","\u2502   ",s,"   \u2502");
			sprintf(card[5],"\u2502       \u2502");
			sprintf(card[6],"\u2502       \u2502");
			sprintf(card[7],"\u2502      A\u2502");
			sprintf(card[8],"\u2514-------\u2518");
			break;
		default:
			sprintf(card[0],"\u250C-------\u2510");
			sprintf(card[1],"\u2502b      \u2502");
			sprintf(card[2],"\u2502       \u2502");
			sprintf(card[3],"\u2502       \u2502");
			sprintf(card[4],"\u2502   \u2665   \u2502");
			sprintf(card[5],"\u2502       \u2502");
			sprintf(card[6],"\u2502       \u2502");
			sprintf(card[7],"\u2502      b\u2502");
			sprintf(card[8],"\u2514-------\u2518");
	}
	return card;
}


