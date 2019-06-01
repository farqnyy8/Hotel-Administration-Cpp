#ifndef HOTEL_H
#define HOTEL_H

#include "Customer.h"
#include "Cleaner.h"
#include "Room.h"

class Hotel{
	
	private:
		string name, address, password;
		int num_of_rooms;
		Room rooms[15];
		vector<Customer> customers;
		vector<Cleaner> cleaners;
		double nonAc, classic, deLux;
		
	public:
		Hotel();
		Hotel(string name, string address);
		void add_customer();
		void employ_cleaner();
		void fire_cleaner();
		void check_in_customer();
		void check_out_customer();
		void clean_room();
		void stop_cleaning_room();
		void view_customer();
		void view_room();
		void view_cleaner();
		void enter();
		void print();
};

#endif
