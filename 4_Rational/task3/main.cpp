#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>
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

int main() {
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("");
		Rational r;
		bool correct = !(input >> r);
		if (!correct) {
			cout << "Read from empty stream works incorrectly" << endl;
			return 3;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 4;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 5;
		}
	}

	{
		istringstream input1("1*2"), input2("1/"), input3("/4");
		Rational r1, r2, r3;
		input1 >> r1;
		input2 >> r2;
		input3 >> r3;
		bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
		if (!correct) {
			cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
				 << r1 << " " << r2 << " " << r3 << endl;

			return 6;
		}
	}

	{
		istringstream input("5/f 6/4");
		Rational r1, r2;
		input >> r1;
		input >> r2;
		bool equal1 = r1 == Rational(0, 1);
		bool equal2 = r2 == Rational(3, 2);
		if (!equal1 || !equal2) {
			cout << "read:\n" << r1 << '\n' << r2;
			return 1;
		}
	}

	cout << "OK" << endl;
	return 0;
}
