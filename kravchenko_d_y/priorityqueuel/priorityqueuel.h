#ifndef PRIORITY_QUEUE_L_H
#define PRIORITY_QUEUE_L_H

#include <iostream>

class PriorityQueueL
{
public:
    PriorityQueueL() = default;
    ~PriorityQueueL();
    PriorityQueueL(const PriorityQueueL& rhs);
    PriorityQueueL& operator=(const PriorityQueueL& rhs);
    void push(const int& x);
    void pop();
    void pushPr(const int& x);
    int& top();
    const int& top() const;
    bool isEmpty() const;
    std:: ostream& writeTo(std::ostream& ostrm) const;

private:
    struct Node
    {
        Node(Node* pNext, const int& value): pNext_(pNext), pData_(value){}
        ~Node() = default;
        Node* pNext_{ nullptr };
        int pData_{ int(0) };
    };
    Node* pHead_{ nullptr };
    Node* pTail_{ nullptr };

};

inline std::ostream& operator<<(std::ostream& ostrm, const PriorityQueueL& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif