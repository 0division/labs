#include "stackl.h"
#include <stdexcept>

StackL::StackL(const StackL &obj)
{
    if (!obj.isEmpty()) {
        Node* pCopyFrom(obj.pHead_->pNext_);
        Node* pCopyTo = new Node(nullptr, obj.pHead_->pData_);
        pHead_ = pCopyTo;
        while (pCopyFrom != nullptr)
        {
            pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->pData_);
            pCopyTo = pCopyTo->pNext_;
            pCopyFrom = pCopyFrom->pNext_;
        }
    }
}

bool StackL::isEmpty() const
{
    return (pHead_ == nullptr);
}

void StackL::push(const int& value)
{
    pHead_ = new Node(pHead_, value);
}

void StackL::pop()
{
    if (!isEmpty()) {
        Node* pDelete(pHead_);
        pHead_ = pDelete->pNext_;
        delete pDelete;
    }
}

int& StackL::top()
{
    if (isEmpty()) {
        throw std::invalid_argument("Error: Stack is Empty");
    }
    return pHead_->pData_;
}

const int& StackL::top() const
{
    if (isEmpty()) {
        throw std::invalid_argument("Error: Stack is Empty");
    }
    return pHead_->pData_;
}

std::ostream& StackL::writeTo(std::ostream &ostrm) const
{
    Node* p = pHead_;
    while (p != NULL)
    {
        ostrm << p->pData_ << ' ';
        p = p->pNext_;
    }
    return ostrm;
}

StackL& StackL::operator=(const StackL& rhs)
{
    Node* pCopyTo = pHead_;
    Node* pCopyFrom = rhs.pHead_;

    while ((pCopyTo->pNext_ != nullptr) && (pCopyFrom->pNext_ != nullptr))
    {
        pCopyTo->pData_ = pCopyFrom->pData_;
        pCopyTo = pCopyTo->pNext_;
        pCopyFrom = pCopyFrom->pNext_;
    }

    if ((pCopyTo->pNext_ == nullptr) && (pCopyFrom->pNext_ != nullptr))
    {
        pCopyTo->pData_ = pCopyFrom->pData_;
        pCopyFrom = pCopyFrom->pNext_;

        while (pCopyFrom != nullptr)

        {
            pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->pData_);
            pCopyTo = pCopyTo->pNext_;
            pCopyFrom = pCopyFrom->pNext_;
        }
    }

    else
    {
        if ((pCopyFrom->pNext_ == nullptr) && (pCopyTo->pNext_ != nullptr))
        {
            pCopyTo->pData_ = pCopyFrom->pData_;
            Node* pContinue(pCopyTo->pNext_);
            pCopyTo->pNext_ = nullptr;
            Node* pDelete;

            while (pContinue != nullptr)
            {
                pDelete = pContinue;
                pContinue = pDelete->pNext_;
                delete pDelete;
            }
        }
    }
    return *this;
}


