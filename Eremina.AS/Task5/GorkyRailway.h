#include "Train.h"
#include "Wagon.h"
#pragma once

class GorkyRailway
{
	int trains_count;
	Train* train_list;
public:
	GorkyRailway();
	~GorkyRailway();
	int* buy_ticket(int day, int number, int vgtype, int count, int trtype);
	int* reserve_place(int day, int number, int vgtype, int count, int trtype);
	void free_places(int day, int number, int vgtype);
};

