#include <iostream>

using namespace std;

struct cars_n {
    string title;
    int year;
    int price;
    string color;
};

int main() {
    setlocale(LC_ALL, "Russian");
    cars_n cars[10];

    for (int i = 1; i <= 10; i++) {
        cars[i].year = 0;
    }

    cars[1].title = "BMW";
    cars[1].year =2018;
    cars[1].price = 1300000;
    cars[1].color = "Синий";

    cars[2].title = "Mercedes-Benz";
    cars[2].year = 2006;
    cars[2].price = 432000;
    cars[2].color = "Зеленый";

    cars[3].title = "Kia";
    cars[3].year = 2014;
    cars[3].price = 650000;
    cars[3].color = "Коричневый";

    cars[4].title = "VAZ 2103";
    cars[4].year = 1980;
    cars[4].price = 25000;
    cars[4].color = "Серый";

    cars[5].title = "Renault";
    cars[5].year = 2020;
    cars[5].price = 800000;
    cars[5].color = "Черный";

    cars[6].title = "Toyota";
    cars[6].year = 1990;
    cars[6].price = 600000;
    cars[6].color = "Красный";

    for (int i = 1; i <= 10; i++) {
        if (cars[i].year > 0) {
            cout << i << ")";
            cout << "Название: " << cars[i].title << endl;
            cout << "Год выпуска: " << cars[i].year << endl;
            cout << "Цена: " << cars[i].price << endl;
            cout << "Цвет: " << cars[i].color << endl << endl;

        }
    }
    int gvlim = 0;
    cout << "Введите минимальный г.в. " << endl;
    cin >> gvlim;
    for (int i = 1; i <= 10; i++) {
        if (cars[i].year < gvlim) {
            cars[i].year = 0;
        }
    }
    int G = 0;
    for (int i = 1; i <= 9; i++) {
        if (cars[i].year == 0) {
            G = i;
            while ((cars[G].year == 0) && (G < 9)) {
                G++;
            }
            cars[i].title = cars[G].title;
            cars[i].year = cars[G].year;
            cars[i].price = cars[G].price;
            cars[i].color = cars[G].color;
            cars[G].year = 0;
        }
    }
    cout << "Список автомобилей удовлетворяющих по г.в.: " << endl;
    for (int i = 1; i <= 10; i++) {
        if (cars[i].year > 0) {
            cout << i << ")";
            cout << "Название: " << cars[i].title << endl;
            cout << "Год выпуска: " << cars[i].year << endl;
            cout << "Цена: " << cars[i].price << endl;
            cout << "Цвет: " << cars[i].color << endl << endl;
            G = 0;

        }
    }
    cout << "Введите данные об одном автомобиле: " << endl;
    for (int i = G ; i < G + 1; i++) {

        cout << "Название: ";
        cin >> cars[i].title;

        cout << "Год выпуска: ";
        cin >> cars[i].year;

        cout << "Цена: ";
        cin >> cars[i].price;

        cout << "Цвет: ";
        cin >> cars[i].color;
        cout << endl;
    }
    cout << "Измененный список автомобилей: " << endl;
    for (int i = 1; i <= 10; i++) {
        if ((cars[i].year > 0) && (cars[i].price > 0)) {
            cout << i << ")";
            cout << "Название: " << cars[i].title << endl;
            cout << "Год выпуска: " << cars[i].year << endl;
            cout << "Цена: " << cars[i].price << endl;
            cout << "Цвет: " << cars[i].color << endl << endl;
            G++;
        }
    }
    return 0;
}
