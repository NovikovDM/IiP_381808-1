#pragma once
#include <string>
#include <locale>
#include <iostream>
#include <algorithm>
#include "Integrals.h"

using namespace std;


Integrals::Integrals()//Konstruktor po umolchaniyu
{
	double a = b = in = 0;
	int n = 1;
}

Integrals::Integrals(double _a, double _b, int _n, double _in)//Konstruktor inicializacii
{
	a = _a;
	b = _b;
	n = _n;
	in = _in;
}


Integrals::Integrals(const Integrals &_c)//Konstruktor kopirovaniya
{
	a = _c.a;
	b = _c.b;
	n = _c.n;
	in = _c.in;
}

Integrals::~Integrals()//Destructor
{
	a = b = n = in = 0;
}


std::istream& operator>>(std::istream & stream, Integrals & c)//Vvod v potok
{
	stream >> c.a >> c.b >> c.n;
	return stream;
}

ostream & operator << (ostream & stream, const Integrals & c)//Vivod v potok
{
	stream << c.in << endl;
	return stream;
}


Integrals Integrals::RightRectangle(double f(double x), const Integrals & c)	//Metod pravih pryamougolnikov
{
	double x, sh;
	Integrals sum;
	sh = (c.b - c.a) / c.n;  //razbivaem na ravnie otrezki (shagi)
	for (int i = 1; i <= c.n; i++)
	{
		x = c.a + i * sh;
		sum.in = sum.in + f(x);
	}
	sum.in = sum.in * sh;
	return sum;
}


Integrals Integrals::LeftRectangle(double f(double x), const Integrals & c)	//Metod levih pryamougolnikov
{
	double x, sh;
	Integrals sum;
	sh = (c.b - c.a) / c.n;  //razbivaem na ravnie otrezki (shagi)
	for (int i = 0; i < c.n; i++)
	{
		x = c.a + i * sh;
		sum.in = sum.in + f(x);
	}
	sum.in = sum.in * sh;
	return sum;
}


Integrals Integrals::MiddleRectangle(double f(double x), const Integrals & c)	////Metod srednih pryamougolnikov
{
	double x, sh;
	Integrals sum;
	sh = (c.b - c.a) / c.n;  //razbivaem na ravnie otrezki (shagi)
	for (int i = 1; i <= c.n; i++)
	{
		x = c.a + (i  * sh / 2);
		sum.in = sum.in + f(x);
	}
	sum.in = sum.in * sh;
	return sum;
}