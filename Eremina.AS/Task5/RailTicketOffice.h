#include "GorkyRailway.h"
#include "Train.h"
#include "Wagon.h"
#pragma once

class RailTicketOffice
{
	GorkyRailway GR;
public:
	RailTicketOffice();
	~RailTicketOffice();
	void buy_ticket();
	void free_places();
};

