#include "Player.h"
using namespace std;

Player::Player() : hand(), name("Jared"), stay(false) {
	Player(2);
}

Player::Player(int len, string h, string n, bool s) {
	hand = new string[len];
	name = n;
	stay = s;
}

Player::~Player() {
	delete[] hand;
}

void Player::setHand(string h) {
	hand = h;
}

string Player::getHand() {
	return hand;
}

void Player::setName(string n) {
	name = n;
}

string Player::getName() {
	return name;
}

void Player::setStay(bool u) {
	stay = u;
}

bool Player::getStay() {
	return stay;
}


//Behavior
//
//Game starts, a name is selected for the player.
//UI
//
//2 players and 52 cards are created.
//Game asked for the name of the non - dealer.
//Main will issue 2 cards to a dealer, and 2 cards to the player who
//Blackjack is then played
