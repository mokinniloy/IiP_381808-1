#include "Train.h"

Train::Train() 
{
	type = 0;
	wagons_count = 0;
	wc_1 = wc_2 = wc_3 = wc_4 = 0;
	wagons = new Wagon[wagons_count];
	for (int i = 0; i < wagons_count; i++)
	{
		wagons[i] = Wagon();
	}
	train_number = 0;
}

Train::Train(int t, int tn) 
{
	type = t;
	wagons_count = 12;
	wc_1 = wc_2 = wc_3 = wc_4 = 0;
	wagons = new Wagon[wagons_count];
	for (int i = 0; i < wagons_count; i++)
	{
		wagons[i] = Wagon();
	}
	train_number = tn;
	switch (type) 
	{
	case 1:
		wc_1 = 12;
		for (int i = 0; i < wagons_count; i++) 
		{
			wagons[i] = Wagon(1, 100);
		}
		break;
	case 2:
		wc_2 = 4;
		wc_3 = 6;
		wc_4 = 2;
		for (int i = 0; i < wagons_count; i++) 
		{
			if (i < 2) wagons[i] = Wagon(4, 18);
			if (i >= 2 && i < 8) wagons[i] = Wagon(3, 36);
			if (i >= 8 && i < 12) wagons[i] = Wagon(2, 54);
		}
		break;
	case 3:
		wc_2 = 8;
		wc_3 = 4;
		for (int i = 0; i < wagons_count; i++) 
		{
			if (i < 4) wagons[i] = Wagon(3, 36);
			if (i >= 4 && i < 12) wagons[i] = Wagon(2, 54);
		}
		break;
	default:
		break;
	}
}

Train::~Train() 
{
}

int Train::get_wagon_count(int tp, int tw)
{
	switch (tp)
	{
	case 1:
		return wc_1;
	case 2:
		switch (tw)
		{
		case 2:
			return wc_2;
		case 3:
			return wc_3;
		case 4:
			return wc_4;
		default:
			break;
		}
	case 3:
		switch (tw)
		{
		case 2:
			return wc_2;
		case 3:
			return wc_3;
		default:
			break;
		}
	default:
		break;
	}
}

int Train::get_wagon_type(int n)
{
	return wagons[n].get_type();
}

int Train::get_wagon_place_count(int n)
{
	return wagons[n].get_place_count();
}

bool Train::get_wagon_place(int n, int day, int pl)
{
	return wagons[n].get_place(day, pl);
}

int Train::get_wagon_price(int n)
{
	return wagons[n].get_price();
}

void Train::reserve(int n, int day, int pl)
{
	wagons[n].reserve(day, pl);
}

int Train::get_train_number()
{
	return train_number;
}
