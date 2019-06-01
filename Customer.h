#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>
#include "Person.h"

#include "Card.h"
#include "Room.h"

using namespace std;

class Customer: public Person{

	private:
		Card card;
		Room room;
		bool is_checked;
	
	public:
		Customer();
		Card get_card() {return card;}
		bool get_checked() const {return is_checked;}
		void set_checked(bool x);
		friend ostream& operator << (ostream& out, Customer& customer);
		friend istream& operator >> (istream& inn, Customer& customer);
	
};

#endif
