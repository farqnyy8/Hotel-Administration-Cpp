#include "Customer.h"

Customer::Customer()
{
	is_checked = false;
}

ostream& operator << (ostream& out, Customer& customer)
{
	customer.print();
	out<<"Check-in status: "<< customer.is_checked << endl;
	return out;
}

istream& operator >> (istream& inn, Customer& customer)
{
	customer.enter();
	Card ncard;
	inn >> ncard;
	customer.card = ncard;
	return inn;
}

void Customer::set_checked(bool x)
{
	is_checked = x;

	if(is_checked == true)
		cout << name << " has been checked in" << endl;
	else 
		cout << name << " has been checked out" << endl;
}

