#pragma once
#include <iostream> 
using namespace std;

class Iterator {
    friend class Mnozhestvo;
    int* elem;
public:
    Iterator() { elem = 0; }
    Iterator(const Iterator& it) { elem = it.elem; }
    bool operator==(const Iterator& it) { return elem == it.elem; }
    bool operator!=(const Iterator& it) { return elem != it.elem; }
    void operator++() { ++elem; }
    void operator++(int) { ++elem; }
    void operator--() { --elem; }
    void operator--(int) { --elem; }
    int& operator*()const { return *elem; }
};

class Mnozhestvo {
    int size;
    int* data;
    int len() { return size; }

    Iterator beg;
    Iterator end;
public:
    Mnozhestvo(int s, int k = 0);
    Mnozhestvo(const Mnozhestvo& a);
    ~Mnozhestvo();
    Mnozhestvo& operator=(const Mnozhestvo& a);
    int& operator[](int index);
    Mnozhestvo operator+(Mnozhestvo& a);
    int operator()();

    friend ostream& operator<<(ostream& out, const Mnozhestvo& a);
    friend istream& operator>>(istream& in, Mnozhestvo& a);

    Iterator first() { return beg; }
    Iterator last() { return end; }
};