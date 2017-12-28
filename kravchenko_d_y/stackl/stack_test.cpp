#include "stackl.h"

int main()
{
    using namespace std;
    StackL s;
    cout << s << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s << endl;
    s.top() = 8;
    cout << s << endl;
    StackL s1;
    s1.push(33);
    s1.push(88);
    s = s1;
    cout << s << endl;
}