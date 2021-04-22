#pragma once
#include<iostream>
#include<string>
using namespace std;
class country
{
	string capital;
	int population;
	double s;
public:
	country();
	country(string, int, double);
	country(const country&);
	~country();
	string get_capital();
	void set_capital(string);
	int get_population();
	void set_population(int);
	double get_s();
	void set_s(double);
	void show();
};