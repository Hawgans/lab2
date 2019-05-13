#include <iostream>
#include "function.h"

using namespace std;
int const n = 11;

int var1(int* m, int size)//Сумма равна 1 элементу, массив инвертируется
{
	int t;
	for (int i = 0; i < size / 2; i++)
	{
		t = m[i];
		m[i] = m[size - i - 1];
		m[size - i - 1] = t;
	}
	return 0;
}

int var2(int* m, int size)//Сумма меньше первого элемента массива, массив сортируется по возрастанию
{
	int i, j;
	int t;
	for (j = 0; j < size - 1; j++)
		for (i = 0; i < size - 1; i++)
		{
			if (m[i] > m[i + 1])
			{
				t = m[i];
				m[i] = m[i + 1];
				m[i + 1] = t;
			}
		}
	return 0;
}

int var3(int* m, int size)//Сумма больше первого элемента массива, массив сортируется по убыванию
{
	int i, j;
	int t;
	for (j = 0; j < size - 1; j++)
		for (i = 0; i < size - 1; i++)
		{
			if (m[i] < m[i + 1])
			{
				t = m[i];
				m[i] = m[i + 1];
				m[i + 1] = t;
			}
		}
	return 0;
}

int(*choice(int* m, int size))(int* m, int size)
{
	int i;
	int sum = 0;

	for (i = 0; i < n; i++)//Суммируем элементы массива
	{
		sum = sum + m[i];
	}
	cout << sum << endl;

	if (m[0] == sum)//Выбор варината
		return(var1);
	else if (m[0] > sum)
		return (var2);
	else if (m[0] < sum)
		return(var3);

}

double sum(double a, double b)//Сложение
{
	return(a + b);
}

double substruct(double a, double b)//Вычитание
{
	return(a - b);
}

double multik(double a, double b)//Умножение
{
	return(a * b);
}

double devide(double a, double b)//Деление
{
	return(a / b);
}

double MAXX(double a, double b)//Поиск макимального значения
{
	return(a > b) ? a : b;
}

double MIN(double a, double b)//Поиск минимального значения
{
	return(a < b) ? a : b;
}

void fold(double* mass, unsigned size, double(*funco)(double, double), double* acc)//Вызов функции для работы с массивом
{
	unsigned i;
	*acc = funco(mass[0], mass[1]);
	for (i = 2; i < size; i++)
	{
		*acc = funco(*acc, mass[i]);
	}
}