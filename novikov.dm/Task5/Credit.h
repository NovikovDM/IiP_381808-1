#pragma once
#include <string>
using namespace std;

class Data {
public:
	int day;
	int month;
	int year;
	bool operator==(const Data &);
	Data();
	~Data();
};


class Credit
{
	Data e;//konec sroka kredita
	int count = 0;//kolichestvo dney s proshlogo zachisleniya viplat po creditu
	double money;//kolichestvo deneg kotorie ostalos viplatit'
	double St_money;//summa kredita
	double percent;//procent deneg za god
public:
	string name;//nazvaniye scheta
	bool op;
	void Recomend(double a, int b, Data x);//funkciya opredelyaushaya procentnuyu stavku
	double Procent();//funkciya spisaniya sredstv
	void Actual(Data a);//funkciya nachisleniya procentov po kreditu
	void SetMoney(double a) { money = St_money = a; }//nachal'naya summa
	double GetMoney() { return money; }//teckushee kolichestvo sredstv
	Credit();
	~Credit();
};
