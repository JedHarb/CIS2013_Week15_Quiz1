#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
	string hand[12];
	string name;
	bool stay;

public:
	Player();
	Player(string h, string n, bool s);
	~Player();

	void setHand(string);
	string getHand();

	void setName(string);
	string getName();

	void setStay(bool);
	bool getStay();
};