#ifndef ARRAY_H_20171025
#define ARRAY_H_20171025
#include <cstddef>

class Array
{
    Array():size_(0),pdata_(nullptr){}
    Array(const Array& a) = default;
    Array(const int size):size_(size)
    {
        pdata_ = new int[size];
    }

    ~Array()
    {
        delete[] pdata_;
    }

    int& operator[](const ptrdiff_t i);
    const int& operator[](const ptrdiff_t i) const;

private:
    ptrdiff_t size_{0};
    int* pdata_{nullptr};
};
#endif
