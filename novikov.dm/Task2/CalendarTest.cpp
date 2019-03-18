#include <string>
#include <iostream>
#include <fstream>
#include "Calendar.h"
#include <vector>
#include <algorithm>


void DateClassTest();
void CalendarClassTest();
void PrintBorder()//granica
{
	cout << endl << "-----------------------------------------------------------------" << endl << endl;
}
void IncorrectDateTest(short day, short month, short year); //proverka opredeleniya nekorrektnoy dati

int main()
{
	DateClassTest();
	PrintBorder();
	CalendarClassTest();


	return 0;
}

void DateClassTest()
{
	cout << "------------DATE CLASS TEST----------------" << endl;
	//proverka construktorov
	cout << "Constructors test" << endl;
	Date date1;
	cout << "date1: " << date1 << endl;
	Date date2(20, 10, 30);
	cout << "date2: " << date2 << endl;
	Date date3(10, Date::March, 8);
	cout << "date3: " << date3 << endl;

	PrintBorder();

	//proverka razlichnih dat
	cout << "Attempts to create incorrect dates" << endl;
	IncorrectDateTest(0, 1, 2000); // Den' = 0 - incorrect
	IncorrectDateTest(1, 10, 1000); // Den' > 0 - correct
	IncorrectDateTest(-1, 10, 1000); // Den' < 0 - incorrect
	IncorrectDateTest(33, 1, 2000); // Den' > 31 - incorrect
	IncorrectDateTest(31, 1, 2000); // Den' = 31 - correct
	IncorrectDateTest(30, 2, 2000); // Den' > 29 - incorrect
	IncorrectDateTest(29, 2, 2000); // Den' = 29 - correct
	IncorrectDateTest(29, 2, 2011); // Den' > 28 - incorrect
	IncorrectDateTest(28, 2, 2011); // Den' = 28 - correct
	IncorrectDateTest(31, 11, 2012); // Den' > 30 - incorrect
	IncorrectDateTest(30, 11, 2012); // Den' = 30 - correct
	IncorrectDateTest(10, 10, 0); // God = 0 - incorrect
	IncorrectDateTest(10, 0, 1000); // mesyac = 0 - incorrect
	IncorrectDateTest(10, -1, 1000); // mesyac <1 - incorrect
	IncorrectDateTest(10, 13, 1000); // Mesyac > 12 - incorrect 

	PrintBorder();
	PrintBorder();



	//Proverka vvoda
	cout << "Input test" << endl;
	Date date4;
	cout << "Enter date4(format day.month.year) : ";
	cin >> date4;
	cout << endl << "date4 = " << date4 << endl;

	PrintBorder();
}

void IncorrectDateTest(short day, short month, short year)
{
	try
	{
		Date incorrect_date(day, month, year);
		cout << incorrect_date << "correct" << endl;
	}
	catch (const exception & ex)
	{
		cout << "date(" << day << ", " << month <<
			", " << year << ") can't be created: " << endl << ex.what() << endl << endl;
	}
}


void CalendarClassTest()
{
	cout << "----------------CALENDAR CLASS TEST---------------------" << endl;

	//proverka konstruktorov
	Calendar calendar1;
	Calendar calendar2(Date(1, 1, 1), "new year");
	Calendar calendar3(1, 1, 1, "new year");
	Calendar calendar4(calendar1);

	//proverka metodov
	cout << "Methods test--------------------------------------------" << endl << endl;

	calendar1.CreateEvent(Date(1, 2, 1), "event");
	cout << "Date of event " << calendar1.DateOfEvent("event") << endl;
	cout << "Attempt to add the same event twice" << endl; //popitka dobavit' sobitie dvazhdi
	try
	{
		calendar1.CreateEvent(Date(1, 2, 1), "event");
		cout << "Date of event " << calendar1.DateOfEvent("event") << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	cout << "The difference between " << Date(12, 7, 205) << " and " << calendar1.DateOfEvent("event") <<
		" = " << calendar1.difference(Date(12, 17, 205), "event") << " days" << endl;

	//perenos
	cout << "Shift date test" << endl;
	cout << calendar1.DateOfEvent("event") << " shift forward on 10.11.12 : ";
	calendar1.perenos_date_forward("event", Date(10, 11, 12));
	cout << "event date " << calendar1.DateOfEvent("event") << endl;
	cout << calendar1.DateOfEvent("event") << " shift backward on 10.10.10 : ";
	calendar1.perenos_date_backward("event", Date(10, 11, 12));
	cout << "event date is " << calendar1.DateOfEvent("event") << endl;

	PrintBorder();

	//proverka vvoda - vivoda
	cout << "Input/output test" << endl;
	ifstream in("input.txt");
	in >> calendar1;
	cout << "calendar1:" << endl << calendar1;
	in >> calendar2;
	cout << "calendar2:" << endl << calendar2;


}