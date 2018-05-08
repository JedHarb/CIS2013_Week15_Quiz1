#include "Card.h"
using namespace std;

Card::Card() : name("A"), suit("Spades"), value(1), isUsed(false) {
	
}

Card::Card(string n, string s, int v, bool u) {
	name = n;
	suit = s;
	value = v;
	isUsed = u;
}

Card::~Card() {
	//leaving empty
}

void Card::setName(string n) {
	name = n;
}

string Card::getName() {
	return name;
}

void Card::setSuit(string s) {
	suit = s;
}

string Card::getSuit() {
	return suit;
}

void Card::setValue(int v) {
	value = v;
}

int Card::getValue() {
	return value;
}

void Card::setUsed(bool u) {
	isUsed = u;
}

bool Card::getUsed() {
	return isUsed;
}

void Card::setCard(int i, string c) {
	deck[i] = c;
}

string Card::getCard(int i) {
	return deck[i];
}
