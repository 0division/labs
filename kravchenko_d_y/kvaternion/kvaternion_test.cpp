#include "kvaternion.h"

int main()
{
	Kvaternion k1(1, 2, 3, 4);
	Kvaternion k2(3, 4, -2, 5);
	k1 += k2;
    std::cout << k1 << std::endl << Determinant(k1) << std::endl;

}
