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
        cout << "1. Создать файл, 2. Напечаать файл, 3. Удалить пару из файла, 4. Увеличить пары, 5. Добавить пары, 0. Выйти\n";
        cin >> c;
        switch (c) {
        case 1:
            cout << "Имя? ";
            cin >> file_name;
            k = make_file(file_name);
            if (k < 0) cout << "Error";
            break;
        case 2:
            cout << "Имя? ";
            cin >> file_name;
            k = print_file(file_name);
            if (k == 0)cout << "Пустой файл\n";
            if (k < 0)cout << "Error\n";
            break;
        case 3:
            cout << "Имя? ";
            cin >> file_name;
            cin >> p;
            k = del_file(file_name, p);
            if (k < 0)cout << "Error";
        case 4:
            cout << "Имя? ";
            cin >> file_name;
            cout << "Какие пары увеличить?\n";
            cin >> p;
            cout << "Насколько?\n";
            cin >> a;
            k = increase_file(file_name, p, a);
            if (k == -1) cout << "Error\n";
            if (k == 0) cout << "Таких пар нет\n";
            break;
        case 5:
            cout << "Имя? ";
            cin >> file_name;
            int n, s;
            cout << "После каких пар следует добавить? ";
            cin >> n;
            cout << "Сколько пар? ";
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