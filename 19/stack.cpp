#include "stack.h"
#include <iostream>

Stack::Stack()
{
	top = NULL;
}
Stack::~Stack()
{
	stack_* p = new stack_;
	while (top != NULL)
	{
		p = top;
		top = top->pred;
		delete p;
	}
	delete top;
}
void Stack::make(int n)
{
	double a;
	if (n <= 0)
	{
		cout << "Ñòåê íå ìîæåò áûòü ñîçäàí!";
	}
	stack_* p = new stack_;
	cin >> a;
	p->data = a;
	p->pred = NULL;
	top = p;
	for (int i = 2; i <= n; i++)
	{
		stack_* h = new stack_;
		cin >> a;
		h->data = a;
		h->pred = top;
		top = h;
	}
}
void Stack::print()
{
	if (top == NULL) cout << "Ñòåê ïóñòîé" << endl;
	else {
		stack_* p = top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->pred;
		}
		cout << endl;
	}
}
void Stack::add()
{
	stack_* p = top;
	stack_* q = new stack_;

	while (p != NULL)
	{
		if (p->data < 0) {
			stack_* r = new stack_;
			q = p->pred;
			p->pred = r;
			p = p->pred;
			p->data = 0;
			p->pred = q;
		}
		p = p->pred;
	}
}
