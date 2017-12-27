#include "array.h"
#include <stdexcept>

Array::Array():pdata_(nullptr), size_(0), physSize_(0){}

Array::Array(const Array &a):size_(a.size_)
{
    pdata_ = new int[size_];
    for (int i = 0; i < size_; i+=1)
    {
        pdata_[i] = a.pdata_[i];
    }
    physSize_ = size_;
}

Array::Array(const int size):size_(size)
{
    if(size<0){ throw std::invalid_argument("Error: Size cannot be negative"); }
    pdata_ = new int[size];
    physSize_ = size_;
}

Array::~Array()
{
    delete[] pdata_;
}

int& Array::operator[](const ptrdiff_t i)
{
    if(i<0 || i>=size_) { throw std::invalid_argument("Error: Out of range exception"); }
    return pdata_[i];
}

const int& Array::operator[](const ptrdiff_t i) const
{
    if(i<0 || i>=size_) {throw std::invalid_argument("Error: Out of range exception");}
    return pdata_[i];
}

bool Array::operator == (const Array& rhs)
{
    bool isEqual{false};
    if(size_!=rhs.size_)
    {
        isEqual = false;
    }else{
        for(int i = 0; i<size_; i+=1){
            if (pdata_[i]!= rhs.pdata_[i]){
                isEqual = false;
                break;
            }else{
                isEqual = true;
            }
        }
    }
    return isEqual;
}

Array& Array::operator = (const Array& rhs)
{
    size_ = rhs.size_;
    pdata_ = new int[size_];
    for(int i = 0; i<rhs.size_; i+=1)
    {
        pdata_[i] = rhs.pdata_[i];
    }
    physSize_ = size_;
    return *this;
}

ptrdiff_t Array::GetSize() const
{
    return size_;
}

void Array::resize(const ptrdiff_t newsize)
{
    if(newsize<0){ throw std::invalid_argument("Error: size cannot be negative"); }
    if(newsize < size_)
    {
        size_ = newsize;
    }else if(newsize <= physSize_)
    {
        for(ptrdiff_t i = size_; i<newsize; i+=1)
        {
            pdata_[i] = 0;
        }
        size_ = newsize;
    }
    else{
        int* newdata = new int[newsize];
        for(int i = 0; i<newsize; i+=1)
        {
            newdata[i] = pdata_[i];
        }
        delete[] pdata_;
        pdata_ = newdata;
        size_ = newsize;
        physSize_ = newsize;
    }

}


void Array::remove(const ptrdiff_t i)
{
    if(i<0 || i>=size_) {throw std::invalid_argument("Error: Out of range exception");}
    for(ptrdiff_t j = i; j<size_-1; j+=1)
    {
        pdata_[j] = pdata_[j+1];
    }
    size_-=1;
}

void Array::insert(const ptrdiff_t i, const int data)
{
    if(i<0 || i>=size_) {throw std::invalid_argument("Error: Out of range exception");}
    if(size_ == physSize_)
    {
        resize(size_+1);
    }
    for(ptrdiff_t j = i; j< size_; j+=1)
    {
        pdata_[j] = pdata_[j+1];
    }
    pdata_[i] = data;
}


std::ostream& Array::writeTo(std::ostream& ostrm) const
{
    ostrm << '{';
    for (ptrdiff_t i = 0; i < size_; i += 1)
    {
        ostrm << pdata_[i] << ' ';
    }
    ostrm << '}';
    return ostrm;
}
