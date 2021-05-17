#include <iostream>
#include "stack.h"
using namespace std;
int main()
{
	setlocale(0, "");
	int n;
	cout << "Введите кол-ство элементов в стеке: ";
	cin >> n;
	Stack s;
	s.make(n);
	cout << "Стек: ";
	s.print();

	s.add();

	cout << "Стек после добавления: ";
	s.print();

	return 0;
}
