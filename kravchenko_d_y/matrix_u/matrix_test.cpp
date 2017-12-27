#include "matrix_u.h"

int main()
{
    using namespace std;
    MatrixU a(3,4);
    MatrixU b(2, 2);
    MatrixU c(2, 2);
    a.at(0,0) = -1;
    a.at(0,1) = -2;
    a.at(2,3) = 9;
    b.at(0, 0) = 1;
    b.at(0, 1) = 2;
    b.at(1, 0) = 3;
    b.at(1, 1) = 4;
    c.at(0, 0) = 5;
    c.at(0, 1) = 6;
    c.at(1, 0) = 7;
    c.at(1, 1) = 8;
    cout << a << endl << "b = \n" << b << endl << "c = \n" << c << endl;
    b = c;
    cout << "b = c = \n" << b << endl;
    b += c;
    cout << "b += c " << endl << "b = \n" << b << endl;
    //b -= a;  ----Generates exception (different size)

}
