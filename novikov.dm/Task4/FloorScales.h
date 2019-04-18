#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "weighing.h"
using namespace std;

class FloorScales
{
private:
	int size, count, delta;
public:
	weighing *A;
	FloorScales();//konstruktor po umolchanyu
	FloorScales(int _size);//konstruktor inicializacii
	FloorScales(const FloorScales &obj);//konstructor kopirovaniya
	~FloorScales();//destruktor
	void add_weighing(weighing &obj);//dobavlenie vzveshivaniya
	weighing get_first_weighing(string _n);//poisk pervogo vzveshivaniya cheloveka
	double get_result_weighing(string _n, int _d, int _m, int _y);//poisk vesa po date i imeni
	double get_min_weight(string _n);//min ves za vse vremya
	double get_min_weight(string _n, int _m);//min ves za mesyac
	double get_mid_weight(string _n);//sredniy ves za vse vremya
	double get_mid_weight(string _n, int _m);//sredniy ves za mesyac
	double get_max_weight(string _n);//max ves za vse vremya
	double get_max_weight(string _n, int _m);//max ves za mesyac
	FloorScales& operator=(const FloorScales &obj);//operator prisvaivaniya
	friend istream& operator>>(istream &stream, FloorScales &obj);//vvod v potok
	friend ostream& operator<<(ostream &stream, const FloorScales &obj);//vivod v potok
};