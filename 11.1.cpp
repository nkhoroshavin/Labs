#include <iostream>
#include <string>
using namespace std;
struct List
{
	char data;
	List* next;
};
List* add(int size)
{ 
	if (size == NULL)
	{
		cout << "Error!:" << endl;
		return 0;
	}
	List* first, * p;

	first = NULL;
	p = new List;

	cout << "������� �������� ������: ";
	cin >> p->data;
	first = p;

	for (int i = 2; i <= size; i++)
	{
		List* h = new List;
		p->next = h;
		p = p->next;
		cin >> p->data;
		p->next = NULL;
	}
	return first;
}

void print(List* first)
{
	if (first == NULL)
	{
		cout << "����� ������: " << endl;
	}
	else
	{
		List* p = first;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}
void add(List*& first, int n)
{ 
	List* p = first;
	List* h = new List;
	cout << "������� " << n << " ��������(��): ";
	cin >> h->data;
	h->next = p;
	first = h;
	while (p->next != NULL)
	{
		List* h = new List;
		cin >> h->data;
		h->next = p->next;
		p->next = h;
		if (p->next->next != NULL)
		{
			p = p->next->next;
		}
		else p = p->next;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	cout << "������� ������ ������: ";
	cin >> size;
	List* list = add(size);
	cout << "������: ";
	print(list);
	add(list, size);
	cout << "��������� ������: ";
	print(list);
	return 0;
}