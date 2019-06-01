//Header file

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Room{
	string name, type; 
	int number;  
	bool occupied;
	bool cleaned;
	double price;
	
	public:
	
	Room();
	Room(string name, int number);
	friend istream& operator >> (istream& inn, Room& room);
	friend ostream& operator << (ostream& out, Room& room);
	bool get_occupied() const {return occupied;}
	bool get_cleaned() {return cleaned;}
	void set_occupied(bool x);
	void set_cleaned(bool x);
	void set_price(double x) {price = x;}
	double get_price() {return price;}
	int get_number() const {return number;}
	void set_number(int x) {number = x;}
	void set_type(string x) {type = x;}
	string get_type() const {return type;}
};

#endif
