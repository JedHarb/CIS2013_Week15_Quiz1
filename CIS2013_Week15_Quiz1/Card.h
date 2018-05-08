//#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card {
private:
	string name;
	string suit;
	int value;
	bool isUsed;

public:

	Card();
	Card(string n, string s, int v, bool u);
	~Card();

	void setName(string);
	string getName();

	void setSuit(string);
	string getSuit();

	void setValue(int);
	int getValue();

	void setUsed(bool);
	bool getUsed();
};