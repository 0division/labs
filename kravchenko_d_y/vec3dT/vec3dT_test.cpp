#include "vec3dT.h"
#include <iostream>

int main()
{
    Vec3dT<int> vi1(1,3,-4);
    Vec3dT<int> vi2(vi1);;
    Vec3dT<int> vi3(5,9,17);
    std::cout << "vi1 = " << vi1 << "\tvi2 = " << vi2 << "\tvi3 = " << vi3 << std::endl;
    vi2 += vi1;
    vi1 = vi2 + vi3;
    std::cout << "vi2 += vi1;  vi1 = vi2 + vi3; "<< std::endl;
    std::cout << "vi1 = " << vi1 << "\tvi2 = " << vi2 << "\tvi3 = " << vi3 << std::endl;
    std::cout << "(vi1,vi2) = " << MultiplyScal(vi1,vi2) << std::endl;
    std::cout << "[vi1,vi2] = " << MultiplyVec(vi1,vi2) << std::endl;

    std::cout << std::endl;

    Vec3dT<double> vd1(1.11,3.33,-4.44);
    Vec3dT<double> vd2(vd1);;
    Vec3dT<double> vd3(5.55,9.99,17.77);
    std::cout << "vd1 = " << vd1 << "\tvi2 = " << vd2 << "\tvd3 = " << vd3 << std::endl;
    vd2 += vd1;
    vd1 = vd2 + vd3;
    std::cout << "vd2 += vd1;  vd1 = vd2 + vd3; "<< std::endl;
    std::cout << "vd1 = " << vd1 << "\tvd2 = " << vd2 << "\tvd3 = " << vd3 << std::endl;
    std::cout << "(vd1,vd2) = " << MultiplyScal(vd1,vd2) << std::endl;
    std::cout << "[vd1,vd2] = " << MultiplyVec(vd1,vd2) << std::endl;


}
