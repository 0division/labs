#include "complex.h"
#include <iostream>
#include <sstream>

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    }
    else {
        cout << "Read error : " << str << " -> " << z << endl;
    }
    return istrm.good();
}


void test_operators(Complex z)
{
    using namespace std;
    cout << "z = " << z << endl;
    z += 2;
    cout << "z += 2	" << z << endl;
    z += Complex(8.0,1.0);
    cout << "z += {8,1}	" << z << endl;
    z -= 2;
    cout << "z -= 2	" << z << endl;
    z -= Complex(7.0);
    cout << "z -= {7,0}	" << z << endl;
    z *= 2;
    cout << "z *= 2	" << z << endl;
    z *= Complex(-1.0, -1.0);
    cout << "z *= {-1,-1}		" << z << endl;
    z /= 2;
    cout << "z /= 2	" << z << endl;
    z /= Complex(2, 3);
    cout << "z /= {2,3}		" << z << endl;
    cout << "z * z = " << z*z << endl;
    cout << "z / {2,1} = " << z/Complex(2,1) << endl;
    cout << "z + 1 = " << z + 1 << endl;
}

int main()
{
    using namespace std;
    Complex z = { 1,1 };
    test_operators(z);
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");

    return 0;
}
