#include <iostream>

#include <string>

#include <fstream>

using namespace std;

struct dat

{

	string fio;

	string date;

	int pass;

	string pass1;

};

void line_in_line()

{

	string key;

	int num = -1;

	ofstream F("F.txt");

	dat N1 = { "������ ���� ��������", "04.10.2002", 507263, "507263" };

	dat N2 = { "������ ���� ��������", "18.02.2010", 263598, "263598" };

	dat N3 = { "�������� ������� ����������", "06.12.2000", 648531, "648531" };

	dat N4 = { "����������� ��������� �������������", "06.10.2002", 984563, "984563" };

	dat N5 = { "�������� ������ ����������", "30.10.1998", 651234, "651234" };

	dat a[5] = { N1, N2, N3, N4, N5 };

	for (int i = 0; i < 5; i++)

		cout << " " << i + 1 << ") " << '\t' << a[i].fio << endl << '\t' << a[i].date << endl << '\t' << a[i].pass << endl << "\n";

	cout << "����� ���� (����� ��������), �� �������� ����� ����������� �����: ";
	cin >> key;

	string a1[5]{ N1.pass1, N2.pass1, N3.pass1, N4.pass1, N5.pass1 };

	for (int i = 0; i < 5; i++)

		if (key == a1[i])
		{
			num = i + 1;
		}
	if (num != -1)
	{
		F << " " << num << ") " << '\t' << a[num - 1].fio << endl << '\t' << a[num - 1].date << endl << '\t' << a[num - 1].pass << endl << "\n";
	}
	else
	{
		F << "������� ������� �� ������";
	}
}

void clear1()

{

	string key;

	int num = -1;

	ofstream F("F.txt");

	dat N1 = { "������ ���� ��������", "04.10.2002", 507263, "507263" };

	dat N2 = { "������ ���� ��������", "18.02.2010", 263598, "263598" };

	dat N3 = { "�������� ������� ����������", "06.12.2000", 648531, "648531" };

	dat N4 = { "����������� ��������� �������������", "06.10.2002", 984563, "984563" };

	dat N5 = { "�������� ������ ����������", "30.10.1998", 651234, "651234" };

	dat a[5] = { N1, N2, N3, N4, N5 };

	for (int i = 0; i < 5; i++)

		cout << " " << i + 1 << ") " << '\t' << a[i].fio << endl << '\t' << a[i].date << endl << '\t' << a[i].pass << endl << "\n";

	cout << "����� ���� (����� ��������), �� �������� ����� ����������� �����: "; cin >> key;

	string a1[5]{ N1.pass1, N2.pass1, N3.pass1, N4.pass1, N5.pass1 };

	for (int i = 0; i < 5; i++)

		if (key == a1[i])
			num = i + 1;

	if (num != -1)

		F << " " << num << ") " << '\t' << a[num - 1].fio << endl << '\t' << a[num - 1].date << endl << '\t' << a[num - 1].pass << endl << "\n";

	else

		F << "������� ������� �� ������";

}

void intersearch()

{

	int key, num = -1, mid = -1, left = 0, right = 4, i, temp, item;

	ofstream F("F.txt");

	dat N1 = { "������ ���� ��������", "04.10.2002", 507263, "507263" };

	dat N2 = { "������ ���� ��������", "18.02.2010", 263598, "263598" };

	dat N3 = { "�������� ������� ����������", "06.12.2000", 648531, "648531" };

	dat N4 = { "����������� ��������� �������������", "06.10.2002", 984563, "984563" };

	dat N5 = { "�������� ������ ����������", "30.10.1998", 651234, "651234" };

	dat a[5] = { N1, N2, N3, N4, N5 };

	for (i = 0; i < 5; i++)

		cout << " " << i + 1 << ") " << '\t' << a[i].fio << endl << '\t' << a[i].date << endl << '\t' << a[i].pass << endl << "\n";

	cout << "����� ���� (����� ��������), �� �������� ����� ����������� �����: "; cin >> key;

	int a1[5]{ N1.pass, N2.pass, N3.pass, N4.pass, N5.pass };

	for (i = 1; i < 5; i++) //���������

	{

		temp = a1[i];

		item = i - 1;

		while (item >= 0 && a1[item] > temp)

		{

			a1[item + 1] = a1[item];

			a1[item] = temp;

			item--;

		}

	}

	while (a1[left] <= key && a1[right] >= key && a1[mid] != key)

	{

		mid = left + ((key - a1[left]) * (right - left)) / (a1[right] - a1[left]);

		if (a1[mid] < key)

			left = mid + 1;

		else

			if (a1[mid] > key)

				right = mid - 1;

	}

	if (a1[mid] == key)

		F << "������� ������� ������";

	else F << "������� ������� �� ������";

}

int main()

{

	setlocale(LC_ALL, "Russian");

	system("chcp 1251>nul");

	int menu = -1;

	while (menu < 1 || menu > 3)

	{

		cout << "������ ����� ������: \n 1. ����� ��������� � ������ \n 2. ���������������� ����� \n 3. ������ �����  \n ����: ";

		cin >> menu;

	}

	if (menu == 1)
	{
		line_in_line();
	}
	if (menu == 2)
	{
		intersearch();
	}
	if (menu == 3)
	{
		clear1();
	}
}