#include "kvaternion.h"

int main()
{
	Kvaternion k1(1, 2, 3, 4);
	Kvaternion k2(3, 4, -2, 5);
    std::cout << k1 << std::endl << k2 << "\ndeterminant k1 = " << Determinant(k1) << std::endl;
    std::cout << k1 + k2 << std::endl;
    std::cout << k1 - k2 << std::endl;
    std::cout << k1*2 << std::endl;
    k1 = k2;
    if(k1==k2) std::cout << "k1==k2" << std::endl;
    std::cout << k1 << "\ntranspose k1" << std::endl;
    k1.Transpose();
    std::cout << k1 << std::endl;
}
