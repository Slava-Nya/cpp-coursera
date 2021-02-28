#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <exception>

using namespace std;

class Rational {
public:
	Rational()
	{
		num = 0;
		den = 1;
	}
	Rational(int numerator, int denominator)
	{
		if (denominator == 0)
			throw 1;
		if (denominator < 0)
		{
			if (numerator < 0)
			{
				denominator = abs(denominator);
				numerator = abs(numerator);
			}
			else
			{
				denominator = abs(denominator);
				numerator = numerator - 2 * numerator;
			}
		}
		if (numerator == 0)
		{
			denominator = 1;
		}
		int nod = Nod(abs(numerator), abs(denominator));
		num = numerator / nod;
		den = denominator / nod;
	}
	int Numerator() const
	{
		return num;
	}
	int Denominator() const
	{
		return den;
	}
private:
	int num; //поле числитель
	int den; //и знаменатель

	int Nod(int a, int b)
	{
		while (a > 0 && b > 0)
		{
			if (a > b)
				a %= b;
			else
				b %= a;
		}
		return a + b;
	}
};
bool operator == (Rational a, Rational b)
{
	if ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator()))
		return true;
	else
		return false;
}
Rational operator + (Rational a, Rational b)
{
	int p = (a.Numerator() * b.Denominator()) + (b.Numerator() * a.Denominator());
	int q = a.Denominator() * b.Denominator();
	return Rational(p, q);
}
Rational operator - (Rational a, Rational b)
{
	int p = (a.Numerator() * b.Denominator()) - (b.Numerator() * a.Denominator());
	int q = a.Denominator() * b.Denominator();
	return Rational(p, q);
}
Rational operator * (Rational a, Rational b)
{
	return Rational((a.Numerator()*b.Numerator()), (a.Denominator()*b.Denominator()));
}
Rational operator / (Rational a, Rational b)
{
	if (b.Numerator() == 0)
		throw 2;
	return Rational((a.Numerator() * b.Denominator()), (a.Denominator() * b.Numerator()));
}

istream& operator >> (istream& is, Rational& obj)
{
	int p, q ;
	char c;

	is >> p;
	is >> c;
	is >> q;
	if (is &&  c == '/')
	{
		obj = Rational(p, q);
	}
	return is;
}

ostream& operator << (ostream& stream, const Rational& r)
{
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}

bool operator > (Rational a, Rational b)
{
	return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}

bool operator < (Rational a, Rational b)
{
	return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

int main()
{
	try
	{
		Rational a, b;
		char ch;
		cin >> a >> ch >> b;
		if (ch == '+') cout << a + b;
		else if (ch == '-') cout << a - b;
		else if (ch == '*') cout << a * b;
		else cout << a / b;
	}
	catch (int ex)
	{
		if (ex == 1)
			cout << "Invalid argument";
		else
			cout << "Division by zero";
	}
	return 0;
}
