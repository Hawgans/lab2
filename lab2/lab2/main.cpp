#include <iostream>
#include <ctime>
#include "function.h"

using namespace std;
int const n = 11;

int main()
{
	double m[] = { 9, 1, 6, 11, 7, 7, 3, 10, 15, 1, 8 }; //Элементы массива
	double result;

	system("chcp 1251");

	fold(m, 11, sum, &result);
	cout << "Сумма: " << result << endl; //Переход на сумму

	fold(m, 11, substruct, &result);
	cout << "Вычитание: " << result << endl; //Переход на вычитание

	fold(m, 11, multik, &result);
	cout << "Умножение: " << result << endl; //Переход на умноженеие

	fold(m, 11, devide, &result);
	cout << "Деление: " << result << endl;  //Переход на деление

	fold(m, 11, MAXX, &result);
	cout << "Максимум: " << result << endl; //Переход на максимальное число

	fold(m, 11, MIN, &result);
	cout << "Минимум: " << result << endl; //Переход на минимальное число

	int mass[n];
	int i;
	int sum = 0;
	int k;
	int (*p)(int* m, int size);

	srand(time(NULL));// создание массива со случайными числами
	for (i = 0; i < n; i++)
	{
		mass[i] = rand() % 201 - 100; //Размер массива

	}

	for (i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;

	p = choice(mass, n);
	p(mass, n);

	for (i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}

	system("pause");
}