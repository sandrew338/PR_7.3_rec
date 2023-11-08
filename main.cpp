// Lab_7_3.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 7.3)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 17
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void SearchMax(int** a, const int n, int level, int& x, int& y, int& value, int max, int i, int j);
void SortDiagonal(int**& a, const int n, int& x, int& y, int& value, int max, int i);
void Create(int** a, const int n, const int Low, const int High, int i, int j);
void Print(int** a, const int n, int i, int j);

void SwapElements(int**& a, const int n, int x, int y, int i);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	int x, y, value;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High, 0, 0);
	Print(a, n, 0, 0);
	cout << "After modification: " << endl;
	//
	SortDiagonal(a, n, x, y, value, a[0][0], 0);
	Print(a, n, 0, 0);
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low,
	const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < n - 1)
	{
		Create(a, n, Low, High, i, j + 1);

	}
	else
	if (i < n - 1)
	{
		Create(a, n, Low, High, i + 1, 0);
	}
}
void Print(int** a, const int n, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < n - 1)
		Print(a, n, i, j + 1);
	else
		if (i < n - 1)
		{
			cout << endl;
			Print(a, n, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void SortDiagonal(int**& a, const int n, int& x, int& y, int& value, int max, int i)
{
	if (i < n)
	{
		max = a[i][0];
		value = max;
		x = i;
		y = 0;
		SearchMax(a, n, i, x, y, value, max, 0, 0);
		SwapElements(a, n, x, y, i);
		cout << i << ". value = " << value << endl << "x = " << x << endl << "y = " << y << endl << "===============" << endl;
		Print(a, n, 0, 0);
		SortDiagonal(a, n, x, y, value, a[i][0], i + 1);
	}
}
void SearchMax(int** a, const int n, int level, int& x, int& y, int& value, int max, int i, int j)
{
	if (j < n)
	{
		if (a[i][j] > max && !(i == j && i < level))
		{
			max = a[i][j];
			value = max;
			x = i;
			y = j;
		}
		SearchMax(a, n, level, x, y, value, max, i, j + 1);
	}
	else
		if (i < n - 1)
		{
			SearchMax(a, n, level, x, y, value, max, i + 1, 0);
		}
}
void SwapElements(int**& a, const int n, int x, int y, int i)
{
	int temp = a[i][i];
	a[i][i] = a[x][y];
	a[x][y] = temp;
}