#ifndef RATIONAL_H_20170921
#define RATIONAL_H_20170921
#include <iostream>

class Rational 
{
public:
    Rational() = default;
    Rational(const int numerator);
    Rational(const int numerator, const int denumerator);
    ~Rational() = default;
    std::ostream& writeTo(std::ostream& ostrm) const;
	bool operator==(const Rational& rhs) const { return (num == rhs.num) && (denum == rhs.denum); }
    bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }
    Rational& operator-=(const Rational& rhs);
    Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }
    Rational& operator*=(const int rhs);
	Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const int rhs);
	Rational& operator/=(const Rational& rhs);

private:
	int num{ 0 };
	int denum{ 1 };
    int NOD(const int numerator, const int denumerator);

};

Rational operator *(const Rational& lhs, const Rational& rhs);
Rational operator *(const int lhs, const Rational& rhs);
Rational operator *(const Rational& lhs, const int rhs);
Rational operator /(const Rational& lhs, const Rational& rhs);
Rational operator /(const int lhs, const Rational& rhs);
Rational operator /(const Rational& lhs, const int rhs);
Rational operator +(const Rational& lhs, const Rational& rhs);
Rational operator +(const int lhs, const Rational& rhs);
Rational operator +(const Rational& lhs, const int rhs);
Rational operator -(const Rational& lhs, const Rational& rhs);
Rational operator -(const int lhs, const Rational& rhs);
Rational operator -(const Rational& lhs, const int rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif
