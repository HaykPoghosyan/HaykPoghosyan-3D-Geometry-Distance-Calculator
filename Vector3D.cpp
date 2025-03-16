#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(const double x, const double y, const double z) noexcept
    : m_x(x), m_y(y), m_z(z)
{
}

Vector3D::Vector3D(const Point3D& start, const Point3D& end) noexcept
    : m_x(end.GetX() - start.GetX()),
      m_y(end.GetY() - start.GetY()),
      m_z(end.GetZ() - start.GetZ())
{
}

double Vector3D::GetX() const noexcept
{
    return m_x;
}

double Vector3D::GetY() const noexcept
{
    return m_y;
}

double Vector3D::GetZ() const noexcept
{
    return m_z;
}

double Vector3D::Length() const noexcept
{
    return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

double Vector3D::Dot(const Vector3D& other) const noexcept
{
    return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

Vector3D Vector3D::Cross(const Vector3D& other) const noexcept
{
    return Vector3D(
        m_y * other.m_z - m_z * other.m_y,
        m_z * other.m_x - m_x * other.m_z,
        m_x * other.m_y - m_y * other.m_x
    );
}

Vector3D Vector3D::Normalize() const noexcept
{
    const double len = Length();
    if (len == 0) return Vector3D();
    
    const double invLen = 1.0 / len;
    return Vector3D(m_x * invLen, m_y * invLen, m_z * invLen);
} 