#pragma once
#include <iostream> 
using namespace std;
class money
{
	long rub;
	int penny;
public:
	money() {
		rub = 0;
		penny = 0.0;
	};
	money(int m, int s) {
		rub = m;
		penny = s;
	}
	money(const money& t)
	{
		rub = t.rub;
		penny = t.penny;
	}
	~money() {};
	int get_f() {
		return rub;
	}
	int get_sec() {
		return penny;
	}
	void set_f(int m)
	{
		rub = m;
	}
	void set_sec(int s) {
		penny = s;
	}

	money& operator=(const money&);
	money operator+(const money&);
	money operator-(const money&);
	friend istream& operator>>(istream& in, money& t);
	friend ostream& operator<<(ostream& out, const money& t);
};