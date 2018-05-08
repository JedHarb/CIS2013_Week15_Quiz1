#include "Player.cpp"
#include "Card.cpp"

//Behavior
//
//Game starts, a name is selected for the player.
//UI
//
//2 players and 52 cards are created.
//Game asked for the name of the non - dealer.
//Main will issue 2 cards to a dealer, and 2 cards to the player who
//Blackjack is then played


int main() {
	string name;
	Player Player;
	Card Card;

	//generate a deck
	for (int i = 0; i < 13; i++) {
		switch (i) {
		case 0: 
			Card.setName("Ace");
			Card.setValue(1);
			break;
		case 1:
			Card.setName("2");
			Card.setValue(2);
			break;
		case 2:
			Card.setName("3");
			Card.setValue(3);
			break;
		case 3:
			Card.setName("4");
			Card.setValue(4);
			break;
		case 4:
			Card.setName("5");
			Card.setValue(5);
			break;
		case 5:
			Card.setName("6");
			Card.setValue(6);
			break;
		case 6:
			Card.setName("7");
			Card.setValue(7);
			break;
		case 7:
			Card.setName("8");
			Card.setValue(8);
			break;
		case 8:
			Card.setName("9");
			Card.setValue(9);
			break;
		case 9:
			Card.setName("10");
			Card.setValue(10);
			break;
		case 10:
			Card.setName("Jack");
			Card.setValue(10);
			break;
		case 11:
			Card.setName("Queen");
			Card.setValue(10);
			break;
		case 12:
			Card.setName("King");
			Card.setValue(10);
			break;
		default:
			cout << "You shouldn't see this...";
		}
		for (int j = 0; j < 4; j++) {
			switch (j) {
			case 1:
				Card.setSuit("-of-Spades");
				break;
			case 2:
				Card.setSuit("-of-Clubs");
				break;
			case 3:
				Card.setSuit("-of-Hearts");
				break;
			case 4:
				Card.setSuit("-of-Diamonds");
				break;
			default:
				cout << "You shouldn't see this either...";
			}
			for (int k = 0; k < 52; k++) {
				Card.setCard(k, Card.getName + Card.getSuit);
			}
		}
	}

	cout << "Welcome to Blackjack. What is your name? ";
	cin >> name;
	Player.setName(name);
	cout << "Okay, " << Player.getName() << " you have "; //cards



	return 0;
}