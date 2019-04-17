#include <string>
#include <fstream>
#include <iostream>
#include "weighing.h"
#include "cstdlib"
#include "floorscales.h"
#include <Windows.h>
int main()
{
	FloorScales fs;
	int choise = 0;
	do
	{
		system("cls");
		cout << " 0. Zagruzka is faila." << endl;
		cout << " 1. Zagruzka v fail." << endl;
		cout << " 2. Pervoe nabludenie." << endl;
		cout << " 3. Dobavit' novoe nabludenie." << endl;
		cout << " 4. Pokazat' ves cheloveka v opredelennuyu datu." << endl;
		cout << " 5. Minimal'niy ves za vse vremya." << endl;
		cout << " 6. Minimal'niy ves za mesyac." << endl;
		cout << " 7. Sredniy ves za vse vremya." << endl;
		cout << " 8. Sredniy ves za mesyac." << endl;
		cout << " 9. Naibol'shiy ves za vse vremya." << endl;
		cout << "10. Naibol'shiy ves za mesyac." << endl;
		cout << "11. Konec raboti." << endl << endl;
		cout << "Vibirite deistvie : ";
		cin >> choise;

		try
		{
			switch (choise)
			{
			case 0:
			{
				string path;
				ifstream fcin;
				system("cls");
				cout << "VVedite put' do faila dlya zagruzki: ";
				cin >> path;
				fcin.open(path);
				cout << "nachalo zagruzki" << endl;
				fcin >> fs;
				fcin.close();
				cout << "konec zagruzki" << endl;
				system("pause");
				break;
			}
			case 1:
			{
				string path;
				ofstream fcout;
				system("cls");
				cout << "VVedite put' do faila dlya sohraneniya v fail: ";
				cin >> path;
				fcout.open(path);
				cout << "nachalo sohraneniya" << endl;
				fcout << fs;
				fcout.close();
				cout << "konec sohraneniya" << endl;
				system("pause");
				break;
			}
			case 2:
			{
				string person;
				system("cls");
				cout << "Vvedite imya: ";
				cin >> person;
				cout << "Pervoe nabludenie : " << fs.get_first_weighing(person);
				system("pause");
				break;
			}
			case 3:
			{
				weighing o;
				system("cls");
				cout << "Vvesti nabludenie (name day month year weight) : ";// Name 1 01 2001 11.11
				cin >> o;
				fs.add_weighing(o);
				cout << "Nabludenie dobavleno" << endl;
				system("pause");
				break;
			}
			case 4:
			{
				string person;
				int day, month, year;
				system("cls");
				cout << "Vvedite imya: ";
				cin >> person;
				cout << "Vvesti datu (day month year): ";
				cin >> day >> month >> year;
				cout << "Weight : " << fs.get_result_weighing(person, day, month, year) << endl;
				system("pause");
				break;
			}
			case 5:
			{
				string person;
				system("cls");
				cout << "Vvedite imya: ";
				cin >> person;
				cout << "Minimal'niy ves: " << fs.get_min_weight(person) << endl;
				system("pause");
				break;
			}
			case 6:
			{
				int m;
				string person;
				system("cls");
				cout << "Vvedite imya: ";
				cin >> person;
				cout << "Vvesti mesyac: ";
				cin >> m;
				cout << "Minimal'niy ves: " << fs.get_min_weight(person, m) << endl;
				system("pause");
				break;
			}
			case 7:
			{
				string person;
				system("cls");
				cout << "Vvedite imya: ";
				cin >> person;
				cout << "Sredniy ves: " << fs.get_mid_weight(person) << endl;
				system("pause");
				break;
			}
			case 8:
			{
				int m;
				string person;
				system("cls");
				cout << "Vvedite imya: ";
				cin >> person;
				cout << "Vvesti mesyac: ";
				cin >> m;
				cout << "Sredniy ves: " << fs.get_mid_weight(person, m) << endl;
				system("pause");
				break;
			}
			case 9:
			{
				string person;

				system("cls");
				cout << "Vvedite imya: ";
				cin >> person;
				cout << "Maksimal'niy ves: " << fs.get_max_weight(person) << endl;
				system("pause");
				break;
			}
			case 10:
			{
				int m;
				string person;
				system("cls");
				cout << "Vvedite imya: ";
				cin >> person;
				cout << "Vvesti mesyac: ";
				cin >> m;
				cout << "Maksimal'niy ves: " << fs.get_max_weight(person, m) << endl;
				system("pause");
				break;
			}
			default: break;
			}
		}



		catch (...)
		{
			cout << "Oshibka" << endl;
			system("pause");
		}
	} while (choise != 11);
}