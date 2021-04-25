#include "Cash.h" 
#include <iostream> 
using namespace std;
void main()
{
	setlocale(LC_ALL, "Rus");
	money a;
	money b;
	money c;
	money d;
	cin >> a;
	cin >> b;
	cout << "Первая сумма:" << a << endl;
	cout << "Вторая сумма:" << b << endl;
	c = a + b;
	d = a - b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "Сложение c = " << c << endl;
	cout << "Вычитание d = " << d << endl;
}
