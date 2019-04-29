#pragma once

class Wagon 
{
	int type;  /* 1 - Сидячий
				  2 - Плацкартный
				  3 - Купейный
				  4 - СВ */
	int place_count;
	int place_price;
	bool** places;
public:
	Wagon();
	Wagon(int t, int pc);
	~Wagon();
	int get_type();  // Узнать тип вагона
	int get_place_count();  // Узнать общее кол-во мест
	bool get_place(int day, int pl);  // Обратиться к месту
	int get_price();  // Узнать цену
	void reserve(int day, int pl);  // Купить место
};