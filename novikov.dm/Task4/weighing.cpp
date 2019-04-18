#include <string>
#include <iostream>
#include "weighing.h" 

weighing::weighing()
{
	day = month = year = weight = 0;
}
weighing::weighing(string _n, int _d, int _m, int _y, double _w)
{
	name = _n;
	day = _d;
	month = _m;
	year = _y;
	weight = _w;
}
void weighing::set_name(string _n)
{
	name = _n;
}

void weighing::set_date(int _d, int _m, int _y)
{
	day = _d;
	month = _m;
	year = _y;
}

void weighing::set_weight(double _w)
{
	weight = _w;
}

istream& operator>>(istream& stream, weighing &obj)
{
	stream >> obj.name >> obj.day >> obj.month >> obj.year >> obj.weight;
	return stream;
}

ostream& operator<<(ostream& stream, const weighing &obj)
{
	stream << obj.name << " " << obj.day << " " << obj.month << " " << obj.year << " " << obj.weight;
	return stream;
}