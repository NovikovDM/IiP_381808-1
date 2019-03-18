#pragma once
#include "Date.h"
#include <string>
#include <exception>

using namespace std;

class Calendar
{
public:
	//konstruktor
	Calendar();
	//kalendar s odnim sobitiem
	Calendar(Date date, string name_event);
	Calendar(short day, short month, short year, string name_event);
	Calendar(short day, Date::Month month, short year, string name_event);
	Calendar(const Calendar& other);

	//destructor
	~Calendar();

	//Getter
	size_t Get_events_count() { return currentSize; } //vozvrashaet kolichestvo sobitiy

	//Metodi
	void CreateEvent(Date date, string name_event);
	const Date& DateOfEvent(string name_event);
	long long difference(Date date, string name_event);
	void perenos_date_forward(string name_event, Date shift);
	void perenos_date_backward(string name_event, Date shift);

	//Operatori
	Calendar & operator= (const Calendar & other);

	friend istream & operator>> (istream & in, Calendar & calendar);
	friend ostream & operator<< (ostream & out, const Calendar & calendar);
private:

	Date* dates;
	string* events;
	size_t currentSize, maxSize;


	void Increase_max_size();
	void clear();
	const int beginSize = 10;
	Date* does_event_create(string name_event);
};
