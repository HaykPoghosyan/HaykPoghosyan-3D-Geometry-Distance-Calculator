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

const Point3D& Vector3D::GetPoint() const noexcept
{
    return m_point;
}

double Vector3D::Length() const noexcept
{
    return std::sqrt(this->LengthSquared());
}

double Vector3D::LengthSquared() const noexcept
{
    return this->Dot(*this);
}

double Vector3D::Dot(const Vector3D& other) const noexcept
{   
    return this->GetX() * other.GetX() + 
           this->GetY() * other.GetY() + 
           this->GetZ() * other.GetZ();
}

Vector3D Vector3D::Cross(const Vector3D& other) const noexcept
{
    return Vector3D(
        this->GetY() * other.GetZ() - this->GetZ() * other.GetY(),
        this->GetZ() * other.GetX() - this->GetX() * other.GetZ(),
        this->GetX() * other.GetY() - this->GetY() * other.GetX()
    );
}

Vector3D Vector3D::Normalize() const noexcept
{
    const double len = this->Length();
    
    if (len == 0) return Vector3D();
    
    const double invLen = 1.0 / len;
    return Vector3D(
        this->GetX() * invLen,
        this->GetY() * invLen,
        this->GetZ() * invLen
    );
} 