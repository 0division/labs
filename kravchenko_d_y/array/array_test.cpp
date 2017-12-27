#include "array.h"
#include <iostream>

int main()
{
    using namespace std;
    Array a(2);
    a[0] = 1;
    a[1] = 2;
    cout << "Array a: " << a << endl;
    Array b(a);                                         //test copy constructor
    cout << "Array b: " << b << endl;

    a.resize(3);
    b.resize(0);
    cout << "Array a: " << a << " size: " << a.GetSize() << endl;
    cout << "Array b: " << b << " size: " << b.GetSize() << endl;

    a.insert(2,42);
    cout << "Array a: " << a << " size: " << a.GetSize() << endl;

    a.remove(1);
    cout << "Array a: " << a << " size: " << a.GetSize() << endl;

    b = a;
    cout << "Array b: " << b << " size: " << b.GetSize() << endl;

    b[0] = 99;
    cout << "Array b: " << b << " size: " << b.GetSize() << endl;
    cout << b[0] << endl;
}
