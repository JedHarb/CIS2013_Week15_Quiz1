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

	char cont = 'y';
	int k = 0;
	int randCard = 0;
	char hitStay;

	srand(time(NULL));

	while (cont == 'y') {
		//generate a deck 
		//definitely not the easiest way I could have done this... but it works!
		for (int i = 0; i < 13; i++) {
			switch (i) {
			case 0:
				Card[i].setName("Ace"); Card[i + 13].setName("Ace"); Card[i + 26].setName("Ace"); Card[i + 39].setName("Ace");
				Card[i].setValue(1); Card[i + 13].setValue(1); Card[i + 26].setValue(1); Card[i + 39].setValue(1);
				break;
			case 1:
				Card[i].setName("2"); Card[i + 13].setName("2"); Card[i + 26].setName("2"); Card[i + 39].setName("2");
				Card[i].setValue(2); Card[i + 13].setValue(2); Card[i + 26].setValue(2); Card[i + 39].setValue(2);
				break;
			case 2:
				Card[i].setName("3"); Card[i + 13].setName("3"); Card[i + 26].setName("3"); Card[i + 39].setName("3");
				Card[i].setValue(3); Card[i + 13].setValue(3); Card[i + 26].setValue(3); Card[i + 39].setValue(3);
				break;
			case 3:
				Card[i].setName("4"); Card[i + 13].setName("4"); Card[i + 26].setName("4"); Card[i + 39].setName("4");
				Card[i].setValue(4); Card[i + 13].setValue(4); Card[i + 26].setValue(4); Card[i + 39].setValue(4);
				break;
			case 4:
				Card[i].setName("5"); Card[i + 13].setName("5"); Card[i + 26].setName("5"); Card[i + 39].setName("5");
				Card[i].setValue(5); Card[i + 13].setValue(5); Card[i + 26].setValue(5); Card[i + 39].setValue(5);
				break;
			case 5:
				Card[i].setName("6"); Card[i + 13].setName("6"); Card[i + 26].setName("6"); Card[i + 39].setName("6");
				Card[i].setValue(6); Card[i + 13].setValue(6); Card[i + 26].setValue(6); Card[i + 39].setValue(6);
				break;
			case 6:
				Card[i].setName("7"); Card[i + 13].setName("7"); Card[i + 26].setName("7"); Card[i + 39].setName("7");
				Card[i].setValue(7); Card[i + 13].setValue(7); Card[i + 26].setValue(7); Card[i + 39].setValue(7);
				break;
			case 7:
				Card[i].setName("8"); Card[i + 13].setName("8"); Card[i + 26].setName("8"); Card[i + 39].setName("8");
				Card[i].setValue(8); Card[i + 13].setValue(8); Card[i + 26].setValue(8); Card[i + 39].setValue(8);
				break;
			case 8:
				Card[i].setName("9"); Card[i + 13].setName("9"); Card[i + 26].setName("9"); Card[i + 39].setName("9");
				Card[i].setValue(9); Card[i + 13].setValue(9); Card[i + 26].setValue(9); Card[i + 39].setValue(9);
				break;
			case 9:
				Card[i].setName("10"); Card[i + 13].setName("10"); Card[i + 26].setName("10"); Card[i + 39].setName("10");
				Card[i].setValue(10); Card[i + 13].setValue(10); Card[i + 26].setValue(10); Card[i + 39].setValue(10);
				break;
			case 10:
				Card[i].setName("Jack"); Card[i + 13].setName("Jack"); Card[i + 26].setName("Jack"); Card[i + 39].setName("Jack");
				Card[i].setValue(10); Card[i + 13].setValue(10); Card[i + 26].setValue(10); Card[i + 39].setValue(10);
				break;
			case 11:
				Card[i].setName("Queen"); Card[i + 13].setName("Queen"); Card[i + 26].setName("Queen"); Card[i + 39].setName("Queen");
				Card[i].setValue(10); Card[i + 13].setValue(10); Card[i + 26].setValue(10); Card[i + 39].setValue(10);
				break;
			case 12:
				Card[i].setName("King"); Card[i + 13].setName("King"); Card[i + 26].setName("King"); Card[i + 39].setName("King");
				Card[i].setValue(10); Card[i + 13].setValue(10); Card[i + 26].setValue(10); Card[i + 39].setValue(10);
				break;
			default:
				cout << "You shouldn't see this...";
			}
			for (int j = 0; j < 4; j++) {
				Card[j * 13 + i].setUsed(false);
				switch (j) {
				case 0:
					Card[i].setSuit(" of Diamonds");
					break;
				case 1:
					Card[i + 13].setSuit(" of Spades");
					break;
				case 2:
					Card[i + 26].setSuit(" of Clubs");
					break;
				case 3:
					Card[i + 39].setSuit(" of Hearts");
					break;
				default:
					cout << "You shouldn't see this either...";
				}
			}
		}

		//// test for proper deck generation
		//for (int k = 0; k < 52; k++) {
		//	cout << Card[k].getName() << Card[k].getSuit() << Card[k].getUsed() << Card[k].getValue() <<  endl;
		//}

		Player[0].resetScore();
		Player[1].resetScore();
		Player[0].setStay(false);
		Player[1].setStay(false);
		name = "Dealer";
		Player[0].setName(name);
		cout << "Welcome to Blackjack. What is your name? ";
		cin >> name;
		Player[1].setName(name);
		cout << "Okay, " << Player[1].getName() << ". " << Player[0].getName() << " starts and draws:" << endl;

		//draw a random card, print it, and update the total
		randCard = getRandomCard();
		while (Card[randCard].getUsed() == true) {
			randCard = getRandomCard();
		}
		Card[randCard].setUsed(true);
		cout << Card[randCard].getName() << Card[randCard].getSuit() << endl;
		Player[0].setScore(Card[randCard].getValue());

		//draw a random card, print it, and update the total
		randCard = getRandomCard();
		while (Card[randCard].getUsed() == true) {
			randCard = getRandomCard();
		}
		Card[randCard].setUsed(true);
		cout << Card[randCard].getName() << Card[randCard].getSuit() << endl;
		Player[0].setScore(Card[randCard].getValue());

		cout << "The dealer has " << Player[0].getScore() << "." << endl << endl;
		cout << Player[1].getName() << " draws:" << endl;

		//draw a random card, print it, and update the total
		randCard = getRandomCard();
		while (Card[randCard].getUsed() == true) {
			randCard = getRandomCard();
		}
		Card[randCard].setUsed(true);
		cout << Card[randCard].getName() << Card[randCard].getSuit() << endl;
		Player[1].setScore(Card[randCard].getValue());

		//draw a random card, print it, and update the total
		randCard = getRandomCard();
		while (Card[randCard].getUsed() == true) {
			randCard = getRandomCard();
		}
		Card[randCard].setUsed(true);
		cout << Card[randCard].getName() << Card[randCard].getSuit() << endl;
		Player[1].setScore(Card[randCard].getValue());

		cout << Player[1].getName() << " has " << Player[1].getScore() << "." << endl << endl;

		//user plays
		while (Player[1].getStay() == false) {
			cout << "Hit (h) or stay (s)? ";
			cin >> hitStay;
			if (hitStay == 'h') {
				//draw a random card, print it, and update the total
				cout << "Hitting, " << Player[1].getName() << " draws: " << endl;
				randCard = getRandomCard();
				while (Card[randCard].getUsed() == true) {
					randCard = getRandomCard();
				}
				Card[randCard].setUsed(true);
				cout << Card[randCard].getName() << Card[randCard].getSuit() << endl;
				Player[1].setScore(Card[randCard].getValue());
				cout << Player[1].getName() << " has " << Player[1].getScore() << "." << endl;

				if (Player[1].getScore() > 21) {
					cout << "Bust! " << Player[1].getName() << " has more than 21, " << Player[1].getName() << " loses." << endl;
					Player[1].setStay(true);
				}
			}
			if (hitStay == 's') {
				Player[1].setStay(true);
				cout << endl;
			}
		}

		//dealer plays if player has not bust
		if (Player[1].getScore() < 22) {
			while (Player[0].getStay() == false) {
				if (Player[0].getScore() < 17) {
					cout << Player[0].getName() << " has less than 17 and must hit." << endl;
					//draw a random card, print it, and update the total
					cout << "Hitting, " << Player[0].getName() << " draws: ";
					randCard = getRandomCard();
					while (Card[randCard].getUsed() == true) {
						randCard = getRandomCard();
					}
					Card[randCard].setUsed(true);
					cout << Card[randCard].getName() << Card[randCard].getSuit() << endl;
					Player[0].setScore(Card[randCard].getValue());
					cout << Player[0].getName() << " has " << Player[0].getScore() << "." << endl;

					if (Player[0].getScore() > 21) {
						cout << "Bust! " << Player[0].getName() << " has more than 21, " << Player[0].getName() << " loses." << endl << Player[1].getName() << " wins!" << endl;
						Player[0].setStay(true);
					}
				}
				else if (Player[0].getScore() > 16) {
					cout << Player[0].getName() << " has more than 16 and must stay." << endl;
					Player[0].setStay(true);
					if (Player[0].getScore() > Player[1].getScore()) {
						cout << Player[0].getName() << " has " << Player[0].getScore() << " and " << Player[1].getName() << " has " << Player[1].getScore() << ". " << Player[0].getName() << " wins.";
					}
					else if (Player[0].getScore() < Player[1].getScore()) {
						cout << Player[0].getName() << " has " << Player[0].getScore() << " and " << Player[1].getName() << " has " << Player[1].getScore() << ". " << Player[1].getName() << " wins!" << endl;
					}
					else if (Player[0].getScore() == Player[1].getScore()) {
						cout << Player[0].getName() << " has " << Player[0].getScore() << " and " << Player[1].getName() << " has " << Player[1].getScore() << ". " << Player[0].getName() << " wins ties." << endl;
					}
				}
			}
		}

		cout << endl << "Play again? (y) or (n): ";
		cin >> cont;
		cout << endl;
	}

	return 0;
}
