#pragma once

#include <iostream>

using namespace std;
const int MAX_SIZE = 30;

class List {
private:
    int size;
    int* data;
public:
    explicit List(int s, int k = 0);

    List();

    List(const List& l);

    ~List();

    List& operator=(const List& l);

    int& operator[](int index);

    List operator+(int k);

    void operator++();

    int operator()() const;

    friend ostream& operator<<(ostream& out, const List& l);

    friend istream& operator>>(istream& in, List& l);
};

istream& operator>>(istream& in, List& l) {
    for (int i = 0; i < l.size; i++) {
        in >> l.data[i];
    }
    return in;
}
List& List::operator=(const List& l) {
    if (this == &l) {
        return *this;
    }
    size = l.size;
    delete[] data;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = l.data[i];
    }
    return *this;
}
void List::operator++() {
    if (size == MAX_SIZE) throw 4;
    int* tmp = data;
    data = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        data[i] = tmp[i];
    }
    delete[] tmp;
    int n;
    cout << "What number to add to the list? ";
    cin >> n;
    data[size] = n;
    ++size;
}
List::List() {
    size = 0;
    data = {};
}