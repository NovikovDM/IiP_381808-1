#include "ProcCenter.h"
Data s;
void ProcCenter::ActualData()

{
	if (st.month == 1 || st.month == 3 || st.month == 5 || st.month == 7 || st.month == 8 || st.month == 10 || st.month == 12) {
		if (st.day == 32)
		{
			st.day = 1;
			st.month++;
			if (st.month == 13)
			{
				st.year++;
				st.month = 1;
			}
		}
	}

	else if (st.month == 4 || st.month == 6 || st.month == 9 || st.month == 11)
	{
		if (st.day == 31)
		{
			st.day = 1;
			st.month++;
		}
	}
	else if (!st.year % 4)
	{
		if (st.day == 30)
		{
			st.day = 1;
			st.month++;
		}
	}
	else if (st.day == 29)
	{
		st.day = 1;
		st.month++;
	}
	s.day = st.day;
	s.month = st.month;
	s.year = st.year;
}


void ProcCenter::ActualCr()
{
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < arr[i].Cr.size(); j++)
		{
			arr[i].Cr[j].Actual(st);
		}
}

bool ProcCenter::CorrectData(Data a)
{
	if (a.year < st.year)
		return false;
	else if (a.month < st.month&&a.year == st.year)
		return false;
	else if (a.day < st.day&&a.month == st.month&&a.year == st.year)
		return false;
	if (a.month > 12)
		return false;
	if (st.month == 1 || st.month == 3 || st.month == 5 || st.month == 7 || st.month == 8 || st.month == 10 || st.month == 12)
	{
		if (st.day > 31)
		{
			return false;
		}
	}
	else if (st.month == 4 || st.month == 6 || st.month == 9 || st.month == 11)
	{
		if (st.day > 30)
		{
			return false;
		}
	}
	else if (!st.year % 4)
	{
		if (st.day > 29)
		{
			return false;
		}
	}
	else if (st.day > 28)
	{
		return false;
	}
	return true;
}

int ProcCenter::Login(int num, string password)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].num == num)
			if (arr[i].Password == password)
				return i;
			else
				return -1;
	}
	return -1;
}

void ProcCenter::NewClient(int n, string name, string password, double money)
{
	Client c1;
	c1.Money = money;
	c1.Name = name;
	c1.Password = password;
	c1.num = n;
	arr.push_back(c1);
}

ProcCenter::ProcCenter()
{

}

ProcCenter::~ProcCenter()
{

}


void Client::NewCr(string n, double m, int d)
{
	Credit a;
	a.name = n;
	a.Recomend(m, d, s);
	a.SetMoney(m);
	Cr.push_back(a);
}