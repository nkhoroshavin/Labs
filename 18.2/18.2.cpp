#include"country.h"
#include<iostream>
#include<string>
using namespace std;

country make_country()
{
	string s;
	int i;
	double d;
	cout << endl;
	cout << "Введите название столицы: ";
	cin >> s;
	cout << "Введите количество чеовек: ";
	cin >> i;
	cout << "Введите площадь: ";
	cin >> d;
	country t(s, i, d);
	return t;
}

void print_strana(country t)
{
	t.show();
}

void main()
{
	country t1;
	t1.show();

	country t2("Moscow", 12000000, 2511.0);
	t2.show();
	cout << endl;

	country t3 = t2;
	t3.set_capital("Warsaw");
	t3.set_population(1700000);
	t3.set_s(517.2);
	cout << endl;

	print_country(t3);

	t1 = make_country();
	t1.show();
}
