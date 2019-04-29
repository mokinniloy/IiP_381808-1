#include "Wagon.h"
#pragma once

class Train
{
	int type; /* 1 - Ласточка
				 2 - Фирменный
				 3 - Скорый */
	Wagon* wagons;
	int wagons_count;
	int wc_1, wc_2, wc_3, wc_4;
	int train_number;
public:
	Train();
	Train(int t, int tn);
	~Train();
	int get_wagon_count(int tp, int tw);
	int get_wagon_type(int n);
	int get_wagon_place_count(int n);
	bool get_wagon_place(int n, int day, int pl);
	int get_wagon_price(int n);
	void reserve(int n, int day, int pl);
	int get_train_number();
};