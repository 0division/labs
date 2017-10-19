#ifndef VEC3D
#define VEC3D
#include <cmath>
#include <iostream>


struct Vec3d
{
public:
    Vec3d() = default;
    Vec3d(const double xv, const double yv, const double zv);
    Vec3d(const Vec3d& v); //конструктор копирования

    ~Vec3d() = default;

    Vec3d& operator = (const Vec3d& v); //можно использовать дефолтный оператор присваивания

    bool operator == (const Vec3d rhs) { return ((std::abs(x-rhs.x)<0.0000001) && (std::abs(y-rhs.y)<0.0000001) && (std::abs(z-rhs.z)<0.0000001)); }
    bool operator != (const Vec3d rhs) { return !operator==(rhs); }
    Vec3d& operator +=(const Vec3d& rhs);
    Vec3d& operator -=(const Vec3d& rhs);
    Vec3d& operator *=(const double rhs);

    double x{ 0.0 };
    double y{ 0.0 };
    double z{ 0.0 };

    std::ostream& writeTo(std::ostream& ostrm) const;
};

Vec3d operator + (const Vec3d& lhs, const Vec3d& rhs);
Vec3d operator - (const Vec3d& lhs, const Vec3d& rhs);
Vec3d operator * (const Vec3d& lhs, const double rhs);
Vec3d operator * (const double lhs, const Vec3d& rhs);

double MultiplyScal(const Vec3d& a, const Vec3d& b);
Vec3d MultiplyVec(const Vec3d& a, const Vec3d& b);

inline std::ostream& operator<<(std::ostream& ostrm, const Vec3d& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif

