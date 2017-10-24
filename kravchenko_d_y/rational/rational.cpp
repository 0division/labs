#include "rational.h"
#include <cmath>

Rational::Rational(const int numerator) : Rational(numerator, 1) {}

Rational::Rational(const int numerator, const int denumerator) : num(numerator), denum(denumerator) {}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << num << "/" << denum;
    return ostrm;
}

int Rational::NOD(const int a, const int b)
{
      if (b == 0)
        return a;

      return NOD(b, a % b);
}

Rational& Rational::operator +=(const Rational& rhs)
{
    if(denum==rhs.denum)
    {
        num+=rhs.num;
    }else{
        num*=rhs.denum;
        num+=rhs.num*denum;
        denum*=rhs.denum;
    }
    int nod = NOD(num,denum);
    num/=nod;
    denum/=nod;
    return *this;
}

Rational& Rational::operator -=(const Rational& rhs)
{
    if(denum==rhs.denum)
    {
        num-=rhs.num;
    }else{
        num*=rhs.denum;
        num-=rhs.num*denum;
        denum*=rhs.denum;
    }
    int nod = NOD(num,denum);
    nod = std::abs(nod);
    num/=nod;
    denum/=nod;
    return *this;
}

Rational& Rational::operator *=(const int rhs)
{
    num*=rhs;
    int nod = NOD(num,denum);
    nod = std::abs(nod);
    num/=nod;
    denum/=nod;
    return *this;
}

Rational& Rational::operator *=(const Rational& rhs)
{
    num*=rhs.num;
    denum*=rhs.denum;
    int nod = NOD(num,denum);
    nod = std::abs(nod);
    num/=nod;
    denum/=nod;
    return *this;
}

Rational& Rational::operator /=(const int rhs)
{
    denum*=rhs;
    int nod = NOD(num,denum);
    nod = std::abs(nod);
    num/=nod;
    denum/=nod;
    return *this;
}

Rational& Rational::operator /=(const Rational& rhs)
{
    num*=rhs.denum;
    denum*=rhs.num;
    int nod = NOD(num,denum);
    nod = std::abs(nod);
    num/=nod;
    denum/=nod;
    return *this;
}

Rational operator *(const Rational& lhs, const Rational& rhs)
{
    Rational prod = lhs;
    prod *= rhs;
    return prod;
}

Rational operator *(const int lhs, const Rational& rhs){ return Rational(lhs)*rhs;}
Rational operator *(const Rational& lhs, const int rhs){ return lhs*Rational(rhs);}

Rational operator +(const Rational& lhs, const Rational& rhs)
{
    Rational sum = lhs;
    sum += rhs;
    return sum;
}

Rational operator +(const int lhs, const Rational& rhs){ return Rational(lhs)+rhs;}
Rational operator +(const Rational& lhs, const int rhs){ return lhs+Rational(rhs);}

Rational operator /(const Rational& lhs, const Rational& rhs)
{
    Rational quot = lhs;
    quot *= rhs;
    return quot;
}

Rational operator /(const int lhs, const Rational& rhs){ return Rational(lhs)/rhs;}
Rational operator /(const Rational& lhs, const int rhs){ return lhs/Rational(rhs);}

Rational operator -(const Rational& lhs, const Rational& rhs)
{
    Rational dif = lhs;
    dif *= rhs;
    return dif;
}

Rational operator -(const int lhs, const Rational& rhs){ return Rational(lhs)-rhs;}
Rational operator -(const Rational& lhs, const int rhs){ return lhs-Rational(rhs);}

