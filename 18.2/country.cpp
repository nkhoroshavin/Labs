#include"country.h"
#include<iostream>
#include<string>
using namespace std;

country::country()
{
	capital = "";
	population = 0;
	s = 0;
	cout << "Конструктор без параметров для объекта" << this << endl;
}
country::country(string N, int K, double S)
{
	capital = N;
	population = K;
	s = P;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}
country::country(const capital& t)
{
	capital = t.capital;
	population = t.population;
	s = t.s;
	cout << "Конструктор копирования для объекта " << this << endl;

}
country::~country()
{
	cout << "Деструктор для объекта " << this << endl;
}
string country::get_capital()
{
	return capital;

}
int country::get_population()
{
	return population;
}
double country::get_s()
{
	return s;
}
void country::set_capital(string N)
{
	capital = N;
}
void country::set_population(int K)
{
	population = K;
}
void country::set_s(double P)
{
	s = P;
}
void country::show()
{
	cout << "Столица : " << capital << endl;
	cout << "Количество : " << population << endl;
	cout << "Площадь : " << s << endl;
}