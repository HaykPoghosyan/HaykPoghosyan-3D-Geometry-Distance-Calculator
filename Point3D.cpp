#include "Point3D.h"

Point3D::Point3D(const double x, const double y, const double z) noexcept
    : m_x(x), m_y(y), m_z(z)
{
}

double Point3D::GetX() const noexcept
{
    return m_x;
}

double Point3D::GetY() const noexcept
{
    return m_y;
}

double Point3D::GetZ() const noexcept
{
    return m_z;
} 