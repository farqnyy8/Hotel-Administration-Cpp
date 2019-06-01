#include"Card.h"

Card::Card()
{
 number="";
 deposit=0;
}
Card::Card(string number, double deposit)
{
 this->number=number;
 this->deposit=deposit;
}
void Card::deposit_money(double x)
{
 deposit=deposit+x;
}
void Card::withdraw_money(double x)
{
 deposit=deposit-x;
}

istream& operator >> (istream& inn, Card& card)
{
	cout << "Enter Card Number: ";
	inn >> card.number;
	
	cout << "Enter Card Deposit: $";
	inn >> card.deposit;
	
	return inn;
}

ostream& operator << (ostream& out, Card& card)
{
	if(card.deposit >= 100 )
		out << "Good Deposit" << endl;
	else
		out << "Bad Deposit" << endl;

	return out;
}
