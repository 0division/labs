#ifndef VEC3DT
#define VEC3DT
#include <iostream>

template<typename T>
struct Vec3dT
{
    public:
    Vec3dT();
    Vec3dT(const T xv, const T yv, const T zv): x(xv), y(yv), z(zv){}
    Vec3dT(const Vec3dT& v) = default;
    ~Vec3dT() = default;

    Vec3dT& operator +=(const Vec3dT& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    Vec3dT& operator -=(const Vec3dT& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    T x{T()};
    T y{T()};
    T z{T()};

    std::ostream& writeTo(std::ostream& ostrm) const
    {
        ostrm << '(' << x << " , " << y << " , " << z << ")";
        return ostrm;
    }
};

template<typename T>
inline std::ostream& operator<<(std::ostream& ostrm, const Vec3dT<T>& rhs)
{
    return rhs.writeTo(ostrm);
}

template<typename T>
Vec3dT<T> operator + (const Vec3dT<T>& lhs, const Vec3dT<T>& rhs)
{
    return Vec3dT<T>(lhs.x+rhs.x,lhs.y+rhs.y,lhs.z+rhs.z);
}

template<typename T>
Vec3dT<T> operator - (const Vec3dT<T>& lhs, const Vec3dT<T>& rhs)
{
    return Vec3dT<T>(lhs.x-rhs.x,lhs.y-rhs.y,lhs.z-rhs.z);
}

template<typename T>
T MultiplyScal(const Vec3dT<T>& a, const Vec3dT<T>& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

template<typename T>
Vec3dT<T> MultiplyVec(const Vec3dT<T>& a, const Vec3dT<T>& b)
{
    return Vec3dT<T>(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

#endif

