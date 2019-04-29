#include "RailTicketOffice.h"
#include <iostream>
#include <locale.h>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "RUS");
	RailTicketOffice RTO;
	int point;
	cout << "Приветствуем вас в Железнодорожной кассе Горьковской железной дороги!\n"
		"1 - Купить билет\n"
		"2 - Узнать о наличии свободных мест\n"
		"0 - Выход\n";
	for (;;)
	{
		cout << ">>> ";
		cin >> point;
		switch (point)
		{
		case 1:
			RTO.buy_ticket();
			break;
		case 2:
			RTO.free_places();
			break;
		case 0:
			cout << "До свидания!";
			exit(0);
		default:
			break;
		}
	}
}