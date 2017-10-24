#include "rational.h"
#include <iostream>

int main()
{
    Rational r0;
    Rational r1(1,2);
    Rational r2(1,3);
    Rational r3(3);
    std::cout << "r0 = " << r0 << " r1= " << r1 <<" r2= " << r2 << " r3= " << r3 << std::endl;

    std::cout << r1 << "+=" << r2 << "; ";
    r1+=r2;

    std::cout << r1 << "-=" << r3 << "; ";
    r1-=r3;
    std::cout << r1 << std::endl;

    std::cout << r1 << "+=" << 3 << "; ";
    r1+=3;
    std::cout << r1 << std::endl;

    std::cout << r1 << "*=" << r2 << "; ";
    r1*=r2;
    std::cout << r1 << std::endl;

    std::cout << r1 << "/=" << 5 << "; ";
    r1/=5;
    std::cout << r1 << std::endl;

    std::cout << r1 << "*" << r2 << "=" << r1*r2 << std::endl;
    std::cout << 3 << "*" << r2 << "=" << 3*r2 << std::endl;
    std::cout << r1 << "*" << 3 << "=" << r1*3 << std::endl;

    std::cout << r1 << "+" << r2 << "=" << r1+r2 << std::endl;
    std::cout << 3 << "+" << r2 << "=" << 3+r2 << std::endl;
    std::cout << r1 << "+" << 3 << "=" << r1+3 << std::endl;

    std::cout << r1 << "/" << r2 << "=" << r1/r2 << std::endl;
    std::cout << 3 << "/" << r2 << "=" << 3/r2 << std::endl;
    std::cout << r1 << "/" << 3 << "=" << r1/3 << std::endl;

    std::cout << r1 << "-" << r2 << "=" << r1-r2 << std::endl;
    std::cout << 3 << "-" << r2 << "=" << 3-r2 << std::endl;
    std::cout << r1 << "-" << 3 << "=" << r1-3 << std::endl;
}
