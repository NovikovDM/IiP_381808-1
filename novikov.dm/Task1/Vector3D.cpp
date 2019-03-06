#include "Vector3D.h"
#include <math.h>
#include <iostream>

//konstruktor klassa po umolchaniyu
Vector3D::Vector3D()
{
	double x = y = z = 0.0;
	double length = 0.0;
}

//konstruktor copirovaniya
Vector3D::Vector3D(const Vector3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	length = v.length;
}

//konstruktor initsializacii
Vector3D::Vector3D(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
	length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

//destructor
Vector3D::~Vector3D()
{
	x = y = z = length = 0;
}

//peregruzka operacii prisvaivaniya
Vector3D& Vector3D::operator=(const Vector3D& v)
{
	(*this).x = v.x;
	(*this).y = v.y;
	(*this).z = v.z;
	(*this).length = v.length;
	return (*this);
}

//peregruzka operacii slozheniya
Vector3D Vector3D::operator+(const Vector3D& v)
{
	Vector3D res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	res.length = sqrt(pow(res.x, 2) + pow(res.y, 2) + pow(res.z, 2));
	return res;
}

//peregruzka operacii vichitaniya
Vector3D Vector3D::operator-(const Vector3D& v)
{
	Vector3D res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	res.length = sqrt(pow(res.x, 2) + pow(res.y, 2) + pow(res.z, 2));
	return res;
}

//peregruzka operacii skalyarnogo proizvedenia vektorov
double Vector3D::operator*(const Vector3D& v)
{
	double scalar;
	scalar = (*this).x*v.x + (*this).y*v.y + (*this).z*v.z;
	return scalar;
}

//peregruzka operacii umnozhenie na skalyar
Vector3D operator*(double l, const Vector3D& v)
{
	Vector3D res;
	res.x = l * v.x;
	res.y = l * v.y;
	res.z = l * v.z;
	res.length = sqrt(pow(res.x, 2) + pow(res.y, 2) + pow(res.z, 2));
	return res;
}

//peregruzka operacii sravnenya vektorov po dline 
bool Vector3D::operator==(const Vector3D& v)
{
	if ((*this).length == v.length)
		return true;
	else
		return false;
}

//peregruzka operacii sravnenya vektorov po dline
bool Vector3D::operator!=(const Vector3D& v)
{
	if ((*this).length != v.length)
		return true;
	else
		return false;
}

//peregruzka operacii sravnenya vektorov po dline
bool Vector3D::operator> (const Vector3D& v)
{
	if ((*this).length > v.length)
		return true;
	else
		return false;
}

//peregruzka operacii sravnenya vektorov po dline
bool Vector3D::operator< (const Vector3D& v)
{
	if ((*this).length < v.length)
		return true;
	else
		return false;
}

//peregruzka operacii vvoda
istream& operator>>(istream& stream, Vector3D& v) {

	stream >> v.x >> v.y >> v.z >> v.length;

	return stream;

}

//peregruzka operacii vivoda
ostream& operator<<(ostream& stream, const Vector3D& v) {

	stream << " X = " << v.x << " Y = " << v.y << " Z = " << v.z << "\nДлина вектора = " << v.length << endl;

	return stream;

}