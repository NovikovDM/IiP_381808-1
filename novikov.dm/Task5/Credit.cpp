#include "Credit.h"
void Credit::Recomend(double a, int b, Data x)
{
	percent = 0.1;
	if (a < 100000)
	{
		e.day = x.day;
		e.month = x.month;
		e.year = x.year + 1;
		percent += 0.02;
	}
	else if (a < 500000)
	{
		e.day = x.day;
		e.month = x.month;
		e.year = x.year + 2;
		percent += 0.035;
	}
	else if (a < 1000000)
	{
		e.day = x.day;
		e.month = x.month;
		e.year = x.year + 3;
		percent += 0.05;
	}
	else
	{
		e.day = x.day;
		e.month = x.month;
		e.year = x.year + 5;
		percent += 0.08;
	}
	switch (b)
	{
	case(1):
		percent += 0.02;
		break;
	case(2):
		percent += 0.035;
		break;
	case(3):
		percent += 0.05;
		break;
	case(4):
		percent += 0.08;
		break;
	default:
		break;
	}
}



void Credit::Actual(Data a)
{
	count++;
	if (op) {
		if (a.day == 1) {
			money = money + (St_money * percent*count / 365);
			count = 0;
		}
	}
	if (e.day == a.day&&e.month == a.month&&e.year == a.year) {
		money = money + (St_money * percent*count / 365);
		count = 0;
		op = false;
	}
}

Data::Data()
{
	day = 0;
	month = 0;
	year = 0;
}

Data::~Data()
{
	day = 0;
	month = 0;
	year = 0;

}




Credit::Credit()
{

}

Credit::~Credit()
{

}

bool Data::operator==(const Data &a)
{
	if (this->day == a.day&&month == a.month&&year == a.year)
		return true;
	else
		return false;
}
