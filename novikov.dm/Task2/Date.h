#pragma once
#include <string>
#include <exception>
#include <iostream>

using namespace std;

class Date
{
private:
	short day, month, year;

public:
	enum Month
	{
		January = 1, February, March,
		April, May, June,
		July, August, September,
		October, November, December
	};

	//konstruktor
	Date() : day(1), month(1), year(1)
	{}
	//vozmozhnost' vvesti mesyac po raznomu
	Date(short day, Month month, short year);
	Date(short day, short month, short year);

	//destructor
	~Date();

	//Getters
	short Get_day() const { return day; } //vozvrashaet den'
	short Get_month() const { return month; } //vozvrashaet mesyac
	short Get_year() const { return year; } //vozvrashaet god


public:
	void Changing(short day, short month, short year);
	long long ofDays() const;

	//Operatori
	Date operator+(const  Date & other) const; //slozhenie
	Date operator-(const  Date & other) const; //vichitanie

	friend ostream & operator<< (ostream& out, const Date & date);
	friend istream & operator>> (istream& in, Date & date);




	// proverka korrektnosti dat
	string is_right(short day, short month, short year) const;
	bool is_year_leap(int year) const;
	unsigned char CountOfDays(short month, short year) const;
	string toString() const;
};
