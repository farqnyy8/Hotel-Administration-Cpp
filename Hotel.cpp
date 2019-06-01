
#include "Hotel.h"

//non member functions
int num_of_empty_rooms(Room rooms[], int& num_of_rooms)
{
	int num = 0;
	for(int i = 0; i < num_of_rooms; i++)
	{
		if(rooms[i].get_occupied() == false)
			num++;
	}
	return num;
}

void print_all_less_busy_cleaner(vector<Cleaner>& cleaners)
{
	cout << endl << "List of less busy cleaners" << endl;
	bool check = false;
	for(int i = 0; i < cleaners.size(); i++)
	{
		if(cleaners[i].get_working() == false)
			cout << "\t" << cleaners[i].get_name() << " " << i+1 << endl;
		else 
			check = true;
	}
	if(check == true)
		cout << "All cleaners are currently working" << endl;
}

void print_all_dirty_room(Room rooms[], int& size)
{
	cout << endl << "List of dirty rooms" << endl;
	bool check = false;

	for(int i = 0; i < size; i++)
	{
		if(rooms[i].get_cleaned() == false)
			cout << "\t" << rooms[i].get_number() + 1 << endl;
		else 
			check = true;
	}
	if(check == true)
		cout << "No dirty room"<< endl;
}

int search_customer(vector<Customer>& customers, string& name)
{
	//return -1 if you don't find
	for(int i = 0; i < customers.size(); i++)
	{
		if(customers[i].get_name() == name)
			return i;
	}
	return -1;
}

int search_cleaner(vector<Cleaner>& cleaners, string& name)
{
	//return -1 if you don't find
	for(int i = 0; i < cleaners.size(); i++)
	{
		if(cleaners[i].get_name() == name)
			return i;
	}
	return -1;
}

void print_customer(vector<Customer>& customers, string& name)
{
	//print details after entering name or number 
	for(int i = 0; i < customers.size(); i++)
	{
		if(customers[i].get_name() == name)
		{
			cout << "\t" << customers[i].get_name() << " " << i + 1 << endl;
			return;
		}	
	}
}

void print_all_empty_rooms(Room rooms[], int& size)
{
	cout << endl << "List of all enpty rooms" << endl;
	bool check = false;
	//print all the rooms that is_booked() is false
	for(int i = 0; i < size; i++)
	{
		if(rooms[i].get_occupied() == false)
			cout << "\t" << rooms[i].get_number() + 1 << " ";
		else 
			check = true;
	}
	cout << endl;
	if(check == true)
		cout << "No empty room"<< endl;
}

void print_all_customers(vector<Customer>& customers)
{
	cout << endl << "List of all customers" << endl;
	for(int i = 0; i < customers.size(); i++)
		cout << "\t" << customers[i].get_name() << endl;
}

void print_all_cleaners(vector<Cleaner>& cleaners)
{
	cout << endl << "List of all cleaners" << endl;
	for(int i = 0; i < cleaners.size(); i++)
		cout << "\t" << cleaners[i].get_name() << endl;
}
//end of non-member functions


Hotel::Hotel()
{
	name = address = "empty";
	num_of_rooms = 15;
 	nonAc = 32.00;
  	classic = 48.00;
  	deLux = 132.00;

	for(int i = 0; i < num_of_rooms; i++)
	{
		rooms[i].set_number(i);
		if(i < 5)
		{
			rooms[i].set_type("NonAc");
			rooms[i].set_price(nonAc);
		}
		else if(i < 10)
		{
			rooms[i].set_type("Classic");
			rooms[i].set_price(classic);
		}
		else
		{
			rooms[i].set_type("DeLux");
			rooms[i].set_price(deLux);
		}
	}
  }

Hotel::Hotel(string name, string address)
{
	this->name = name;
	this->address = address;
	nonAc = 32.00;
  	classic = 48.00;
  	deLux = 132.00;

	for(int i = 0; i < num_of_rooms; i++)
	{
		rooms[i].set_number(i + 1);
		if(i < 5)
		{
			rooms[i].set_type("NonAc");
			rooms[i].set_price(nonAc);
		}
		else if(i < 10)
		{
			rooms[i].set_type("Classic");
			rooms[i].set_price(classic);
		}
		else
		{
			rooms[i].set_type("DeLux");
			rooms[i].set_price(deLux);
		}
	}
}

void Hotel::add_customer()
{
	if(customers.size() == 0)
	{
		//add
		Customer temp;
		cin >> temp;
		customers.push_back(temp);
	}
	else 
	{
		//enter customer name
		string temp_name;
		int findp = search_customer(customers, temp_name);
		
		if(findp == -1)
		{
			//add 
			Customer temp;
			cin >> temp;
			customers.push_back(temp);
		}
		else
		{
			//display customer already exists
			cout << temp_name << "already exist" << endl;
		}
	}
}

void Hotel::employ_cleaner()
{
	if(cleaners.size() == 0)
	{
		//add 
		Cleaner temp;
		cin >> temp;
		cleaners.push_back(temp);
	}
	else 
	{
		//enter cleaner name
		string temp_name;
		int find = search_cleaner(cleaners, temp_name);
		
		if(find == -1)
		{
			//add 
			Cleaner temp;
			cin >> temp;
			cleaners.push_back(temp);
		}
		else
		{
			//display cleaner already exists
			cout << temp_name << "already exist" << endl;
		}
	}	
}

