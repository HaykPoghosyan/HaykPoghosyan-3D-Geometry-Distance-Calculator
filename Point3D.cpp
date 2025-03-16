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

Point3D Point3D::operator+(const Point3D& other) const noexcept
{
    return Point3D(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
}

Point3D Point3D::operator-(const Point3D& other) const noexcept
{
    return Point3D(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
}

Point3D Point3D::operator*(double scalar) const noexcept
{
    return Point3D(m_x * scalar, m_y * scalar, m_z * scalar);
}

// Non-member operator for scalar * Point3D
Point3D operator*(double scalar, const Point3D& point) noexcept
{
    return point * scalar; // Reuse the member operator
} 