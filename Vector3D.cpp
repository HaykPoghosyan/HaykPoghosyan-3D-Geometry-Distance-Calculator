#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(const double x, const double y, const double z) noexcept
    : m_point(x, y, z)
{
}

Vector3D::Vector3D(const Point3D& point) noexcept
    : m_point(point)
{
}

Vector3D::Vector3D(const Point3D& start, const Point3D& end) noexcept
    : m_point(end - start)
{
}

double Vector3D::GetX() const noexcept
{
    return m_point.GetX();
}

double Vector3D::GetY() const noexcept
{
    return m_point.GetY();
}

double Vector3D::GetZ() const noexcept
{
    return m_point.GetZ();
}

double Vector3D::Length() const noexcept
{
    const double x = m_point.GetX();
    const double y = m_point.GetY();
    const double z = m_point.GetZ();
    return std::sqrt(x * x + y * y + z * z);
}

double Vector3D::Dot(const Vector3D& other) const noexcept
{
    return m_point.GetX() * other.GetX() + 
           m_point.GetY() * other.GetY() + 
           m_point.GetZ() * other.GetZ();
}

Vector3D Vector3D::Cross(const Vector3D& other) const noexcept
{
    return Vector3D(
        m_point.GetY() * other.GetZ() - m_point.GetZ() * other.GetY(),
        m_point.GetZ() * other.GetX() - m_point.GetX() * other.GetZ(),
        m_point.GetX() * other.GetY() - m_point.GetY() * other.GetX()
    );
}

Vector3D Vector3D::Normalize() const noexcept
{
    const double len = Length();
    if (len == 0) return Vector3D();
    
    const double invLen = 1.0 / len;
    return Vector3D(m_point * invLen);
} 