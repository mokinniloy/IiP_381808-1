#include "GorkyRailway.h"
#include "Train.h"
#include "Wagon.h"
#include <iostream>
using namespace std;

GorkyRailway::GorkyRailway()
{
	trains_count = 10;
	train_list = new Train[trains_count];
	train_list[0] = Train(1, 101);
	train_list[1] = Train(1, 102);
	train_list[2] = Train(1, 103);
	train_list[3] = Train(1, 104);
	train_list[4] = Train(1, 105);
	train_list[5] = Train(1, 106);
	train_list[6] = Train(2, 201);
	train_list[7] = Train(2, 202);
	train_list[8] = Train(3, 301);
	train_list[9] = Train(3, 302);
}

GorkyRailway::~GorkyRailway()
{
}

int* GorkyRailway::buy_ticket(int day, int number, int vgtype, int count, int trtype)
{
	switch (number)
		{
			case 101:
				return reserve_place(day, 0, vgtype, count, trtype);
			case 102:
				return reserve_place(day, 1, vgtype, count, trtype);
			case 103:
				return reserve_place(day, 2, vgtype, count, trtype);
			case 104:
				return reserve_place(day, 3, vgtype, count, trtype);
			case 105:
				return reserve_place(day, 4, vgtype, count, trtype);
			case 106:
				return reserve_place(day, 5, vgtype, count, trtype);
			case 201:
				return reserve_place(day, 6, vgtype, count, trtype);
			case 202:
				return reserve_place(day, 7, vgtype, count, trtype);
			case 301:
				return reserve_place(day, 8, vgtype, count, trtype);
			case 302:
				return reserve_place(day, 9, vgtype, count, trtype);
			default:
				int* ret = new int[1];
				ret[0] = -1;
				return ret;
		}
}

int* GorkyRailway::reserve_place(int day, int number, int vgtype, int count, int trtype)
{
	for (int u = 0; u < 12; u++) 
	{
		if (train_list[number].get_wagon_type(u) == vgtype)
		{
			int tmp = 0;
			int* pls = new int[count];
			for (int i = 0; ((i < train_list[number].get_wagon_place_count(u)) && (tmp < count)); i++)
			{
				if (train_list[number].get_wagon_place(u, day, i) == false)
				{
					pls[tmp] = i;
					tmp++;
				}
			}
			int prc = 0;
			if (tmp == count)
			{
				for (int i = 0; i < tmp; i++)
				{
					train_list[number].reserve(u, day, pls[i]);
					prc += train_list[number].get_wagon_price(u);
				}

				int* ret = new int[2 + count];
				ret[0] = u+1;
				ret[1] = prc;
				for (int y = 0; y < count; y++) ret[2 + y] = pls[y];
				return ret;
			}
			else
			{
				int* ret = new int[1];
				ret[0] = -1;
				return ret;
			}
		}
	}
	int* ret = new int[1];
	ret[0] = -1;
	return ret;
}

void GorkyRailway::free_places(int day, int number, int vgtype)
{
	for (int i = 0; i < 10; i++)
	{
		if (train_list[i].get_train_number() == number)
		{
			for (int j = 0; j < 12; j++)
			{
				if (train_list[i].get_wagon_type(j) == vgtype)
				{
					cout << "Вагон " << j+1 << ": ";
					for (int u = 0; u < train_list[i].get_wagon_place_count(j); u++)
					{
						if (train_list[i].get_wagon_place(j, day, u) == false)
						{
							cout << u << " ";
						}
					}
					cout << endl;
				}
			}
		}
	}
}
