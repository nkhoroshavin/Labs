#include <iostream> 
#include "pair.h"
#include "list.h"
#include <cstdlib> 
using namespace std;
typedef List<Pair> lst;
int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		lst l;
		cout << "N?";
		int n; cin >> n;
		l.make(n);
		cout << "��������� ������: " << endl;
		l.print();
		l.add_average();
		cout << "������ ����� ���������� �������� ���������������: " << endl;
		l.print();
		Pair k1, k2;
		cin >> k1 >> k2;
		l.del_key_inRange(k1, k2);
		cout << "������ ����� ��������: " << endl;
		l.print();
		l.sumMaxMin();
		cout << "������ ����� ���������� � ��������� ����� ������������� � ������������: " << endl;
		l.print();
	}
	catch (int)
	{
		cout << "error!";
	}
}