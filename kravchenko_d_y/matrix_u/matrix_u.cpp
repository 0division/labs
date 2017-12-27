#include "matrix_u.h"
#include <stdexcept>

MatrixU::MatrixU(const ptrdiff_t row, const ptrdiff_t col): nRow_(row), nCol_(col)
{
    if (nRow_ > 0 && nCol_ > 0)
    {
        pdata_ = new int[nRow_* nCol_];
    }else{
        throw std::invalid_argument("Error: The number of rows or columns can't be negative");
    }
}

MatrixU::MatrixU(const MatrixU& a): nRow_(a.nRow_), nCol_(a.nCol_)
{
    pdata_ = new int[nRow_*nCol_];
    for (ptrdiff_t i(0); i < nRow_ * nCol_; i += 1) {
        pdata_[i] = a.pdata_[i];
    }
}

MatrixU::~MatrixU()
{
    delete[] pdata_;
}

int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if(iRow < 0 || iCol < 0){
        throw std::invalid_argument("Error: Out of range");
    }else {
        return pdata_[nCol_ * iRow + iCol];
    }
}

const int &MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if(iRow < 0 || iCol < 0){
        throw std::invalid_argument("Error: Out of range");
    }else {
        return pdata_[nCol_ * iRow + iCol];
    }
}

MatrixU& MatrixU::operator=(const MatrixU& rhs)
{
    for (ptrdiff_t i(0); i < nRow_ * nCol_; i += 1) {
        pdata_[i] = rhs.pdata_[i];
    }
    return *this;
}

MatrixU& MatrixU::operator+=(const MatrixU& rhs)
{
    if (nRow_ == rhs.nRow_ && nCol_ == rhs.nCol_)
    {

        for (ptrdiff_t i(0); i < nRow_ * nCol_; i += 1)
        {
            pdata_[i] += rhs.pdata_[i];
        }
        return *this;
    } else {
        throw std::invalid_argument("Error: Matrices must be of equal size");
    }
}

MatrixU& MatrixU::operator-=(const MatrixU& rhs)
{
    if (nRow_ == rhs.nRow_ && nCol_ == rhs.nCol_)
    {

        for (ptrdiff_t i(0); i < nRow_ * nCol_; i += 1)
        {
            pdata_[i] -= rhs.pdata_[i];
        }
        return *this;
    } else {
        throw std::invalid_argument("Error: Matrices must be of equal size");
    }
}

bool MatrixU::operator==(const MatrixU &rhs) const {
    bool isEqual = false;
    if (nRow_ == rhs.nRow_ && nCol_ == rhs.nCol_)
    {
        for (ptrdiff_t i(0); i < nRow_ * nCol_; i += 1)
        {
            if(pdata_[i] != rhs.pdata_[i])
            {
                isEqual = false;
                break;
            }else{
                isEqual = true;
            }
        }
    }
    return isEqual;
}

std::ostream& MatrixU::writeTo(std::ostream& ostrm) {
    for (ptrdiff_t i = 0; i < nRow_ * nCol_; i++) {
        ostrm << pdata_[i] << ' ';
        if((i+1)%nCol_==0) ostrm << std::endl;
    }
    return ostrm;
}