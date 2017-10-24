#include "kvaternion.h"

std::ostream& Kvaternion::writeTo(std::ostream& ostrm) const
{
	ostrm << a1 << " " << a2 << "\n" << b1 << " " << b2;
	return ostrm;
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

Kvaternion operator+(const Kvaternion& lhs, const Kvaternion rhs) 
{
	Kvaternion sum = lhs;
	sum += rhs;
	return sum;
}

Kvaternion operator-(const Kvaternion& lhs, const Kvaternion rhs)
{
	Kvaternion sum = lhs;
	sum -= rhs;
	return sum;
}

int Determinant(const Kvaternion& k) 
{
	return k.a1*k.b2 - k.a2*k.b1;
}