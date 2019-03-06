#include <iostream>
#include <string.h>
#include <locale.h>
#include "Vector3D.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Vector3D Vector1(7.3, 1.9, 2.1), Vector2(6, 0, 2), Vector3;
	Vector3 = Vector2;
	cout << "Координаты вектора 1: \n" << Vector1 << "\n" << "Координаты вектора 2: \n" << Vector2 << "\n" << "Координаты вектора 3: \n" << Vector3 << endl;
	cout << "_______________________________________________" << endl;
	Vector3D summa = Vector1 + Vector2;
	Vector3D raznost = Vector1 - Vector2;
	double pr = Vector1 * Vector2;
	cout << "\n Сумма векторов 1 и 2 = " << summa << endl;
	cout << "\n Разность векторов 1 и 2 = " << raznost << endl;
	cout << "Произведение векторов 1 и 2 = " << pr << endl << endl;
	cout << "_______________________________________________" << endl;
	Vector3 = 3.2 * Vector2;
	cout << "Вектор 3 умноженный на скаляр: \n" << Vector3 << endl;
	cout << "_______________________________________________" << endl;
	if (Vector1 > Vector2)
		cout << "Вектор1 длиннее Вектора2" << endl;
	else if (Vector1 < Vector2)
		cout << "Вектор2 длиннее Вектора1" << endl;
	else
		cout << "Длина Вектора1 равна длине Вектора2" << endl;

	system("pause");
	return 0;
}