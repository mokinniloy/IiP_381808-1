#include "Wagon.h"

Wagon::Wagon()
{
	type = 0;
	place_count = 0;
	place_price = 0;
	places = new bool* [5];
	for (int i = 0; i < 5; i++) 
	{
		places[i] = new bool[place_count];
	}
}

Wagon::Wagon(int t, int pc) 
{
	type = t;
	place_count = pc;
	place_price = 0;
	switch (t) 
	{
	case 1:
		place_price = 1200;
		break;
	case 2:
		place_price = 1400;
		break;
	case 3:
		place_price = 1750;
		break;
	case 4:
		place_price = 2000;
		break;
	default:
		break;
	}
	places = new bool* [5];
	for (int i = 0; i < 5; i++) 
	{
		places[i] = new bool[place_count];
		places[i] = { false };
	}
}

Wagon::~Wagon() 
{
	place_price = 0;
	for (int i = 0; i < 5; i++) 
	{
		delete places[i];
	}
	delete[] places;
	type = 0;
	place_count = 0;
}

int Wagon::get_type()
{
	return type;
}

int Wagon::get_place_count()
{
	return place_count;
}

bool Wagon::get_place(int day, int pl)
{
	return places[day-1][pl];
}

int Wagon::get_price()
{
	return place_price;
}

void Wagon::reserve(int day, int pl)
{
	places[day - 1][pl] = true;
}
