#include "RailTicketOffice.h"
#include <iostream>
#include <locale.h>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "RUS");
	RailTicketOffice RTO;
	int point;
	cout << "������������ ��� � ��������������� ����� ����������� �������� ������!\n"
		"1 - ������ �����\n"
		"2 - ������ � ������� ��������� ����\n"
		"0 - �����\n";
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
			cout << "�� ��������!";
			exit(0);
		default:
			break;
		}
	}
}