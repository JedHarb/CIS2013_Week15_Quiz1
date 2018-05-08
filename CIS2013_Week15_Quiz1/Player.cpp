#include "Player.h"
using namespace std;

Player::Player() : hand(), name("Jared"), stay(false) {
	//Player(2);
}

Player::Player(string h, string n, bool s) {
	//hand = h;
	name = n;
	stay = s;
}

Player::~Player() {

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

