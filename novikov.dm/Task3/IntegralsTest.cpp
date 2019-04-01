#include <clocale>
#include <iostream>
#include <fstream>
#include "Integrals.h"

using namespace std;


int main()
{
	typedef double(*Function)(double);
	int k, f1;
	Function f2 = 0;
	Integrals c1, i, i2, i3;
	string f3;

	cout << "Vvediteinterval integrirovaniya i chislo otrezkov metoda pryamougolnikov ";

	cin >> c1;	//Peregruzka chteniya

	cout << "Vibirite funkciyu: " << endl;

	cout << "1 - Sin(x) " << endl;

	cout << "2 - Cos(x) " << endl;

	cout << "3 - exp(x) " << endl;
def1:

	cin >> f1;
	switch (f1)
	{
	case 1:
		f2 = sin;
		f3 = "Sin(x)";	//textovoe nazvanie funkcii
		break;

	case 2:
		f2 = cos;
		f3 = "Cos(x)";
		break;

	case 3:
		f2 = exp;
		f3 = "Exp(x)";
		break;

	default:
		cout << "Viberite cifru iz spiska: ";
		goto def1;
	}


	cout << "Vibirite metod vichisleniya integrala:" << endl;
	cout << "1 - Metod pravih pryamougolnikov " << endl;
	cout << "2 - Metod levih pryamougolnikov " << endl;
	cout << "3 - Metod srednih pryamougolnikov " << endl;
	cout << "4 - Vichislenie vsemi metodami " << endl;

def2:

	cin >> k;
	switch (k)
	{
	case 1:
		i = i.RightRectangle(f2, c1);
		cout << "Metod pravih pryamougolnikov: int(" << f3 << ") = " << i << endl;
		break;

	case 2:
		i = i.LeftRectangle(f2, c1);
		cout << "Metod levih pryamougolnikov: int(" << f3 << ") = " << i << endl;
		break;

	case 3:
		i = i.MiddleRectangle(f2, c1);
		cout << "Metod srednih pryamougolnikov: int(" << f3 << ") = " << i << endl;
		break;

	case 4:
		i = i.RightRectangle(f2, c1);
		i2 = i2.LeftRectangle(f2, c1);
		i3 = i3.MiddleRectangle(f2, c1);
		cout << "Metod pravih pryamougolnikov: int(" << f3 << ") = " << i << endl;
		cout << "Metod levih pryamougolnikov: int(" << f3 << ") = " << i2 << endl;
		cout << "Metod srednih pryamougolnikov: int(" << f3 << ") = " << i3 << endl;
		break;

	default:
		cout << "Viberite cifru iz predstavlennogo spiska: ";
		goto def2;
		break;
	}


	getchar();
	getchar();
}