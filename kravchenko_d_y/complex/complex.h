#ifndef COMPLEX_H_20170921
#define COMPLEX_H_20170921  

#include <iosfwd> //предварительные объявления для того что связано с потоками
#include <cmath>

struct Complex {
    Complex() = default;
    Complex(const double real);
	Complex(const double real, const double imaginary);
    Complex(const Complex& v) = default;
    ~Complex() = default;
    bool operator==(const Complex& rhs) const { return (std::abs(re-rhs.re)<0.0000001) && (std::abs(im-rhs.im)<0.0000001); }
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator*=(const double rhs); 
	Complex& operator*=(const Complex& rhs);
	Complex& operator/=(const double rhs);
	Complex& operator/=(const Complex& rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

#endif 


