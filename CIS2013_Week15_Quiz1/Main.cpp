#include "Player.h"
#include "Card.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

//Behavior
//
//Game starts, a name is selected for the player.
//UI
//
//2 players and 52 cards are created.
//Game asked for the name of the non - dealer.
//Main will issue 2 cards to a dealer, and 2 cards to the player who
//Blackjack is then played

int getRandomCard()
{
	return rand() % 52;
}

int main() {
	string name;
	Player Player[2];
	Card Card[52];
	int k = 0;
	int randCard = 0;

	srand(time(NULL));

	//generate a deck
	for (int i = 0; i < 13; i++) {
		switch (i) {
		case 0: 
			Card[i, i+13, i+26, i+39].setName("Ace");
			Card[i, i+13, i+26, i+39].setValue(1);
			break;
		case 1:
			Card[i, i+13, i+26, i+39].setName("2");
			Card[i, i+13, i+26, i+39].setValue(2);
			break;
		case 2:
			Card[i, i+13, i+26, i+39].setName("3");
			Card[i, i+13, i+26, i+39].setValue(3);
			break;
		case 3:
			Card[i, i+13, i+26, i+39].setName("4");
			Card[i, i+13, i+26, i+39].setValue(4);
			break;
		case 4:
			Card[i, i+13, i+26, i+39].setName("5");
			Card[i, i+13, i+26, i+39].setValue(5);
			break;
		case 5:
			Card[i, i+13, i+26, i+39].setName("6");
			Card[i, i+13, i+26, i+39].setValue(6);
			break;
		case 6:
			Card[i, i+13, i+26, i+39].setName("7");
			Card[i, i+13, i+26, i+39].setValue(7);
			break;
		case 7:
			Card[i, i+13, i+26, i+39].setName("8");
			Card[i, i+13, i+26, i+39].setValue(8);
			break;
		case 8:
			Card[i, i+13, i+26, i+39].setName("9");
			Card[i, i+13, i+26, i+39].setValue(9);
			break;
		case 9:
			Card[i, i+13, i+26, i+39].setName("10");
			Card[i, i+13, i+26, i+39].setValue(10);
			break;
		case 10:
			Card[i, i+13, i+26, i+39].setName("Jack");
			Card[i, i+13, i+26, i+39].setValue(10);
			break;
		case 11:
			Card[i, i+13, i+26, i+39].setName("Queen");
			Card[i, i+13, i+26, i+39].setValue(10);
			break;
		case 12:
			Card[i, i+13, i+26, i+39].setName("King");
			Card[i, i+13, i+26, i+39].setValue(10);
			break;
		default:
			cout << "You shouldn't see this...";
		}
		for (int j = 0; j < 4; j++) {
			Card[j * 13 + i].setUsed(false);
			switch (j) {
			case 1:
				Card[i + 13].setSuit(" of Spades");
				break;
			case 2:
				Card[i + 26].setSuit(" of Clubs");
				break;
			case 3:
				Card[i + 39].setSuit(" of Hearts");
				break;
			case 0:
				Card[i].setSuit(" of Diamonds");
				break;
			default:
				cout << "You shouldn't see this either...";
			}
		}
	}

	for (int k = 0; k < 52; k++) {
		cout << Card[k].getName() << Card[k].getSuit() << endl;
	}

	cout << "Welcome to Blackjack. What is your name? ";
	cin >> name;
	Player[1].setName(name);
	cout << "Okay, " << Player[1].getName() << " you have:" << endl;

	//draw a random card, print it, and update the total
	randCard = getRandomCard();
	while (Card[randCard].getUsed() == true) {
		randCard = getRandomCard();
		Card[randCard];
	}
	Card[randCard].setUsed(true);
	cout << Card[randCard].getName() << Card[randCard].getSuit() << endl;
	Player[1].setScore(Card[randCard].getValue);

	//draw a random card, print it, and update the total
	randCard = getRandomCard();
	while (Card[randCard].getUsed() == true) {
		randCard = getRandomCard();
		Card[randCard];
	}
	Card[randCard].setUsed(true);
	cout << Card[randCard].getName() << Card[randCard].getSuit() << endl;
	Player[1].setScore(Card[randCard].getValue);


	

	char x;
	cin >> x;

	return 0;
}
