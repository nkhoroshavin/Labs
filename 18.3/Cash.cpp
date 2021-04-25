#include "Cash.h" 
#include <iostream> 
using namespace std;

money& money::operator=(const money& t)
{
	if (&t == this)
		return *this;
	rub = t.rub;
	penny = t.penny;
	return *this;
}
money money::operator+(const money& t)
{
	long temp1 = rub * 100 + penny;
	long temp2 = t.rub * 100 + t.penny;
	money p;
	p.rub = (temp1 + temp2) / 100;
	p.penny = (temp1 + temp2) % 100;
	return p;
}
money money::operator - (const money& t)
{
	long temp3 = rub * 100 - penny;
	long temp4 = t.rub * 100 - t.penny;
	money q;
	q.rub = (temp4 - temp3) / 100;
	q.penny = (temp4 - temp3) % 100;
	return q;
}
istream& operator>>(istream& in, money& t)
{
	cout << "Введите рубли: ";
	cin >> t.rub;
	cout << "Введите копейки: ";
	cin >> t.penny;
	return in;
}
ostream& operator<<(ostream& out, const money& t)
{

	return (out << t.rub << "," << t.penny);
}
