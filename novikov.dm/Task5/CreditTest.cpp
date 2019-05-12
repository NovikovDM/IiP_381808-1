#include<iostream>
#include<fstream>
#include <windows.h>
#include "ProcCenter.h"
using namespace std;

ProcCenter center;
void CrMenu(int cl, int d)
{//работа с кредитом
	int x;
	while (1)
	{
		system("cls");
		cout << center.arr[cl].Cr[d].name << endl;
		cout << "Kolichestvo sredstv  - " << center.arr[cl].Cr[d].GetMoney() << endl;
		cout << "1)Pogasit' nachisleniya po creditu\n";
		cout << "2)Dosrochno pogasit' credit\n";
		cout << "3)Nazad\n";
		cin >> x;
		switch (x)
		{
		case(1):
		{//pogashenie nachisleniya po creditu
			system("cls");
			double s = center.arr[cl].Cr[d].Procent();
			center.arr[cl].Money -= s;
			cout << "Sredstva perevedeni " << s << endl;
			getchar();
			getchar();
			break;
		}
		case(2)://dosrochnoe pogashenie credita
		{
			if (!center.arr[cl].Cr[d].op)
			{
				cout << "Schet" << center.arr[cl].Cr[d].name << " zakrit";
				center.arr[cl].Money -= center.arr[cl].Cr[d].GetMoney();
				center.arr[cl].Cr.erase(center.arr[cl].Cr.begin() + d);
				getchar();
				getchar();
				return;
			}
			else cout << "Schet ne mozhet bit' zakrit";
			getchar();
			getchar();
			break;
		}
		case(3):
		{
			return;
			break;
		}
		default:
			break;
		}
	}
}

void Menu2(int l)
{
	int n;
	while (1)
	{
		system("cls");
		cout << "Client - " << center.arr[l].Name << endl;
		cout << "1) Deneg na schete\n";
		cout << "2) Otkritie crediti\n";
		cout << "3) Noviy credit\n";
		cout << "0) nazad\n";
		cin >> n;
		switch (n)
		{
		case(1)://summa na schete
		{
			system("cls");
			cout << "Summa sredstv na schete - " << center.arr[l].Money;
			getchar();
			getchar();
			break;
		}
		case(2)://menu otkritih creditov
		{
			int i, m;
			system("cls");
			for (i = 0; i < center.arr[l].Cr.size(); i++)
				cout << i + 1 << ")" << center.arr[l].Cr[i].name << endl;
			cout << i + 1 << ") nazad\n";
			cout << "vibirite credit\n";
			cin >> m;
			if (m - 1 < center.arr[l].Cr.size())
				CrMenu(l, m - 1);
			break;
		}
		case(3):
		{//Sozdanie novogo credita
			int x;
			double y;
			system("cls");//vibrat' srok kredita
			cout << "1)Na 1 god\n";
			cout << "2)Na 2 goda\n";
			cout << "3)N 3 goda\n";
			cout << "4)На 5 let\n";
			cin >> x;
			if (!(x > 0 && x < 5)) {
				cout << "oshibka";
				break;
			}

			system("cls");//summa i procentnaya godovaya stavka
			cout << "Summa do 100000, procent - " << 5 + x * 0.2 << "%" << endl;
			if (center.arr[l].Money > 100000)
				cout << "Summa ot 100000 do 500000, procent - " << 5 + x * 0.4 << "%" << endl;
			if (center.arr[l].Money > 500000)
				cout << "Summa ot 500000 do 1000000, procent - " << 5 + x * 0.6 << "%" << endl;
			if (center.arr[l].Money > 1000000)
				cout << "Summa ot 1000000 do 3000000, procent - " << 5 + x * 0.8 << "%" << endl;
			cout << "Vvedite summu\n";
			cin >> y;
			if (y<0 || y>center.arr[l].Money)
			{
				cout << "Summa nekorrektna";
				break;
			}
			system("cls");
			string nam;
			cout << "vvedite nazvanie kredita\n";
			cin >> nam;
			center.arr[l].NewCr(nam, y, x);
			break;
		}
		case(0):
			return;
			break;
		default:
			break;
		}
	}
}

int main()
{
	int x;
	Data a1;
	center.st.day = 1;
	center.st.month = 1;
	center.st.year = 2000;
	center.ActualData();
	while (true)
	{
		system("cls");
		cout << "Data - " << center.st.day << "." << center.st.month << "." << center.st.year << endl;
		cout << "1) Sozdat' novogo pol'zovatelya\n";
		cout << "2) Voiti v akkaunt\n";
		cout << "3) Pereyti k date\n";
		cout << "0) Viyti\n";
		cin >> x;
		switch (x)
		{
		case(1):
		{//Sozdanie pol'zovatelya
			system("cls");
			string a, b;
			double m;
			int n;
			cout << "Vvedite imya pol'zovatelya\n";
			getline(cin, a);
			cout << "Pridumayte parol'\n";
			cin >> b;
			cout << "Vvedite nomer karti\n";
			cin >> n;
			cout << "Vvedite colichestvo deneg na karte\n";
			cin >> m;
			center.NewClient(n, a, b, m);
			break;
		}
		case(2):
		{//Vhod v akkaunt
			int a;
			string b1;
			system("cls");
			cout << "Vvesti nomer karti\n";
			cin >> a;
			cout << "Vvesti parol'\n";
			cin >> b1;
			int l = center.Login(a, b1);
			if (l < 0)
			{
				cout << "\nOshibka vhoda";
				getchar();
				getchar();
			}
			else Menu2(l);
			break;
		}
		case(3):
		{//Vvod novoi dati
			char a2;
			system("cls");
			cout << "Vvesti datu\n";
			cin >> a1.day >> a2 >> a1.month >> a2 >> a1.year;
			if (center.CorrectData(a1))
			{
				while (!(center.st == a1))
				{
					center.st.day++;
					center.ActualData();
					center.ActualCr();
				}
			}
			getchar();
			break;
		case(0):
			return 0;
		default:
			break;
		}
		}
		return 0;
	}
}