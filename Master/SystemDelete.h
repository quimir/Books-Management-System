#pragma once


#ifndef _SystemDelete_H
#define _SystemDelete_H
#include "add.h"


class SystemDelete :protected SystemAdd
{
public:
	SystemDelete() :SystemAdd(bookTemp, periodicalTemp) {}
	int chooseBookOrPeriodical()const;
	bool bookDelete(System*,SystemAdd*);
	bool periodicalDelete(System*,SystemAdd*);
};
#endif