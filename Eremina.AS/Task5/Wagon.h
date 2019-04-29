#pragma once

class Wagon 
{
	int type;  /* 1 - �������
				  2 - �����������
				  3 - ��������
				  4 - �� */
	int place_count;
	int place_price;
	bool** places;
public:
	Wagon();
	Wagon(int t, int pc);
	~Wagon();
	int get_type();  // ������ ��� ������
	int get_place_count();  // ������ ����� ���-�� ����
	bool get_place(int day, int pl);  // ���������� � �����
	int get_price();  // ������ ����
	void reserve(int day, int pl);  // ������ �����
};