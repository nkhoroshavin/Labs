#include <iostream> 
#include "pair.h"
#include "MsetList.h"
#include <cstdlib> 
using namespace std;
//typedef MsetList<Pair> mlst;
int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		//mlst l;
		cout << "N?";
		int n; cin >> n;
		MsetList<Pair>m(n);
		cout << "��������� ������: " << endl;
		m.print();
		m.add_average();
		cout << "������ ����� ���������� �������� ���������������: " << endl;
		m.print();
		Pair k1, k2;
		cin >> k1 >> k2;
		m.del_key_inRange(k1, k2);
		cout << "������ ����� ��������: " << endl;
		m.print();
		m.sumMaxMin();
		cout << "������ ����� ���������� � ��������� ����� ������������� � ������������: " << endl;
		m.print();
	}
	catch (int)
	{
		cout << "error!";
	}
}