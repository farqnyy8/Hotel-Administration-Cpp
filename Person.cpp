//including the header file
#include "Person.h"

//initialising static variable
short Person::id_gen = 1000;

Person::Person()
{
  name = address = phone = email = "empty.";
  //id_num is generated by adding one to the former id_gen. id_gen starts at 1000 by choice
  id_num = ++id_gen;
  room_num = -1;
}

string Person::get_name() const
{
  return name;
}

short Person::get_id() const
{
  return id_num;
}

string Person::get_phone() const
{
  return phone;
}

string Person::get_email() const
{
  return email;
}

void Person::set_name(string& nName)
{
  name = nName;
}

void Person::set_phone(string& nPhone)
{
  phone = nPhone;
}

void Person::set_email(string& nEmail)
{
  email = nEmail;
}

void Person::enter()
{
  cin.ignore();
  cout << "Enter Name: ";
  getline(cin, name);

  cout << "Enter Address: ";
  getline(cin, address);

  cout << "Enter Phone: ";
  cin >> phone;

  cout << "Enter Email: ";
  cin >> email;
  cin.ignore();
}

void Person::print()
{
  cout << "Name: " << name << endl;
  cout << "ID Number: " << id_num << endl;
  cout << "Address: " << address << endl;
  cout << "Phone: " << phone << endl;
  cout << "Email: " << email << endl;
}