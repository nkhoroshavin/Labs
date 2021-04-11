#include <iostream>
#include <string>
using namespace std;

struct info {
	string FIO;
	string NUMBER;
	string PASS;
};
bool knut_morris_pratt(string str, string pod) {
	int i, j, k;
	bool res = 0;
	int d = str.size();
	int e = pod.size();
	if (d == 0) {
		cout << "������� ������ ������\n";
	}
	else {
		if (e == 0) {
			cout << "������� ������ ���������\n";
		}
		else {
			j = 0;
			k = -1;
		}
	}
	int* pf = new int[1000];
	pf[0] = -1;
	while (j < e - 1) {
		while (k >= 0 && pod[j] != pod[k])
			k = pf[k];
		j++;
		k++;
		if (pod[j] == pod[k])
			pf[j] = pf[k];
		else
			pf[j] = k;
	}
	i = 0;
	j = 0;
	while (j < e && i < d) {
		while (j >= 0 && str[i] != pod[j])
			j = pf[j];
		i++;
		j++;
	}
	delete[] pf;
	if (j == e)
		res = 1;
	return res;
}
bool boyer_moor(string str, string pod) {
	int d = str.size();
	int e = pod.size();
	if (d == 0)
		cout << "������� ������ ������\n";
	else if (e == 0)
		cout << "������� ������ ���������\n";
	else
		int  i, Pos;
	int  bmt[256];
	for (int i = 0; i < 256; i++)
		bmt[i] = e;
	for (int i = e - 1; i >= 0; i--)
		if (bmt[(short)(pod[i])] == e)
			bmt[(short)(pod[i])] = e - i - 1;
	int pos = e - 1;
	while (pos < d)
		if (pod[e - 1] != str[pos])
			pos += bmt[(short)(str[pos])];
		else
			for (int i = e - 2; i >= 0; i--) {
				if (pod[i] != str[pos - e + i + 1]) {
					pos += bmt[(short)(str[pos - e + i + 1])] - 1;
					break;
				}
				else
					if (i == 0) {
						return true;
					}
			}
	return false;
}

void boyer(info* st, string key, int n) {
	bool l;
	bool p = 0;
	for (int i = 0; i < n; i++) {
		l = boyer_moor(st[i].PASS, key);
		if (l != 0) {
			cout << "������� ������ ��� �������: " << i << endl;
			cout << "���: " << st[i].FIO << endl;
			cout << "����� ��������: " << st[i].NUMBER << endl;
			cout << "����� ��������: " << st[i].PASS << endl;
			p = 1;
		}
	}
	if (p == 0) {
		cout << "������� �� ������" << endl;
	}
}
void knut(info* st, string key, int n) {
	bool l;
	bool p = 0;
	for (int i = 0; i < n; i++) {
		l = knut_morris_pratt(st[i].PASS, key);
		if (l != 0) {
			cout << "������� ������ ��� �������: " << i << endl;
			cout << "���: " << st[i].FIO << endl;
			cout << "����� ��������: " << st[i].NUMBER << endl;
			cout << "����� ��������: " << st[i].PASS << endl;
			p = 1;
		}
	}
	if (p == 0) {
		cout << "������� �� ������" << endl;
	}
}
int main() {
	int n;
	string key;
	cout << "���-�� ���������: ";
	cin >> n;
	cin.ignore();
	cout << "���� ��� ������ (�������) : ";
	getline(cin, key);
	info* st = new info[n];
	for (int i = 0; i < n; i++) {
		cout << "���: ";
		getline(cin, st[i].FIO);
		cout << "����� ��������: ";
		getline(cin, st[i].NUMBER);
		cout << "����� ��������: ";
		getline(cin, st[i].PASS);
	}
	bool a;
	cout << "������� 0, ���� ������ ���������� ����� ���������� ������-���� " << endl;
	cout << "������� 1, ���� ������ ���������� ����� ���������� �����-�������-������ " << endl;
	cin >> a;
	switch (a) {
	case 0: boyer(st, key, n); break;
	case 1: knut(st, key, n); break;
	default: cout << "������! " << endl;
	}
	return 0;
}
