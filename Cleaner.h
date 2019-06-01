#ifndef CLEANER_H
#define CLEANER_H

#include <fstream>
#include "Person.h"
#include "Room.h"

class Cleaner: public Person{

	private:
		//data fields
		bool working;
		Room c_room;
	
	public:
		//constructor
		Cleaner();
		bool get_working();
		void assign_Room(int num);
		void remove_from_Room();
		friend istream& operator >> (istream& inn, Cleaner& clean);
		friend ostream& operator << (ostream& out, Cleaner& clean);
};

#endif
