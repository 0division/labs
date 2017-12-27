#ifndef MATRIX_U_H_20171102
#define MATRIX_U_H_20171102

#include <cstddef>
#include <iostream>

class MatrixU
{
public:
    MatrixU() = default;
    MatrixU(const ptrdiff_t row, const ptrdiff_t col);
    MatrixU(const MatrixU& a);
    ~MatrixU();

    int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;

    bool operator==(const MatrixU& rhs) const;
    bool operator!=(const MatrixU& rhs) const{ return !operator==(rhs);}
    MatrixU& operator=(const MatrixU& rhs);
    MatrixU& operator+=(const MatrixU& rhs);
    MatrixU& operator-=(const MatrixU& rhs);

    std::ostream& writeTo(std::ostream& ostrm);
private:
    ptrdiff_t nRow_{0};
    ptrdiff_t nCol_{0};
    int* pdata_{ nullptr };
};

inline std::ostream& operator << (std::ostream& ostrm, MatrixU& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif
