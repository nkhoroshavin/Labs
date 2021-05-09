#include <iostream>
#include "Pair.h"
#include <fstream>
#include "file_work.h"
#include <string>
using namespace std;
int main() {
    Pair p, a;
    int k, c;
    char file_name[30];
    do {
        cout << "1. ������� ����, 2. ��������� ����, 3. ������� ���� �� �����, 4. ��������� ����, 5. �������� ����, 0. �����\n";
        cin >> c;
        switch (c) {
        case 1:
            cout << "���? ";
            cin >> file_name;
            k = make_file(file_name);
            if (k < 0) cout << "Error";
            break;
        case 2:
            cout << "���? ";
            cin >> file_name;
            k = print_file(file_name);
            if (k == 0)cout << "������ ����\n";
            if (k < 0)cout << "Error\n";
            break;
        case 3:
            cout << "���? ";
            cin >> file_name;
            cin >> p;
            k = del_file(file_name, p);
            if (k < 0)cout << "Error";
        case 4:
            cout << "���? ";
            cin >> file_name;
            cout << "����� ���� ���������?\n";
            cin >> p;
            cout << "���������?\n";
            cin >> a;
            k = increase_file(file_name, p, a);
            if (k == -1) cout << "Error\n";
            if (k == 0) cout << "����� ��� ���\n";
            break;
        case 5:
            cout << "���? ";
            cin >> file_name;
            int n, s;
            cout << "����� ����� ��� ������� ��������? ";
            cin >> n;
            cout << "������� ���? ";
            cin >> s;
            Pair* items = new Pair[s];
            for (int i = 0; i < s; ++i) {
                cin >> items[i];
            }
            k = add_file(file_name, n, s, items);
            if (k == -1) cout << "Error\n";
            break;
        }
    } while (c != 0);
}