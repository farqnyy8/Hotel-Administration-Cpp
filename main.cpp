//include header file for hotel class
#include "Hotel.h"

//function declarations
int display();
void action(Hotel& hot, short& num);

//main function
int main() 
{
	Hotel hot;
	hot.enter();

	short x = display();

	do
	{
		if(x >=1 && x <=12)
			action(hot, x); //carry out action
		else if(x == 0)
			return 0; //end Program 

		//system("cls");
		x = display(); //call display function
 
	}while(x != 0 || x == -1); 

	return 0;
}

//display function
int display()
{
	string p;
	short choice;

	cout << endl << endl << "1. Register a Customer." << endl;
	cout << "2. Employ a Cleaner" << endl;
	cout << "3. Fire a Cleaner" << endl;
	cout << "4. Customer Check-in" << endl;
	cout << "5. Customer Check-out" << endl; 
	cout << "6. Room Service" << endl;
	cout << "7. Complete Room Service" << endl;
	cout << "8. View Customer Details" << endl;
	cout << "9. View Cleaner Details" << endl;
	cout << "10. View Room Details" << endl;
	cout << "11. View Stats" << endl;
	cout << "12. Quit Program" << endl;

	cout << endl << "Enter choice of action: ";
	cin >> p;

	if(p.size() > 1)
	{
		choice = int(p[0]) - int('0');
		choice *= 10;
		choice += int(p[1]) - int('0');
	}
	else if (p.size() == 1)
	{
		choice = int(p[0]) - int('0');
	}

	//return part
	if((isalpha(p[0])))
	{
		cout << "Invalid Input!!!" << endl;
		return 13;
	}
	else if( (p.size() > 1) && isalpha(p[1]) )
	{
		cout << "Invalid Input!!!" << endl;
		return 13;
	}
	else if(choice == 12)
	{
		string sure;
		cout << "Are you sure you want to quit (Y or anything else): ";
		cin >> sure;

		if(sure == "Y" || sure == "y")
		{
			cout << "Bye...." << endl;
			return 0;
		}
		else
		{
			cout << "Continue....." << endl;
			return -1;
		}
	}
	else if(choice < 1 || choice > 12)
	{
		cout << "Invalid Input!!!" << endl;
		return 13;
	}
	return choice;
}

//action function
void action(Hotel& hot, short& num)
{

	cout << endl << endl << "********************************************" << endl;

	switch(num)
	{
		case 1: cout << "Customer Registration. " << endl; hot.add_customer(); break;
		case 2: cout << "Cleaner Employment." << endl; hot.employ_cleaner(); break;
		case 3: cout << "Cleaner Employment Termination. " << endl; hot.fire_cleaner(); break;
		case 4: cout << "Check-in Customer. " << endl; hot.check_in_customer(); break;
		case 5: cout << "Check-out Customer. " << endl; hot.check_out_customer(); break;
		case 6: cout << "Clean Room." << endl; hot.clean_room(); break;
		case 7: cout << "Stop Cleaning Room." << endl; hot.stop_cleaning_room(); break;
		case 8: cout << "View Customer Details." << endl; hot.view_customer(); break;
		case 9: cout << "View Cleaner Details." << endl; hot.view_cleaner(); break;
		case 10: cout << "View Room Details." << endl; hot.view_room(); break;
		case 11: cout << "Stats." << endl; hot.print(); break;
	}

	cout << "********************************************" << endl;

}
