#include <iostream>
using namespace std;
char a;

struct stack
{
	char data;
	stack* prev;
};

stack* stack_d(int n)
{
	if (n == 0)
	{
		return NULL;
	}

	stack* top, * p;
	top = NULL;
	p = new stack;

	cout << "������� ��������: ";
	cin >> a;
	p->data = a;
	p->prev = NULL;
	top = p;

	for (int i = 2; i <= n; i++)
	{
		stack* h = new stack;

		cin >> a;
		h->data = a;
		h->prev = top;
		top = h;
	}
	return top;
}

void print(stack* top)
{
	if (top == NULL)
	{
		cout << "���� ����" << endl;
	}

	else
	{
		stack* p = top;

		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
}

void add(stack*& first, int n)
{
	stack* p = first;
	stack* h = new stack;

	cout << "������� ������� ��� ����������: ";
	cin >> h->data;
	h->prev = p;
	first = h;

	while (p->prev != NULL)
	{
		stack* h = new stack;

		cout << "������� ������� ��� ����������: ";
		cin >> h->data;
		h->prev = p->prev;
		p->prev = h;

		if (p->prev->prev != NULL)
		{
			p = p->prev->prev;
		}

		else {
			p = p->prev;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ���-�� ���������: ";
	int n;
	cin >> n;
	stack* st = stack_d(n);
	cout << "����: ";
	print(st);
	add(st, n);

	cout << "��������� ����: ";
	print(st);
	return 0;
}