#ifndef KRAVCHENKO_D_Y_STACK_L_H
#define KRAVCHENKO_D_Y_STACK_L_H

#include <iostream>

class StackL {
public:
    StackL() = default;
    StackL(const StackL& obj);
    ~StackL()
    {
        while(!isEmpty())
        {
            pop();
        }
    }
    StackL& operator=(const StackL& rhs);
    bool isEmpty() const;
    void push(const int& v);
    void pop();
    int& top();
    const int& top() const;
    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    struct Node
    {
        Node(Node* pNext, const int& value): pNext_(pNext), pData_(value){}
        ~Node() = default;
        Node* pNext_{ nullptr };
        int pData_{ int(0) };
    };
    Node* pHead_{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const StackL& rhs)
{
    return  rhs.writeTo(ostrm);
}
#endif //KRAVCHENKO_D_Y_STACK_L_H
