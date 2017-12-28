#include "priorityqueuel.h"

int main()
{
    using namespace std;

    PriorityQueueL a;
    a.pushPr(11);
    a.pushPr(22);
    a.pushPr(33);
    cout << "a:"<< a << endl;
    PriorityQueueL b(a);
    cout << "b(x):" << b << endl;
    PriorityQueueL c;
    cout << "c:" << c << endl;
    a.pop();
    cout << "a:" << a << endl;
    cout << "top: " << a.top() << endl;

    c.pushPr(5);
    c.pushPr(4);
    c.pushPr(2);
    cout << "c:" << c << endl;
    c.pushPr(3);
    cout << "c:" << c << endl;
    c.pushPr(8);
    cout << "c:" << c << endl;
    c.pushPr(15);
    cout << "c:" << c << endl;
    c.pushPr(15);
    cout << "c:" << c << endl;
    c.pushPr(0);
    cout << "c:" << c << endl;
    c.pushPr(7);
    cout << "c:" << c << endl;
    cout << endl;

    PriorityQueueL d;
    d.pushPr(1);
    d.pushPr(3);
    d.pushPr(2);
    cout << "d:" << d << endl;
    d = c;
    cout << "d=c:" << d << endl;
}