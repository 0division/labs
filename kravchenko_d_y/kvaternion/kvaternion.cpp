#include "kvaternion.h"

std::ostream& Kvaternion::writeTo(std::ostream& ostrm) const
{
	ostrm << a1 << " " << a2 << "\n" << b1 << " " << b2;
	return ostrm;
}

Kvaternion& Kvaternion::operator =(const Kvaternion& rhs)
{
    a1 = rhs.a1;
    a2 = rhs.a2;
    b1 = rhs.b1;
    b2 = rhs.b2;
    return *this;
}

Kvaternion& Kvaternion::operator +=(const Kvaternion& rhs) 
{
	a1 += rhs.a1;
	a2 += rhs.a2;
	b1 += rhs.b1;
	b2 += rhs.b2;
	return *this;
}

Kvaternion& Kvaternion::operator -=(const Kvaternion& rhs)
{
	a1 -= rhs.a1;
	a2 -= rhs.a2;
	b1 -= rhs.b1;
	b2 -= rhs.b2;
	return *this;
}

Kvaternion operator+(const Kvaternion& lhs, const Kvaternion& rhs)
{
	Kvaternion sum = lhs;
	sum += rhs;
	return sum;
}

Kvaternion operator-(const Kvaternion& lhs, const Kvaternion& rhs)
{
	Kvaternion sum = lhs;
	sum -= rhs;
	return sum;
}

Kvaternion& Kvaternion::operator *=(const int rhs)
{
    a1 *= rhs;
    a2 *= rhs;
    b1 *= rhs;
    b2 *= rhs;
    return *this;
}

Kvaternion operator * (const int lhs, const Kvaternion& rhs)
{
    Kvaternion prod = rhs;
    prod*=lhs;
    return prod;
}

Kvaternion operator * (const Kvaternion& lhs, const int rhs)
{
    Kvaternion prod = lhs;
    prod*=rhs;
    return prod;
}

void Kvaternion::Transpose()
{
    int temp = a2;
    a2 = b1;
    b1 = temp;
}

int Determinant(const Kvaternion& k) 
{
	return k.a1*k.b2 - k.a2*k.b1;
}
