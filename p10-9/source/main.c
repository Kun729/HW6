#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CARD 52
#define FACE 13

struct card
{
	char *face;
	char *suit;
};

typedef struct card Card;

void filldeck(Card*const wdeck, const char*wface[], const char*wsuit[]);
void shuffle(Card *const wdeck);
void deal(Card *const wdeck);

int main()
{
	Card deck[CARD];
	const char*face[] = { "Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
	const char*suit[] = { "Hearts","Clubs","Diamonds","Spades" };

	srand(time(NULL));
	filldeck(deck, face, suit);
	shuffle(deck);
	deal(deck);
}

void filldeck(Card*const wdeck, const char*wface[], const char*wsuit[])
{
	for (size_t i = 0; i < CARD; ++i)
	{
		wdeck[i].face = wface[i%FACE];
		wdeck[i].suit = wsuit[i / FACE];
	}
}
void shuffle(Card *const wdeck)
{
	for (size_t i = 0; i < CARD; ++i)
	{
		size_t j = rand() % CARD;
		Card tmp = wdeck[i];
		wdeck[i] = wdeck[j];
		wdeck[j] = tmp;
	}
}
void deal(Card *const wdeck)
{
	int i;
	for (i = 0; i < CARD; i++)
	{
		printf("%5s of %-8s%s", wdeck[i].face, wdeck[i].suit, (i + 1) % 4 ? " " : "\n");
	}
}