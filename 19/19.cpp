#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	setlocale(0, "");
	int n;
	cout << "������� ���������� ��������� � �����: ";
	cin >> n;

	Stack s;

	s.make(n);

	cout << "��������� ����: ";
	s.print();

	s.add();

	cout << "���� ����� ����������: ";
	s.print();

	return 0;
}