#include "Calendar.h"

//konstruktor
Calendar::Calendar()
{
	dates = new Date[beginSize];
	events = new string[beginSize];
	currentSize = 0;
	maxSize = beginSize;
}

//konstruktor s odnim sobitiem
Calendar::Calendar(Date date, string name_event) : Calendar()
{
	dates[currentSize] = date;
	events[currentSize] = name_event;
	currentSize = 1;
}

//konstruktor dlya mesyaca cifroy
Calendar::Calendar(short day, short month, short year, string name_event)
	: Calendar(Date(day, month, year), name_event)
{}

//konstruktor dlya mesyaca slovom
Calendar::Calendar(short day, Date::Month month, short year, string name_event)
	: Calendar(Date(day, month, year), name_event)
{}

Calendar::Calendar(const Calendar & other)
{
	maxSize = other.maxSize;
	currentSize = other.currentSize;
	dates = new Date[maxSize];
	events = new string[maxSize];

	for (int i = 0; i < currentSize; ++i)
	{
		dates[i] = other.dates[i];
		events[i] = other.events[i];
	}
}

//destruktor
Calendar::~Calendar()
{
	clear();
}

//sozdanie sobitiya, proverka sushestvovaniya
void Calendar::CreateEvent(Date date, string name_event)
{
	if (does_event_create(name_event) != nullptr)
	{
		throw exception("This event is already there");
	}

	if (currentSize == maxSize)
	{
		Increase_max_size();
	}

	dates[currentSize] = date;
	events[currentSize] = name_event;
	++currentSize;
}

//proverka sushestvovaniya
const Date & Calendar::DateOfEvent(string name_event)
{
	Date* result = does_event_create(name_event);
	if (result == nullptr)
	{
		throw exception("No such event");
	}

	return *result;
}


long long Calendar::difference(Date date, string name_event)
{
	Date* result = does_event_create(name_event);
	if (result == nullptr)
	{
		throw exception("No such event");
	}

	return date.ofDays() - result->ofDays();
}

//perenos sobitiy nazad
void Calendar::perenos_date_backward(string name_event, Date shift)
{
	Date* result = does_event_create(name_event);
	if (result == nullptr)
	{
		throw exception("Can't shift event date: event does not create!");
	}

	*result = *result - shift;
}

//perenos sobitiy vpered
void Calendar::perenos_date_forward(string name_event, Date shift)
{
	Date* result = does_event_create(name_event);
	if (result == nullptr)
	{
		throw exception("Can't shift event date: event does not create!");
	}

	*result = *result + shift;


}

Calendar & Calendar::operator=(const Calendar & other)
{
	if (this == &other)
	{
		return *this;
	}

	clear();
	maxSize = other.maxSize;
	currentSize = other.currentSize;
	dates = new Date[maxSize];
	events = new string[maxSize];

	for (int i = 0; i < currentSize; ++i)
	{
		dates[i] = other.dates[i];
		events[i] = other.events[i];
	}

	return *this;
}

void Calendar::Increase_max_size()
{
	maxSize *= 1.5;
	Date* newDates = new Date[maxSize];
	string* newEvents = new string[maxSize];

	for (int i = 0; i < currentSize; ++i)
	{
		newDates[i] = dates[i];
		newEvents[i] = events[i];
	}

	clear();
	dates = newDates;
	events = newEvents;
}

//ochistka
void Calendar::clear()
{
	delete[] dates;
	delete[] events;
}


Date * Calendar::does_event_create(string name_event)
{
	for (int i = 0; i < currentSize; ++i)
	{
		if (events[i] == name_event)
		{
			return &dates[i];
		}
	}
	return nullptr;
}

//vvod
istream & operator>>(istream & in, Calendar & calendar)
{
	calendar.clear();
	in >> calendar.currentSize;
	calendar.dates = new Date[calendar.currentSize];
	calendar.events = new string[calendar.currentSize];
	calendar.maxSize = calendar.currentSize;
	for (int i = 0; i < calendar.currentSize; ++i)
	{
		int event_size;
		in >> calendar.dates[i] >> event_size;
		char event_name[100];
		in.getline(event_name, event_size + 2);
		calendar.events[i] = event_name;
		calendar.events[i].erase(calendar.events[i].begin());
	}
	return in;
}

//vivod
ostream & operator<<(ostream & out, const Calendar & calendar)
{
	//output format:
	//size
	//date1 event_name_size1 event_name1
	//date2 event_name_size2 event_name2
	//....
	//dateSize event_name_sizeSize event_nameSize
	out << calendar.currentSize << endl;
	for (int i = 0; i < calendar.currentSize; ++i)
	{
		out << calendar.dates[i] << " " << calendar.events[i].size() << " " << calendar.events[i] << endl;
	}
	return out;
}