module;
#include <math.h>
#include <ostream>
export module Math;

export class Complex
{
private:
	double m_re;
	double m_im;
public:
	Complex(double real_num)
	{
		m_re = real_num;
		m_im = 0;
	}
	Complex()
	{
		m_re = 0;
		m_im = 0;
	}
	Complex(double real_num, double img_num)
	{
		m_re = real_num;
		m_im = img_num;
	}

	static Complex FromExponentialForm(double Module, double Args)
	{
		Complex fef;
		fef.m_re = Module * cos(Args);
		fef.m_im = Module * sin(Args);
		return fef;
	}
	static Complex FromAlgebraicForm(double real_num, double img_num)
	{
		Complex alg_obj(real_num, img_num);
		return alg_obj;
	}
	double Re() const
	{
		return m_re;
	}
	double Im() const
	{
		return m_im;
	}
	double Mod() const
	{
		return sqrt(m_re * m_re + m_im * m_im);
	}
	double Arg() const
	{
		return atan2(m_im, m_re);
	}

	explicit operator double() const {
		return (double)m_re;
	}
	Complex operator-()
	{
		Complex object{*this};
		object.m_im *= -1;
		object.m_re *= -1;
		return object;
	}
	Complex& operator++()
	{
		m_re++;
		return *this;
	}
	Complex operator++(int inc)
	{
		Complex object{*this};
		++*this;
		return object;
	}
	Complex& operator--()
	{
		m_re--;
		return *this;
	}
	Complex operator--(int dec)
	{
		Complex object{*this};
		--*this;
		return object;
	}
	Complex& operator+=(Complex var)
	{
		m_re += var.m_re;
		m_im += var.m_im;
		return *this;
	}
	Complex& operator-=(Complex var) {
		m_re -= var.m_re;
		m_im -= var.m_im;
		return *this;
	}
	//DKA
	Complex& operator*=(Complex var) {
		double realMI = m_re;
		double imagination = m_im;
		m_re = realMI * var.m_re - imagination * var.m_im;
		m_im = realMI * var.m_im + imagination * var.m_re;
		return *this;
	}
	Complex& operator/=(Complex var) {
		double tre1 = m_re, tim1 = m_im;
		double tre2 = var.m_re, tim2 = var.m_im;
		m_re = (tre1 * tre2 + tim1 * tim2) / (pow(tre2, 2) + pow(tim2, 2));
		m_im = (tre2 * tim1 - tre1 * tim2) / (pow(tre2, 2) + pow(tim2, 2));
		return *this;
	}
	friend Complex operator+ (const Complex& one, const Complex& two);
	friend Complex operator- (const Complex& one, const Complex& two);
	friend Complex operator* (const Complex& one, const Complex& two);
	friend Complex operator/ (const Complex& one, const Complex& two);

	friend Complex operator ""i(long double img_num);
	friend Complex operator ""i(unsigned long long img_num);

	friend std::ostream& operator<<(std::ostream& stream, const Complex& var);
};
export Complex operator+(const Complex& one, const Complex& two)
{
	return Complex(one.m_re + two.m_re, one.m_im + two.m_im);
}
export Complex operator-(const Complex& one, const Complex& two)
{
	return Complex(one.m_re - two.m_re, one.m_im - two.m_im);
}
export Complex operator*(const Complex& one, const Complex& two)
{
	return Complex((one.m_re * two.m_re - one.m_im * two.m_im),
		(one.m_re * two.m_im + one.m_im * two.m_re));
}
export Complex operator/(const Complex& one, const Complex& two)
{
	return Complex((one.m_re * two.m_re + one.m_im * two.m_im) /
		(two.m_re * two.m_re + two.m_im * two.m_im),
		(two.m_re * one.m_im - one.m_re * two.m_im) /
		(two.m_re * two.m_re + two.m_im * two.m_im));
}
export Complex operator""i(long double img_num)
{
	return Complex(0.0, static_cast<double>(img_num));
}
export Complex operator""i(unsigned long long img_num)
{
	return Complex(0.0, static_cast<double>(img_num));
}
export std::ostream& operator<<(std::ostream& stream, const Complex& var)
{
	if (var.m_im < 0)
	{
		stream << var.m_re << " " << var.m_im << "i";
	}
	else
	{
		stream << var.m_re << " + " << var.m_im << "i";
	}
	return stream;
}

export int FindGreatestCommonDivisor(int a, int b)
{
	int r;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	while (true)
	{
		if (b == 0)
			return a;
		r = a % b;
		a = b;
		b = r;
	}
}
export int FindLeastCommonMultiple(int a, int b) {
	return abs(a * b) / FindGreatestCommonDivisor(a, b);
}

export class Rational {
	int m_nominator;
	int m_denominator;
	
public:
	void normalize()
	{
		int nod = FindGreatestCommonDivisor(m_nominator, m_denominator);
		m_nominator /= nod;
		m_denominator /= nod;
		if (m_denominator < 0) {
			m_denominator *= -1;
			m_nominator *= -1;
		}
	}

