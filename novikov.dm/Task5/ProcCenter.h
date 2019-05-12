#pragma once
#include <string>
#include <vector>
#include "Credit.h"
using namespace std;

class Client
{
public:
	int num;//nomer karti
	string Name;//imya clienta
	string Password;//parol'
	vector<Credit> Cr;//spisok vseh creditov
	double Money;//kolichestvo vseh deneg na karte klienta
	void NewCr(string n, double m, int d);//funkciya dobavleniya novogo credita
};
class ProcCenter
{
public:
	vector<Client> arr;//spisok clientov
	void ActualData();//rabota s datami
	void ActualCr();//obnovlenie creditov v sootvetstvii s datoi
	bool CorrectData(Data a);//correktorovka dat(perevod mesyacev v godi, dnei v mesyaci)
	Data st;//actual'naya data 
	int Login(int num, string password);//vhod pol'zovatelya
	void NewClient(int n, string name, string password, double money);//dobavlenie clienta
	ProcCenter();
	~ProcCenter();
};

