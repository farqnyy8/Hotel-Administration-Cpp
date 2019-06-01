
#include "Cleaner.h"

Cleaner::Cleaner()
{
	working = false;
}
bool Cleaner::get_working()
{
	return working;
}

void Cleaner::assign_Room(int num)
{
	set_room(num);
}
void Cleaner::remove_from_Room()
{
	set_room(-1);
}

istream& operator >> (istream& inn, Cleaner& clean)
{
	clean.enter();

	return inn;
}

ostream& operator << (ostream& out, Cleaner& clean)
{
	clean.print();

	return out;
}
