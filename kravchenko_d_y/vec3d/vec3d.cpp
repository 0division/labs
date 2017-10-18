#include "vec3d.h"
#include <iosfwd>


Vec3d::Vec3d(const double xv, const double yv, const double zv) :x(xv), y(yv), z(zv) {}  //это называется список инициализации, все поля инициализируются здесь

Vec3d::Vec3d(const Vec3d& v) :x(v.x), y(v.y), z(v.z) {}

Vec3d& Vec3d::operator = (const Vec3d& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vec3d& Vec3d::operator +=(const Vec3d& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

Vec3d& Vec3d::operator -=(const Vec3d& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

Vec3d& Vec3d::operator *=(const double rhs)
{
    x*=rhs;
    y*=rhs;
    z*=rhs;
    return *this;
}

Vec3d operator + (const Vec3d& lhs, const Vec3d& rhs)
{
    Vec3d sum(lhs);
    sum += rhs;
    return sum;
}

Vec3d operator - (const Vec3d& lhs, const Vec3d& rhs)
{
    Vec3d dif(lhs);
    dif += rhs;
    return dif;
}

Vec3d operator * (const Vec3d& lhs, const double rhs)
{
    Vec3d prod(lhs);
    prod *= rhs;
    return prod;
}

Vec3d operator * (const double lhs, const Vec3d& rhs)
{
    Vec3d prod(rhs);
    prod *= lhs;
    return prod;
}

double MultiplyScal(const Vec3d& a, const Vec3d& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vec3d MultiplyVec(const Vec3d& a, const Vec3d& b)
{
    return Vec3d(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

std::ostream& Vec3d::writeTo(std::ostream& ostrm) const
{
    ostrm << '(' << x << " , " << y << " , " << z << ")";
    return ostrm;
}
