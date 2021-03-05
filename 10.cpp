#include <iostream>//15 Вариант
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m, i, j;
	cout << "Введите размер массива: ";
	cin >> n >> m;
	int** matr;
	matr = new int* [n];
	for (i = 0; i < n; i++)
	{
		matr[i] = new int[m];

		for (j = 0; j < m; j++)
			matr[i][j] = rand() % 100 - 50;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int max = 0;
	int k = 0, p = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			if (matr[i][j] > max)
			{
				max = matr[i][j];
				k = i;
				p = j;
			}
	}
	for (i = 0; i < n; i++)
	{
		for (j = p; j < m - 1; j++)
			matr[i][j] = matr[i][j + 1];

	}
	m--;
	for (i = k; i < n - 1; i++)
	{
		for (j = 0; j < m; j++)
			matr[i][j] = matr[i + 1][j];
	}
	n--;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
		delete matr[i];
	delete[] matr;
	return 0;
}
