#include "money.h" 
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
	cout << "������ ����� �����:" << a << endl;
	cout << "������ ����� �����:" << b << endl;
	c = a + b;
	d = a - b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "�������� c = " << c << endl;
	cout << "��������� d = " << d << endl;
}