void Hotel::fire_cleaner()
{
	if(cleaners.size() == 0)
	{
		//display no cleaner yet 
		cout  << "There is no cleaner yet" << endl;
	}
	else 
	{
		print_all_cleaners(cleaners);
		//enter cleaner name
		cin.ignore();
		string temp_name;
		cout << endl << "Enter Cleaner Name: ";
		getline(cin,temp_name);
		int find = search_cleaner(cleaners, temp_name);
		
		if(find == -1)
		{
			//display cleaner doesn't exists 
			cout << temp_name << "doesn't exist" << endl;
		}
		else
		{
			//fire cleaner
			cleaners.erase(cleaners.begin() + find);
		}
	}
}

void Hotel::check_in_customer()
{
	if(customers.size() == 0)
		cout << "There are no customers yet" << endl;
	else
	{
		print_all_customers(customers);
		//print customer info
		cin.ignore();
		string name;
		cout << "Enter Customer Name or Q to quit: ";
		getline(cin, name);
		int find = search_customer(customers, name);
	
		if(find == -1)
		{
			do{
				//loop until found or quit
				cout << "Enter Customer Name or Q to quit: ";
				getline(cin, name);
				find = search_customer(customers, name);
			}while((name != "Q" || name != "q") && find == -1);

			if(find > -1)
				cout << customers[find];
		}
		else
		{
			cout << customers[find];
		}
		//print all empty rooms
		cout << "Empty Rooms......." << endl;
		print_all_empty_rooms(rooms, num_of_rooms);
		//select room 
		int num;
		cout << "Enter the room number you want to book: ";
		cin >> num;
		num -= 1;
		//check if deposit is enough and assign room to customer
		if(customers[find].get_card().get_deposit() >= nonAc)
		{
			customers[find].set_room(num);
			rooms[num].set_occupied(true);
			customers[find].set_checked(true);
			customers[find].get_card().withdraw_money(rooms[num].get_price());
		}
		else
		{
			cout << "Insufficient funds!!!" << endl;
		}
	}
}

void Hotel::check_out_customer()
{
	if(customers.size() == 0)
	{
		cout << "There is no customer yet" << endl;
	}
	else
	{
		print_all_customers(customers);
		cin.ignore();
		//get customer name
		string name;
		cout << "Enter Customer Name or Q to quit: ";
		getline(cin, name);
		int find = search_customer(customers, name);
		//remove the customer from the room by setting rooms[customer[find].get_num()] to empty status
		if(find == -1)
		{
			//loop until found or quit
			cout << "Enter Customer Name or Q to quit: ";
			getline(cin, name);
			find = search_customer(customers, name);
		}
		else
		{
			if(customers[find].get_checked() == false)
				cout << "This customer is not checked in" << endl;
			else
			{
				customers[find].set_checked(false);
				rooms[customers[find].get_room()].set_occupied(false);
			}			
		}
	}
}

void Hotel::clean_room()
{
	//get room number
	print_all_dirty_room(rooms, num_of_rooms);
	cout << "Enter a room to be cleaned: ";
	int num; 
	cin >> num;
	num -= 1;

	//assign a cleaner to the room
	print_all_less_busy_cleaner(cleaners);
	int cnum;
	cout << "Choose cleaner: ";
	cin >> cnum; 
	cnum -= 1;
	//display stop_cleaning_room after some time
	cleaners[num].assign_Room(cnum);
	rooms[num].set_cleaned(true);
}

void Hotel::stop_cleaning_room()
{
	// set room to cleaned = true
	print_all_dirty_room(rooms, num_of_rooms);
	//stop cleaner from stop_cleaning_room - set isworking to false
	cout << "Enter the room you want to stop cleaning: ";
	int x;
	cin >> x;
	for(int i = 0; i < cleaners.size(); i++)
	{
		if(cleaners[i].get_room() == x)
			cleaners[i].remove_from_Room();
	}
	//set occupied to false
	rooms[x].set_occupied(false);
}


void Hotel::view_customer()
{
	if(customers.size() == 0)
		cout << "There are no customers yet" << endl;
	else
	{
		print_all_customers(customers);
		cin.ignore();
		string name;
		int find;
		do
		{
			cout<<"Enter customer name or Q to quit: ";
			getline(cin,name);
			find = search_customer(customers, name);

		}while(((name != "q") || (name != "Q")) && find == -1);	
	
    
		//display
		cout<<customers[find];
	}
}


void Hotel::view_room()
{
	int choice;
	//display rooms[get_num]
	cout<<"Enter Room number: ";
	cin >> choice;
	cout<<rooms[choice - 1];
}

void Hotel::view_cleaner()
{
	if(cleaners.size() == 0)
	{
		cout << "There are no cleaners yet" << endl;
	}
	else
	{
		print_all_cleaners(cleaners);
		//enter name
		//search name
		//display cleaners[find]
		cin.ignore();
		string name;
		int find;
		do
		{
			cout<<"Enter cleaner's name or Q to quit: ";
			getline(cin,name);
			find = search_cleaner(cleaners,name);
		}while (((name != "q") || (name != "Q")) && find == -1);	
	
    
		//display
		cout << cleaners[find];
	}

}

void Hotel::enter()
{
  cout <<"Enter Hotel Name: ";
  getline(cin, name);

  cout <<"Enter Hotel Address: ";
  getline(cin, address);

  cout << "Enter a password: ";
  cin >> password;
}

void Hotel::print()
{
	string x;
	cout << "Enter the password: ";
	cin >> x;

	if(x == password)
	{
		cout << "Number of empty rooms: " << num_of_empty_rooms(rooms, num_of_rooms) << endl;;
		cout << "Number of Cleaners: " << cleaners.size() << endl;
		cout << "Number of Customers: " << customers.size() << endl;
	}
	else 
	{
		cout << "You do not have authorized access to this information." << endl;
	}
}
