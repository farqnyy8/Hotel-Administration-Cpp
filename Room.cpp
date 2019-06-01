//inclusion guard
#ifndef PERSON_H
#define PERSON_H

//libraries
#include <iostream>
#include <string>
#include <vector>

//std namespace
using namespace std;

class Person{

  protected:
    //data fields
    string name, address, phone, email; 
    static short id_gen;
    short id_num, room_num;
  
  public:
    //constructor
    Person();

    //accessors
    string get_name() const;
    short get_id() const;
    string get_phone() const;
    string get_email() const;
	int get_room() const {return room_num;}

    //mutators
    void set_name(string& nName);
    void set_phone(string& nPhone);
    void set_email(string& nEmail);
	void set_room(int n) {room_num = n;}

    //others
    void enter();
    void print();
};

#endif
