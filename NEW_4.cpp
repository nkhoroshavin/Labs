#include <iostream>
using namespace std;
int n, l, c, k;
int a[100];


int main()
{
	setlocale(LC_ALL, "");
	cout << "Введите количество чисел в массиве: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 - 50;
		cout << a[i] << " ";
	}


	cout << "\nВведите значение, которое необходимо удалить: ";
	cin >> k;
	c = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == k)
		{
			c = a[i];
			l = i;
			if (l == n)
			{
				n = n - 1;
			}
			else {
				for (int j = l; j < n - 1; j++)
				{
					a[j] = a[j + 1];
				}
				n--;
			}
		}
	}
	if (c == 0)
	{
		cout << "Такой элемент в массиве не найден.";
	}
	else {
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
	}

	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			n++;
			for (int j = n; j > i; j--)
			{
				a[j] = a[j - 1];
			}
			i++;
			a[i-1] = 0;

		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}