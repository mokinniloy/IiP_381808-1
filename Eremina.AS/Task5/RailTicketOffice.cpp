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

	cout << "���� (1-5): ";
	cin >> day;
	if (day >= 1 && day <= 5)
	{
		cout << "����� ������ (101-106 - ��������, 201-202 - ���������, 301-302 - ��������): ";
		cin >> number;
		if (number >= 101 && number <= 106)
		{
			trtype = 1;
			cout << "��� ������ (1 - �������): ";
			cin >> vgtype;
			if (vgtype == 1)
			{
				cout << "���-�� ���� (1-100): ";
				cin >> count;
				if (count < 1 || count > 100)
				{
					cout << "��������, �� �� ����� ������������ ������� ����." << endl;
					return;
				}
			}
			else
			{
				cout << "��������, ������ ������ ���." << endl;
				return;
			}
		}
		else if (number >= 201 && number <= 202)
		{
			trtype = 2;
			cout << "��� ������ (2 - �����������, 3 - ��������, 4 - ��): ";
			cin >> vgtype;
			if (vgtype == 2)
			{
				cout << "���-�� ���� (1-54): ";
				cin >> count;
				if (count < 1 || count > 54)
				{
					cout << "��������, �� �� ����� ������������ ������� ����." << endl;
					return;
				}
			}
			else if (vgtype == 3)
			{
				cout << "���-�� ���� (1-36): ";
				cin >> count;
				if (count < 1 || count > 36)
				{
					cout << "��������, �� �� ����� ������������ ������� ����." << endl;
					return;
				}
			}
			else if (vgtype == 4)
			{
				cout << "���-�� ���� (1-18): ";
				cin >> count;
				if (count < 1 || count > 18)
				{
					cout << "��������, �� �� ����� ������������ ������� ����." << endl;
					return;
				}
			}
			else
			{
				cout << "��������, ������ ������ ���." << endl;
				return;
			}
		}
		else if (number >= 301 && number <= 302)
		{
			trtype = 3;
			cout << "��� ������ (2 - �����������, 3 - ��������): ";
			cin >> vgtype;
			if (vgtype == 2)
			{
				cout << "���-�� ���� (1-54): ";
				cin >> count;
				if (count < 1 || count > 54)
				{
					cout << "��������, �� �� ����� ������������ ������� ����." << endl;
					return;
				}
			}
			else if (vgtype == 3)
			{
				cout << "���-�� ���� (1-36): ";
				cin >> count;
				if (count < 1 || count > 36)
				{
					cout << "��������, �� �� ����� ������������ ������� ����." << endl;
					return;
				}
			}
			else
			{
				cout << "��������, ������ ������ ���." << endl;
				return;
			}
		}
	}
	else
	{
		cout << "��������, �� �� ������ ������ �� ���� ����." << endl;
		return;
	}

	int* buy = new int[2 + count];
	buy = GR.buy_ticket(day, number, vgtype, count, trtype);
	if (buy[0] == -1) 
	{
		cout << "������ �����" << endl;
		return;
	}
	cout << "_______________________________________" << endl;
	cout << "����: " << day << "\n"
		"����� ������: " << number << "\n"
		"����� ������: " << buy[0] << "\n"
		"�����: ";
	for (int i = 2; i < count+2; i++) cout << buy[i] << " ";
	cout << "\n����� �����: " << buy[1] << endl;
	cout << "_______________________________________" << endl;
}

void RailTicketOffice::free_places()
{
	int day = 0, number = 0, vgtype = 0, count = 0, trtype = 0;

	cout << "���� (1-5): ";
	cin >> day;
	if (day >= 1 && day <= 5)
	{
		cout << "����� ������ (101-106 - ��������, 201-202 - ���������, 301-302 - ��������): ";
		cin >> number;
		if (number >= 101 && number <= 106)
		{
			trtype = 1;
			cout << "��� ������ (1 - �������): ";
			cin >> vgtype;
			if (vgtype == 1)
			{
				GR.free_places(day, number, 1);
			}
			else
			{
				cout << "��������, ������ ������ ���." << endl;
				return;
			}
		}
		else if (number >= 201 && number <= 202)
		{
			trtype = 2;
			cout << "��� ������ (2 - �����������, 3 - ��������, 4 - ��): ";
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
				cout << "��������, ������ ������ ���." << endl;
				return;
			}
		}
		else if (number >= 301 && number <= 302)
		{
			trtype = 3;
			cout << "��� ������ (2 - �����������, 3 - ��������): ";
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
				cout << "��������, ������ ������ ���." << endl;
				return;
			}
		}
	}
	else
	{
		cout << "��������, �� �� ������ ������ �� ���� ����." << endl;
		return;
	}
}
