#ifndef ARRAY_H_20171025
#define ARRAY_H_20171025
#include <cstddef>
#include <iostream>

class Array
{
public:
    Array();
    Array(const Array& a);
    Array(const int size);
    ~Array();

    bool operator == (const Array& rhs);
    bool operator != (const Array& rhs){return !operator ==(rhs);}
    int& operator[](const ptrdiff_t i);
    const int& operator[](const ptrdiff_t i) const;
    Array& operator=(const Array& rhs);

    ptrdiff_t GetSize() const;
    void resize(const ptrdiff_t newsize);
    void insert(const ptrdiff_t i, const int data);
    void remove(const ptrdiff_t i);

    std::ostream& writeTo(std::ostream& ostrm) const;

private:
    ptrdiff_t size_{0};
    ptrdiff_t physSize_{0};
    int* pdata_{nullptr};
};

inline std::ostream& operator<<(std::ostream& ostrm, const Array& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif
