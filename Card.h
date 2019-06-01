//Card.CARD_H

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
	private:
 		string number;
 		double deposit;

	public:
 		Card();
 		Card(string,double);
 		void deposit_money(double);
 		void withdraw_money(double);
		double get_deposit() const {return deposit;}
 		friend istream& operator >> (istream& inn, Card& card);
 		friend ostream& operator << (ostream& out, Card& card);
};

#endif
