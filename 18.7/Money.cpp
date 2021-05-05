#include "Money.h"
Money::Money(void)
{
	rub = pen = 0;
}


Money::Money(int R, int C)
{
	rub = R; pen = C;
}
Money::Money(const Money& t)
{
	rub = t.rub; pen = t.pen;
}
Money& Money::operator =(const Money& t)
{
	rub = t.rub; pen = t.pen; return*this;
}
ostream& operator<<(ostream& out, const Money& t)
{

	out << t.rub << " . " << t.pen << " ; "; return out;
}
istream& operator>>(istream& in, Money& t)
{
	cout << "\nrub?"; in >> t.rub;
	cout << "\npen?"; in >> t.pen;
	return in;
}

Money Money::operator +(Money k)
{
	int t = rub * 100 + pen;
	int kt = k.rub * 100 + k.pen;
	t -= kt;
	Money temp(t / 100, t % 100);
	return temp;
}