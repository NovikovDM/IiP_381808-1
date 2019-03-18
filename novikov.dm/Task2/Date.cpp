#include "Date.h"

//konstuktor
Date::Date(short day, Month month, short year)
{
	Changing(day, month, year);
}

//konstructor
Date::Date(short day, short month, short year)
{
	Changing(day, month, year);
}

//destructor
Date::~Date()
{
}

//proverka korrectnosti dat
string Date::is_right(short day, short month, short year) const
{
	if (year <= 0)
	{
		return "Incorrect year: it must be > 0!";
	}

	if (month < 1 || month > 12)
	{
		return "Incorrect month: it must be >= 1 and <= 12!";
	}

	short count = CountOfDays(month, year); //kolichestvo dney 
	if (day < 1 || day > count)
	{
		return "Incorrect day: it must be >= 1 and <= " + to_string(count) + " in " + to_string(month) + "this month!";
	}

	return "";
}

//opredelenie visokosnih godov
bool Date::is_year_leap(int year) const
{
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}


void Date::Changing(short day, short month, short year)
{
	string result = is_right(day, month, year);
	if (result != "")
	{
		throw exception(result.c_str());
	}

	this->day = day;
	this->month = month;
	this->year = year;

}

//formirovanie dati (den'.mesyac.god)
string Date::toString() const
{
	return to_string(day) + "." + to_string(month) + "." + to_string(year);
}


long long Date::ofDays() const
{
	long long result = 0;
	for (int i = 1; i <= year; ++i)
	{
		if (is_year_leap(i))
		{
			result += 365;
		}
		else
		{
			result += 366;
		}
	}

	for (int i = 1; i <= month; ++i)
	{
		result += CountOfDays(i, year);
	}

	result += day;
	return result;
}

//opredelenie dnya, mesyaca, goda (slozhenie)
Date Date::operator+(const Date &other) const
{
	short new_year = this->year + other.year;

	short new_month = this->month + other.month;
	if (new_month > 12)
	{
		++new_year;
		new_month -= 12;
	}

	short count = CountOfDays(month, new_year);
	short new_day = this->day + other.day;
	if (new_day > count)
	{
		++new_month;
		if (new_month > 12)
		{
			new_month -= 12;
			++new_year;
		}
		new_day -= count;

	}

	return Date(new_day, new_month, new_year);
}

//opredelenie dnya, mesyaca, goda (vichitanie)
Date Date::operator-(const Date & other) const
{
	short new_year = this->year - other.year;

	short new_month = this->month - other.month;
	if (this->month <= other.month)
	{
		new_month += 12;
		--new_year;
	}

	short new_day = this->day - other.day;
	if (this->day <= other.day)
	{
		--new_month;
		if (new_month == 0)
		{
			--new_year;
			new_month = 12;
		}
		new_day += CountOfDays(new_month, new_year);
	}

	string result = is_right(new_day, new_month, new_year);
	if (result != "")
	{
		throw exception("It's impossible to substract more from the less");
	}

	return Date(new_day, new_month, new_year);
}

//kolichestvo dney v mesyacah
unsigned char Date::CountOfDays(short month, short year) const
{
	switch (month)
	{
	case January:
	case March:
	case July:
	case August:
	case October:
	case December:
		return 31;

	case April:
	case June:
	case September:
	case November:
		return 30;

	case February:
		return (is_year_leap(year) ? 29 : 28);
	}
}

//vivod
ostream & operator<<(ostream & out, const Date & date)
{
	out << date.toString();
	return out;
}

//vvod
istream & operator>>(istream & in, Date & date)
{
	char razdelitel = '.';
	short tmp_day, tmp_month;
	in >> tmp_day >> razdelitel >> tmp_month >> razdelitel >> date.year;
	date.day = tmp_day;
	date.month = tmp_month;
	return in;
}