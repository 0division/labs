#include "complex.h"
#include <iostream>
#include <sstream>


Complex::Complex(const double real)
    : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{
}

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator+(const Complex& lhs, const double rhs)
{
    Complex sum(rhs);
    sum += lhs;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}


Complex operator-(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re - rhs, lhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    Complex prod(lhs);
    prod *= rhs;
    return prod;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
    Complex quot(lhs);
    quot /= rhs;
    return quot;
}

Complex& Complex::operator*=(const double rhs)
{
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
    double temp_re = re*rhs.re - im*rhs.im;
    im = re*rhs.im + rhs.re*im;
    re = temp_re;
    return *this;
}

Complex& Complex::operator/=(const double rhs)
{
    re /= rhs;
    im /= rhs;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
    double temp_re = (re*rhs.re + im*rhs.im)/(rhs.re*rhs.re + rhs.im*rhs.im);
    im = (im*rhs.re-re*rhs.im)/(rhs.re*rhs.re + rhs.im*rhs.im);
    re = temp_re;
    return *this;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaganary;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
        return istrm;
}