	Rational()
	{
		m_nominator = 0;
		m_denominator = 1;
	}
	Rational(int _nominator, int _denominator) {
		m_denominator = _denominator;
		m_nominator = _nominator;
		normalize();
	}
	Rational(int _nominator) {
		m_nominator = _nominator;
		m_denominator = 1;
	}
	int Nominator() const {
		return m_nominator;
	}
	int Denominator() const {
		return m_denominator;
	}
	explicit operator double() const {
		return double(m_nominator) / m_denominator;
	}
	Rational operator-() {
		Rational object{*this};
		object.m_nominator *= -1;
		return object;
	}
	Rational& operator++ () {
		m_nominator += m_denominator;
		return *this;
	}
	Rational operator++ (int _param) {
		Rational object{*this};
		(*this).m_nominator += m_denominator;
		return object;
	}
	Rational& operator-- () {
		m_nominator -= m_denominator;
		return *this;
	}
	Rational operator-- (int _param) {
		Rational object{*this};
		(*this).m_nominator -= m_denominator;
		return object;
	}
	Rational& operator+=(Rational var) {
		int new_den = FindLeastCommonMultiple(m_denominator, var.m_denominator);
		m_nominator = new_den / m_denominator * m_nominator;
		m_nominator += new_den / var.m_denominator * var.m_nominator;
		m_denominator = new_den;
		normalize();
		return *this;
	}
	Rational& operator-=(Rational var) {
		int new_d = FindGreatestCommonDivisor(m_denominator, var.m_denominator);
		m_nominator = new_d / m_denominator * m_nominator;
		m_nominator -= new_d / var.m_denominator * var.m_nominator;
		m_denominator = new_d;
		normalize();
		return *this;
	}
	Rational& operator*=(Rational var) {
		m_denominator *= var.m_denominator;
		m_nominator *= var.m_nominator;
		normalize();
		return *this;
	}
	Rational& operator/=(Rational var) {
		m_denominator *= var.m_nominator;
		m_nominator *= var.m_denominator;
		normalize();
		return *this;
	}
	friend Rational operator+ (const Rational& one, const Rational& two);
	friend Rational operator- (const Rational& one, const Rational& two);
	friend Rational operator* (const Rational& one, const Rational& two);
	friend Rational operator/(const Rational& one, const Rational& two);

	friend bool operator==(const Rational& one, const Rational& two);
	friend bool operator>(const Rational& one, const Rational& two);
	friend bool operator<(const Rational& one, const Rational& two);
	friend bool operator>=(const Rational& one, const Rational& two);
	friend bool operator<=(const Rational& one, const Rational& two);

	friend std::ostream& operator<<(std::ostream& stream, const Rational& var);
};

export Rational operator+ (const Rational& one, const Rational& two) {
	int denominator = FindLeastCommonMultiple(one.m_denominator, two.m_denominator);
	int nominator = denominator / one.m_denominator * one.m_nominator;
	nominator += denominator / two.m_denominator * two.m_nominator;
	return Rational{ nominator, denominator };
}

export Rational operator-(const Rational& one, const Rational& two)
{
	int denominator = FindLeastCommonMultiple(one.m_denominator, two.m_denominator);
	int nominator = denominator / one.m_denominator * one.m_nominator;
	nominator -= denominator / two.m_denominator * two.m_nominator;
	return Rational{ nominator, denominator };
}

export Rational operator*(const Rational& one, const Rational& two)
{
	return Rational{ one.m_nominator * two.m_nominator, two.m_denominator * one.m_denominator };
}

export Rational operator/(const Rational& one, const Rational& two)
{
	return Rational{ one.m_nominator * two.m_denominator,one.m_denominator * two.m_nominator };
}

export bool operator==(const Rational& one, const Rational& two)
{
	return one.m_nominator == two.m_nominator && one.m_denominator == two.m_denominator;
}

export bool operator>(const Rational& one, const Rational& two)
{
	int den = FindLeastCommonMultiple(one.m_denominator, two.m_denominator);
	return den / one.m_denominator * one.m_nominator > den / two.m_denominator * two.m_nominator;
}
export bool operator<(const Rational& one, const Rational& two)
{
	int den = FindLeastCommonMultiple(one.m_denominator, two.m_denominator);
	return den / one.m_denominator * one.m_nominator < den / two.m_denominator * two.m_nominator;
}
export bool operator>=(const Rational& one, const Rational& two)
{
	int den = FindLeastCommonMultiple(one.m_denominator, two.m_denominator);
	return den / one.m_denominator * one.m_nominator >= den / two.m_denominator * two.m_nominator;
}
export bool operator<=(const Rational& one, const Rational& two)
{
	int den = FindLeastCommonMultiple(one.m_denominator, two.m_denominator);
	return den / one.m_denominator * one.m_nominator <= den / two.m_denominator * two.m_nominator;
}

export std::ostream& operator<<(std::ostream& stream, const Rational& var) {
	stream << var.m_nominator << "|" << var.m_denominator;
	return stream;
}

export Complex f(const Complex& z)
{
	Complex a(2, 0);
	Complex result = a * z + std::exp(5) * (1 + z);
	return result;
}

export Rational f(const Rational& r) 
{
	Rational a(2, 1);
	Rational result = a * r + std::exp(5) * (1 + r);
	return result;
}

export double f(const double& d) 
{
	double a = 2.0;
	int result = a * d + std::exp(5) * (1 + d);
	return result;
}