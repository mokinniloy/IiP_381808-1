#include "RailTicketOffice.h"
#include "GorkyRailway.h"
#include "Train.h"
#include "Wagon.h"
#include <iostream>
using namespace std;

RailTicketOffice::RailTicketOffice()
{
}


RailTicketOffice::~RailTicketOffice()
{
}

void RailTicketOffice::buy_ticket()
{
	int day = 0, number = 0, vgtype = 0, count = 0, trtype = 0;

	cout << "День (1-5): ";
	cin >> day;
	if (day >= 1 && day <= 5)
	{
		cout << "Номер поезда (101-106 - Ласточка, 201-202 - Фирменный, 301-302 - Экспресс): ";
		cin >> number;
		if (number >= 101 && number <= 106)
		{
			trtype = 1;
			cout << "Тип вагона (1 - Сидячий): ";
			cin >> vgtype;
			if (vgtype == 1)
			{
				cout << "Кол-во мест (1-100): ";
				cin >> count;
				if (count < 1 || count > 100)
				{
					cout << "Извините, мы не можем предоставить столько мест." << endl;
					return;
				}
			}
			else
			{
				cout << "Извините, такого вагона нет." << endl;
				return;
			}
		}
		else if (number >= 201 && number <= 202)
		{
			trtype = 2;
			cout << "Тип вагона (2 - Плацкартный, 3 - Купейный, 4 - СВ): ";
			cin >> vgtype;
			if (vgtype == 2)
			{
				cout << "Кол-во мест (1-54): ";
				cin >> count;
				if (count < 1 || count > 54)
				{
					cout << "Извините, мы не можем предоставить столько мест." << endl;
					return;
				}
			}
			else if (vgtype == 3)
			{
				cout << "Кол-во мест (1-36): ";
				cin >> count;
				if (count < 1 || count > 36)
				{
					cout << "Извините, мы не можем предоставить столько мест." << endl;
					return;
				}
			}
			else if (vgtype == 4)
			{
				cout << "Кол-во мест (1-18): ";
				cin >> count;
				if (count < 1 || count > 18)
				{
					cout << "Извините, мы не можем предоставить столько мест." << endl;
					return;
				}
			}
			else
			{
				cout << "Извините, такого вагона нет." << endl;
				return;
			}
		}
		else if (number >= 301 && number <= 302)
		{
			trtype = 3;
			cout << "Тип вагона (2 - Плацкартный, 3 - Купейный): ";
			cin >> vgtype;
			if (vgtype == 2)
			{
				cout << "Кол-во мест (1-54): ";
				cin >> count;
				if (count < 1 || count > 54)
				{
					cout << "Извините, мы не можем предоставить столько мест." << endl;
					return;
				}
			}
			else if (vgtype == 3)
			{
				cout << "Кол-во мест (1-36): ";
				cin >> count;
				if (count < 1 || count > 36)
				{
					cout << "Извините, мы не можем предоставить столько мест." << endl;
					return;
				}
			}
			else
			{
				cout << "Извините, такого вагона нет." << endl;
				return;
			}
		}
	}
	else
	{
		cout << "Извините, мы не продаём билеты на этот день." << endl;
		return;
	}

	int* buy = new int[2 + count];
	buy = GR.buy_ticket(day, number, vgtype, count, trtype);
	if (buy[0] == -1) 
	{
		cout << "Ошибка ввода" << endl;
		return;
	}
	cout << "_______________________________________" << endl;
	cout << "День: " << day << "\n"
		"Номер поезда: " << number << "\n"
		"Номер вагона: " << buy[0] << "\n"
		"Места: ";
	for (int i = 2; i < count+2; i++) cout << buy[i] << " ";
	cout << "\nОбщая сумма: " << buy[1] << endl;
	cout << "_______________________________________" << endl;
}

void RailTicketOffice::free_places()
{
	int day = 0, number = 0, vgtype = 0, count = 0, trtype = 0;

	cout << "День (1-5): ";
	cin >> day;
	if (day >= 1 && day <= 5)
	{
		cout << "Номер поезда (101-106 - Ласточка, 201-202 - Фирменный, 301-302 - Экспресс): ";
		cin >> number;
		if (number >= 101 && number <= 106)
		{
			trtype = 1;
			cout << "Тип вагона (1 - Сидячий): ";
			cin >> vgtype;
			if (vgtype == 1)
			{
				GR.free_places(day, number, 1);
			}
			else
			{
				cout << "Извините, такого вагона нет." << endl;
				return;
			}
		}
		else if (number >= 201 && number <= 202)
		{
			trtype = 2;
			cout << "Тип вагона (2 - Плацкартный, 3 - Купейный, 4 - СВ): ";
			cin >> vgtype;
			if (vgtype == 2)
			{
				GR.free_places(day, number, 2);
			}
			else if (vgtype == 3)
			{
				GR.free_places(day, number, 3);
			}
			else if (vgtype == 4)
			{
				GR.free_places(day, number, 4);
			}
			else
			{
				cout << "Извините, такого вагона нет." << endl;
				return;
			}
		}
		else if (number >= 301 && number <= 302)
		{
			trtype = 3;
			cout << "Тип вагона (2 - Плацкартный, 3 - Купейный): ";
			cin >> vgtype;
			if (vgtype == 2)
			{
				GR.free_places(day, number, 2);
			}
			else if (vgtype == 3)
			{
				GR.free_places(day, number, 3);
			}
			else
			{
				cout << "Извините, такого вагона нет." << endl;
				return;
			}
		}
	}
	else
	{
		cout << "Извините, мы не продаём билеты на этот день." << endl;
		return;
	}
}
