#include <string>
#include <iostream>
#include <string>
#include <iostream>
#include "weighing.h"
#include "FloorScales.h"
FloorScales::FloorScales() //konstruktor po umolchanyu
{
	count = size = 0;
	A = NULL;
	delta = 10;
}


FloorScales::FloorScales(int _size)//konstruktor inicializacii
{
	count = 0;
	delta = 10;
	size = _size;
	A = new weighing[size];
}


FloorScales::FloorScales(const FloorScales &obj) :size(obj.size), count(obj.count) //konstructor kopirovaniya
{
	A = new weighing[size];
	for (int i = 0; i < size; i++)
	{
		A[i] = obj.A[i];
	}
}


FloorScales::~FloorScales() //destruktor
{
	delete[]A;
	count = size = 0;
	A = NULL;
}

void FloorScales::add_weighing(weighing &obj) //dobavlenie vzveshivaniya
{
	if (count == size)
	{
		weighing *tmp;
		size += delta;
		tmp = new weighing[size];
		for (int i = 0; i < count; ++i)
		{
			tmp[i] = A[i];
			delete[]A;
			A = tmp;
		}

		A[count] = obj;
		count++;
	}
}

weighing FloorScales::get_first_weighing(string _n) //poisk pervogo vzveshivaniya cheloveka
{
	for (int i = 0; i < count; i++)
	{
		if (A[i].get_name() == _n)
			return A[i];
	}
	throw "Net nabludeniy";
}

double FloorScales::get_result_weighing(string _n, int _d, int _m, int _y) //poisk vesa po date i imeni
{
	for (int i = 0; i < count; i++)
	{
		if (A[i].get_name() == _n)
		{
			if ((A[i].get_day() == _d) && (A[i].get_month() == _m) && (A[i].get_year() == _y))
				return A[i].get_weight();
		}
	}
	throw "Net nabludeniy";
}

double FloorScales::get_min_weight(string _n) //min ves za vse vremya
{
	double min = 99999999;
	for (int i = 0; i < count; i++)
	{
		if (A[i].get_name() == _n)
		{
			if (A[i].get_weight() < min)
				min = A[i].get_weight();
		}
	}
	if (min == 99999999) throw "Net nabludeniy";
	return min;
}

double FloorScales::get_min_weight(string _n, int _m) //min ves za mesyac
{
	double min = 99999999;
	for (int i = 0; i < count; i++)
	{
		if ((A[i].get_name() == _n) && (A[i].get_month() == _m))
		{
			if (A[i].get_weight() < min)
				min = A[i].get_weight();
		}
	}
	if (min == 99999999) throw "Net nabludeniy v etom mesyace";
	return min;
}

double FloorScales::get_mid_weight(string _n) //sredniy ves za vse vremya
{
	double mid = 0;
	double counter = 0;
	for (int i = 0; i < count; i++)
	{
		if (A[i].get_name() == _n)
		{
			mid += A[i].get_weight();
			counter++;
		}
	}
	if (counter == 0) throw "Net nabludeniy";
	return mid / counter;
}

double FloorScales::get_mid_weight(string _n, int _m) //sredniy ves za mesyac
{
	double mid = 0;
	double counter = 0;
	for (int i = 0; i < count; i++)
	{
		if ((A[i].get_name() == _n) && (A[i].get_month() == _m))
		{
			mid += A[i].get_weight();
			counter++;
		}
	}
	if (counter == 0) throw "Net nabludeniy v etom mesyace";
	return mid / counter;
}

double FloorScales::get_max_weight(string _n) //max ves za vse vremya
{
	double max = 0;
	for (int i = 0; i < count; i++)
	{
		if (A[i].get_name() == _n)
		{
			if (A[i].get_weight() > max)
				max = A[i].get_weight();
		}
	}
	if (max == 0) throw "Net nabludeniy";
	return max;
}

double FloorScales::get_max_weight(string _n, int _m) //max ves za mesyac
{
	double max = 0;
	for (int i = 0; i < count; i++)
	{
		if ((A[i].get_name() == _n) && (A[i].get_month() == _m))
		{
			if (A[i].get_weight() > max)
				max = A[i].get_weight();
		}
	}
	if (max == 0) throw "Нет наблюдений за этот месяц";
	return max;
}



FloorScales& FloorScales::operator=(const FloorScales & obj) //operator prisvaivaniya
{
	if (this == &obj) return *this;
	if (size != obj.size)
	{
		delete[]A;
		size = obj.size;
		A = new weighing[size];
	}
	count = obj.count;
	for (int i = 0; i < size; i++)
	{
		A[i] = obj.A[i];
	}
	return *this;
}

istream& operator>>(istream &stream, FloorScales &obj) //vvod v potok
{
	stream >> obj.size >> obj.count;
	obj.A = new weighing[obj.size];
	for (int i = 0; i < obj.count; i++)
	{
		stream >> obj.A[i];
	}
	return stream;
}

ostream& operator<<(ostream &stream, const FloorScales &obj) //vivod v potok
{
	stream << obj.size << " " << obj.count << endl;
	for (int i = 0; i < obj.count; i++)
	{
		stream << obj.A[i] << endl;
	}
	return stream;
}
