#include "priorityqueuel.h"
#include <iostream>
#include <stdexcept>


PriorityQueueL::PriorityQueueL(const PriorityQueueL& rhs)
{
    if (!rhs.isEmpty())
    {
        Node* t = rhs.pHead_;
        while (t != nullptr)
        {
            push(t->pData_);
            t = t->pNext_;
        }
    }
}

bool PriorityQueueL::isEmpty() const
{
    return pHead_ == nullptr;
}

void PriorityQueueL::push(const int& value)
{
    if (isEmpty())
    {
        pTail_ = new Node(nullptr, value);
        pHead_= pTail_;
    }

    else
    {
        pTail_->pNext_ = new Node(nullptr, value);
        pTail_ = pTail_->pNext_;
    }
}


void PriorityQueueL::pushPr(const int& value)
{
    if ((isEmpty())||(value > pHead_->pData_))
    {
        pHead_ = new Node(pHead_, value);
        if (pTail_ == nullptr)
        {
            pTail_ = pHead_;
        }
        return;
    }

    if (value <pTail_->pData_)
    {
        pTail_->pNext_ = new Node(nullptr, value);
        pTail_ = pTail_->pNext_;
        return;
    }
    Node* t = pHead_;
    while ((t->pNext_)->pData_ > value)
    {
        t = t->pNext_;
    }
    t->pNext_ = new Node(t->pNext_, value);


}

void PriorityQueueL::pop()
{
    if (isEmpty())
    {
        throw std::invalid_argument("Error: Stack is Empty");
    }
    else
    {
        Node* pDel(pHead_);
        pHead_ = pHead_->pNext_;
        delete pDel;
    }
}

int& PriorityQueueL::top()
{
    if (isEmpty())
    {
        throw std:: invalid_argument("Error: Stack is Empty");
    }
    return pHead_->pData_;
}

const int& PriorityQueueL::top() const
{
    if (isEmpty())
    {
        throw std::invalid_argument("Error: Stack is Empty");
    }
    return pHead_->pData_;
}

std::ostream& PriorityQueueL::writeTo(std::ostream& ostrm) const
{
    if (!isEmpty())
    {
        Node* t = pHead_;
        while (t != nullptr)
        {
            ostrm << t->pData_ << ' ';
            t = t->pNext_;
        }
    }
    return ostrm;
}


PriorityQueueL::~PriorityQueueL()
{
    while (!isEmpty())
    {
        pop();
    }
}

PriorityQueueL& PriorityQueueL::operator=(const PriorityQueueL& rhs)
{
    Node* pCopyTo = pHead_;
    Node* pCopyFrom = rhs.pHead_;
    if ((pCopyTo != nullptr) && (pCopyFrom != nullptr)) {
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
    }
    else {
        if ((pCopyTo == nullptr) && (pCopyFrom != nullptr)) {
            pHead_ = new Node(pCopyTo, pCopyFrom->pData_);
            pCopyTo = pHead_;
            pCopyFrom = pCopyFrom->pNext_;
            while (pCopyFrom != nullptr)
            {
                pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->pData_);
                pCopyTo = pCopyTo->pNext_;
                pCopyFrom = pCopyFrom->pNext_;
            }
        }
        else {
            if ((pCopyTo != nullptr) && (pCopyFrom == nullptr)) {
                while (!isEmpty())
                {
                    pop();
                }
            }
        }
    }

    return *this;

}