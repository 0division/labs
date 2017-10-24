#ifndef KVATERNION_19_10_17
#define KVATERNION_19_10_17
#include <iostream>

struct Kvaternion
{
	Kvaternion() = default;
	Kvaternion(const int n1, const int n2, const int m1, const int m2): a1(n1), a2(n2), b1(m1), b2(m2) {}
	Kvaternion(const Kvaternion& k) = default;
	~Kvaternion() = default;

	bool operator ==(const Kvaternion& rhs) const { return a1 == rhs.a1 && a2 == rhs.a2 && b1 == rhs.b1 && b2 == rhs.b2; }
	bool operator !=(const Kvaternion& rhs) const { return !operator==(rhs); }

	Kvaternion& operator +=(const Kvaternion& rhs);
	Kvaternion& operator -=(const Kvaternion& rhs);

	std::ostream& writeTo(std::ostream& ostrm) const;

	int a1{ 0 };
	int a2{ 0 };
	int b1{ 0 };
	int b2{ 0 };
};

inline std::ostream& operator <<(std::ostream& ostrm, const Kvaternion& rhs) 
{
	return rhs.writeTo(ostrm);
}

Kvaternion operator+(const Kvaternion& lhs, const Kvaternion& rhs);
Kvaternion operator-(const Kvaternion& lhs, const Kvaternion& rhs);

int Determinant(const Kvaternion& k);

#endif // !KVATERNION_19.10.17

