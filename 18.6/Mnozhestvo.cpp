#include "Mnozhestvo.h"

Mnozhestvo::Mnozhestvo(int s, int k) {
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = k;

    beg.elem = &data[0];
    end.elem = &data[size];
}

Mnozhestvo::Mnozhestvo(const Mnozhestvo& a) {
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];

    beg = a.beg;
    end = a.end;
}

Mnozhestvo::~Mnozhestvo() {
    delete[] data;
    data = 0;
}

Mnozhestvo& Mnozhestvo::operator=(const Mnozhestvo& a) {
    if (this == &a) return *this;
    size = a.size;
    if (data != 0) delete[]data;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];

    beg = a.beg;
    end = a.end;
    return *this;
}

int& Mnozhestvo::operator[](int index) {
    if (index < size) return data[index];
    cerr << "\nError! Index > size";
}

Mnozhestvo Mnozhestvo::operator+(Mnozhestvo& a) {
    Mnozhestvo temp(size);
    for (int i = 0; i < size; i++) {
        if (i < a.size)
        {
            temp.data[i] = a.data[i] + data[i];
        }
        else
        {
            temp.data[i] = +data[i];
        }
    }
    return temp;
}
int Mnozhestvo::operator()() {
    return len();
}
ostream& operator<<(ostream& out, const Mnozhestvo& a) {
    for (int i = 0; i < a.size; i++) {
        out << a.data[i] << " ";
    }
    return out;
}
istream& operator>>(istream& in, Mnozhestvo& a) {
    for (int i = 0; i < a.len(); i++) {
        in >> a.data[i];
    }
    return in;
}