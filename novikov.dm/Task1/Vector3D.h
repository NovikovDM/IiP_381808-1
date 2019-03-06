#pragma once
#include <iostream>
using namespace std;

class Vector3D
{
public:
	Vector3D(void); //konstruktor klassa po umolchaniyu
	Vector3D(const Vector3D&); //konstruktor copirovaniya
	Vector3D(double _x, double _y, double _z); //konstruktor initsializacii
	~Vector3D(); //destructor po umolchaniyu
	Vector3D& operator= (const Vector3D& v);//peregruzka operacii prisvaivaniya
	Vector3D operator+(const Vector3D& v);//peregruzka operacii slozheniya
	Vector3D operator-(const Vector3D& v);//peregruzka operacii vichitaniya
	double operator*(const Vector3D& v);//peregruzka operacii skalyarnogo proizvedenia vektorov 
	friend Vector3D operator*(double l, const Vector3D& v);//peregruzka operacii umnozhenie na skalyar
	bool operator==(const Vector3D& v);//peregruzka operacii sravnenya vektorov po dline
	bool operator!=(const Vector3D& v);//peregruzka operacii sravnenya vektorov po dline
	bool operator>(const Vector3D& v);//peregruzka operacii sravnenya vektorov po dline
	bool operator<(const Vector3D& v);//peregruzka operacii sravnenya vektorov po dline
	friend istream& operator>>(istream& stream, Vector3D& v);//peregruzka operacii vvoda 
	friend ostream& operator<<(ostream& stream, const Vector3D& v);//peregruzka operacii vivoda


private:
	double x, y, z; //koordinati vektora v 3-hmernom prostranstve
	double length; //dlina vektora
};
Vector3D operator*(double l, const Vector3D& v);
ostream& operator<<(ostream& stream, const Vector3D& v);
istream& operator>>(istream& stream, Vector3D& v);